/*-
 * Copyright (c) 2006 Verdens Gang AS
 * Copyright (c) 2006-2015 Varnish Software AS
 * All rights reserved.
 *
 * Author: Poul-Henning Kamp <phk@phk.freebsd.dk>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include "config.h"

#include "cache_varnishd.h"

#include <stdio.h>
#include <stdlib.h>

#include "vgz.h"
#include "vsl_priv.h"
#include "vmb.h"

#include "common/heritage.h"
#include "common/vsmw.h"

/* ------------------------------------------------------------
 * strands helpers - move elsewhere?
 */

static unsigned
strands_len(const struct strands *s)
{
	unsigned r = 0;
	int i;

	for (i = 0; i < s->n; i++) {
		if (s->p[i] == NULL || *s->p[i] == '\0')
			continue;
		r += strlen(s->p[i]);
	}

	return (r);
}

/*
 * like VRT_Strands(), but truncating instead of failing for end of buffer
 *
 * returns number of bytes including NUL
 */
static unsigned
strands_cat(char *buf, unsigned bufl, const struct strands *s)
{
	unsigned l = 0, ll;
	int i;

	/* NUL-terminated */
	assert(bufl > 0);
	bufl--;

	for (i = 0; i < s->n && bufl > 0; i++) {
		if (s->p[i] == NULL || *s->p[i] == '\0')
			continue;
		ll = strlen(s->p[i]);
		if (ll > bufl)
			ll = bufl;
		memcpy(buf, s->p[i], ll);
		l += ll;
		buf += ll;
		bufl -= ll;
	}
	*buf = '\0';	/* NUL-terminated */
	return (l + 1);
}

/* These cannot be struct lock, which depends on vsm/vsl working */
static pthread_mutex_t vsl_mtx;
static pthread_mutex_t vsc_mtx;
static pthread_mutex_t vsm_mtx;

static struct VSL_head		*vsl_head;
static const uint32_t		*vsl_end;
static uint32_t			*vsl_ptr;
static unsigned			vsl_segment_n;
static ssize_t			vsl_segsize;

struct VSC_main *VSC_C_main;

static void
vsl_sanity(const struct vsl_log *vsl)
{
	AN(vsl);
	AN(vsl->wlp);
	AN(vsl->wlb);
	AN(vsl->wle);
}

/*--------------------------------------------------------------------
 * Check if the VSL_tag is masked by parameter bitmap
 */

static inline int
vsl_tag_is_masked(enum VSL_tag_e tag)
{
	volatile uint8_t *bm = &cache_param->vsl_mask[0];
	uint8_t b;

	assert(tag > SLT__Bogus);
	assert(tag < SLT__Reserved);
	bm += ((unsigned)tag >> 3);
	b = (0x80 >> ((unsigned)tag & 7));
	return (*bm & b);
}

/*--------------------------------------------------------------------
 * Lay down a header fields, and return pointer to the next record
 */

static inline uint32_t *
vsl_hdr(enum VSL_tag_e tag, uint32_t *p, unsigned len, uint32_t vxid)
{

	AZ((uintptr_t)p & 0x3);
	assert(tag > SLT__Bogus);
	assert(tag < SLT__Reserved);
	AZ(len & ~VSL_LENMASK);

	p[1] = vxid;
	p[0] = ((((unsigned)tag & 0xff) << 24) | len);
	return (VSL_END(p, len));
}

/*--------------------------------------------------------------------
 * Wrap the VSL buffer
 */

static void
vsl_wrap(void)
{

	assert(vsl_ptr >= vsl_head->log);
	assert(vsl_ptr < vsl_end);
	vsl_segment_n += VSL_SEGMENTS - (vsl_segment_n % VSL_SEGMENTS);
	assert(vsl_segment_n % VSL_SEGMENTS == 0);
	vsl_head->offset[0] = 0;
	vsl_head->log[0] = VSL_ENDMARKER;
	VWMB();
	if (vsl_ptr != vsl_head->log) {
		*vsl_ptr = VSL_WRAPMARKER;
		vsl_ptr = vsl_head->log;
	}
	vsl_head->segment_n = vsl_segment_n;
	VSC_C_main->shm_cycles++;
}

/*--------------------------------------------------------------------
 * Reserve bytes for a record, wrap if necessary
 */

static uint32_t *
vsl_get(unsigned len, unsigned records, unsigned flushes)
{
	uint32_t *p;
	int err;

	err = pthread_mutex_trylock(&vsl_mtx);
	if (err == EBUSY) {
		AZ(pthread_mutex_lock(&vsl_mtx));
		VSC_C_main->shm_cont++;
	} else {
		AZ(err);
	}
	assert(vsl_ptr < vsl_end);
	AZ((uintptr_t)vsl_ptr & 0x3);

	VSC_C_main->shm_writes++;
	VSC_C_main->shm_flushes += flushes;
	VSC_C_main->shm_records += records;

	/* Wrap if necessary */
	if (VSL_END(vsl_ptr, len) >= vsl_end)
		vsl_wrap();

	p = vsl_ptr;
	vsl_ptr = VSL_END(vsl_ptr, len);
	assert(vsl_ptr < vsl_end);
	AZ((uintptr_t)vsl_ptr & 0x3);

	*vsl_ptr = VSL_ENDMARKER;

	while ((vsl_ptr - vsl_head->log) / vsl_segsize >
	    vsl_segment_n % VSL_SEGMENTS) {
		vsl_segment_n++;
		vsl_head->offset[vsl_segment_n % VSL_SEGMENTS] =
		    vsl_ptr - vsl_head->log;
	}

	AZ(pthread_mutex_unlock(&vsl_mtx));
	/* Implicit VWMB() in mutex op ensures ENDMARKER and new table
	   values are seen before new segment number */
	vsl_head->segment_n = vsl_segment_n;

	return (p);
}

/*--------------------------------------------------------------------
 * Stick a finished record into VSL.
 */

static void
vslr(enum VSL_tag_e tag, uint32_t vxid, const char *b, unsigned len)
{
	uint32_t *p;
	unsigned mlen;

	mlen = cache_param->vsl_reclen;

	/* Truncate */
	if (len > mlen)
		len = mlen;

	p = vsl_get(len, 1, 0);

	memcpy(p + 2, b, len);

	/*
	 * vsl_hdr() writes p[1] again, but we want to make sure it
	 * has hit memory because we work on the live buffer here.
	 */
	p[1] = vxid;
	VWMB();
	(void)vsl_hdr(tag, p, len, vxid);
}

/*--------------------------------------------------------------------
 * Add a unbuffered record to VSL
 *
 * NB: This variant should be used sparingly and only for low volume
 * NB: since it significantly adds to the mutex load on the VSL.
 */

void
VSLv(enum VSL_tag_e tag, uint32_t vxid, const char *fmt, va_list ap)
{
	unsigned n, mlen = cache_param->vsl_reclen;
	char buf[mlen];

	AN(fmt);
	if (vsl_tag_is_masked(tag))
		return;

	if (strchr(fmt, '%') == NULL) {
		vslr(tag, vxid, fmt, strlen(fmt) + 1);
	} else {
		n = vsnprintf(buf, mlen, fmt, ap);
		if (n > mlen - 1)
			n = mlen - 1;
		buf[n++] = '\0'; /* NUL-terminated */
		vslr(tag, vxid, buf, n);
	}

}

void
VSLs(enum VSL_tag_e tag, uint32_t vxid, const struct strands *s)
{
	unsigned n, mlen = cache_param->vsl_reclen;
	char buf[mlen];

	if (vsl_tag_is_masked(tag))
		return;

	n = strands_cat(buf, mlen, s);

	vslr(tag, vxid, buf, n);
}

void
VSL(enum VSL_tag_e tag, uint32_t vxid, const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	VSLv(tag, vxid, fmt, ap);
	va_end(ap);
}

/*--------------------------------------------------------------------*/

void
VSL_Flush(struct vsl_log *vsl, int overflow)
{
	uint32_t *p;
	unsigned l;

	vsl_sanity(vsl);
	l = pdiff(vsl->wlb, vsl->wlp);
	if (l == 0)
		return;

	assert(l >= 8);

	p = vsl_get(l, vsl->wlr, overflow);

	memcpy(p + 2, vsl->wlb, l);
	p[1] = l;
	VWMB();
	p[0] = ((((unsigned)SLT__Batch & 0xff) << 24));
	vsl->wlp = vsl->wlb;
	vsl->wlr = 0;
}

/*--------------------------------------------------------------------
 * VSL-buffered-txt
 */

void
VSLbt(struct vsl_log *vsl, enum VSL_tag_e tag, txt t)
{
	unsigned l, mlen;
	char *p;

	vsl_sanity(vsl);
	Tcheck(t);
	if (vsl_tag_is_masked(tag))
		return;
	mlen = cache_param->vsl_reclen;

	/* Truncate */
	l = Tlen(t);
	if (l > mlen - 1)
		l = mlen - 1;

	assert(vsl->wlp < vsl->wle);

	/* Flush if necessary */
	if (VSL_END(vsl->wlp, l + 1) >= vsl->wle)
		VSL_Flush(vsl, 1);
	assert(VSL_END(vsl->wlp, l + 1) < vsl->wle);
	p = VSL_DATA(vsl->wlp);
	memcpy(p, t.b, l);
	p[l++] = '\0';		/* NUL-terminated */
	vsl->wlp = vsl_hdr(tag, vsl->wlp, l, vsl->wid);
	assert(vsl->wlp < vsl->wle);
	vsl->wlr++;

	if (DO_DEBUG(DBG_SYNCVSL))
		VSL_Flush(vsl, 0);
}

/*--------------------------------------------------------------------
 * VSL-buffered-strands
 */
void
VSLbs(struct vsl_log *vsl, enum VSL_tag_e tag, const struct strands *s)
{
	unsigned l, mlen;

	vsl_sanity(vsl);
	if (vsl_tag_is_masked(tag))
		return;
	mlen = cache_param->vsl_reclen;

	/* including NUL */
	l = strands_len(s) + 1;
	if (l > mlen)
		l = mlen;

	assert(vsl->wlp < vsl->wle);

	/* Flush if necessary */
	if (VSL_END(vsl->wlp, l) >= vsl->wle)
		VSL_Flush(vsl, 1);
	assert(VSL_END(vsl->wlp, l) < vsl->wle);

	mlen = strands_cat(VSL_DATA(vsl->wlp), l, s);
	assert(l == mlen);

	vsl->wlp = vsl_hdr(tag, vsl->wlp, l, vsl->wid);
	assert(vsl->wlp < vsl->wle);
	vsl->wlr++;

	if (DO_DEBUG(DBG_SYNCVSL))
		VSL_Flush(vsl, 0);
}

/*--------------------------------------------------------------------
 * VSL-buffered
 */

void
VSLbv(struct vsl_log *vsl, enum VSL_tag_e tag, const char *fmt, va_list ap)
{
	char *p;
	const char *u, *f;
	unsigned n, mlen;
	txt t;

	vsl_sanity(vsl);
	AN(fmt);
	if (vsl_tag_is_masked(tag))
		return;

	/*
	 * If there are no printf-expansions, don't waste time expanding them
	 */
	f = NULL;
	for (u = fmt; *u != '\0'; u++)
		if (*u == '%')
			f = u;
	if (f == NULL) {
		t.b = TRUST_ME(fmt);
		t.e = TRUST_ME(u);
		VSLbt(vsl, tag, t);
		return;
	}

	if (!strcmp(fmt, "%s")) {
		p = va_arg(ap, char *);
		t.b = p;
		t.e = strchr(p, '\0');
		VSLbt(vsl, tag, t);
		return;
	}

	mlen = cache_param->vsl_reclen;

	/* Flush if we cannot fit a full size record */
	if (VSL_END(vsl->wlp, mlen + 1) >= vsl->wle)
		VSL_Flush(vsl, 1);

	p = VSL_DATA(vsl->wlp);
	n = vsnprintf(p, mlen, fmt, ap);
	if (n > mlen - 1)
		n = mlen - 1;	/* we truncate long fields */
	p[n++] = '\0';		/* NUL-terminated */
	vsl->wlp = vsl_hdr(tag, vsl->wlp, n, vsl->wid);
	assert(vsl->wlp < vsl->wle);
	vsl->wlr++;

	if (DO_DEBUG(DBG_SYNCVSL))
		VSL_Flush(vsl, 0);
}

void
VSLb(struct vsl_log *vsl, enum VSL_tag_e tag, const char *fmt, ...)
{
	va_list ap;

	vsl_sanity(vsl);
	va_start(ap, fmt);
	VSLbv(vsl, tag, fmt, ap);
	va_end(ap);
}

#define Tf6 "%ju.%06ju"
#define Ta6(t) (uintmax_t)floor((t)), (uintmax_t)floor((t) * 1e6) % 1000000U

void
VSLb_ts(struct vsl_log *vsl, const char *event, vtim_real first,
    vtim_real *pprev, vtim_real now)
{

	/*
	 * XXX: Make an option to turn off some unnecessary timestamp
	 * logging. This must be done carefully because some functions
	 * (e.g. V1L_Open) takes the last timestamp as its initial
	 * value for timeout calculation.
	 */
	vsl_sanity(vsl);
	AN(event);
	AN(pprev);
	assert(!isnan(now) && now != 0.);
	VSLb(vsl, SLT_Timestamp, "%s: " Tf6 " " Tf6 " " Tf6,
	    event, Ta6(now), Ta6(now - first), Ta6(now - *pprev));
	*pprev = now;
}

void
VSLb_bin(struct vsl_log *vsl, enum VSL_tag_e tag, ssize_t len, const void *ptr)
{
	unsigned mlen;
	char *p;

	vsl_sanity(vsl);
	AN(ptr);
	if (vsl_tag_is_masked(tag))
		return;
	mlen = cache_param->vsl_reclen;

	/* Truncate */
	if (len > mlen)
		len = mlen;

	assert(vsl->wlp < vsl->wle);

	/* Flush if necessary */
	if (VSL_END(vsl->wlp, len) >= vsl->wle)
		VSL_Flush(vsl, 1);
	assert(VSL_END(vsl->wlp, len) < vsl->wle);
	p = VSL_DATA(vsl->wlp);
	memcpy(p, ptr, len);
	vsl->wlp = vsl_hdr(tag, vsl->wlp, len, vsl->wid);
	assert(vsl->wlp < vsl->wle);
	vsl->wlr++;

	if (DO_DEBUG(DBG_SYNCVSL))
		VSL_Flush(vsl, 0);
}

/*--------------------------------------------------------------------
 * Setup a VSL buffer, allocate space if none provided.
 */

void
VSL_Setup(struct vsl_log *vsl, void *ptr, size_t len)
{

	if (ptr == NULL) {
		len = cache_param->vsl_buffer;
		ptr = malloc(len);
		AN(ptr);
	}
	vsl->wlp = ptr;
	vsl->wlb = ptr;
	vsl->wle = ptr;
	vsl->wle += len / sizeof(*vsl->wle);
	vsl->wlr = 0;
	vsl->wid = 0;
	vsl_sanity(vsl);
}

/*--------------------------------------------------------------------*/

void
VSL_ChgId(struct vsl_log *vsl, const char *typ, const char *why, uint32_t vxid)
{
	uint32_t ovxid;

	vsl_sanity(vsl);
	ovxid = vsl->wid;
	VSLb(vsl, SLT_Link, "%s %u %s", typ, VXID(vxid), why);
	VSL_End(vsl);
	vsl->wid = vxid;
	VSLb(vsl, SLT_Begin, "%s %u %s", typ, VXID(ovxid), why);
}

/*--------------------------------------------------------------------*/

void
VSL_End(struct vsl_log *vsl)
{
	txt t;
	char p[] = "";

	vsl_sanity(vsl);
	AN(vsl->wid);
	t.b = p;
	t.e = p;
	VSLbt(vsl, SLT_End, t);
	VSL_Flush(vsl, 0);
	vsl->wid = 0;
}

static void v_matchproto_(vsm_lock_f)
vsm_vsc_lock(void)
{
	AZ(pthread_mutex_lock(&vsc_mtx));
}

static void v_matchproto_(vsm_lock_f)
vsm_vsc_unlock(void)
{
	AZ(pthread_mutex_unlock(&vsc_mtx));
}

static void v_matchproto_(vsm_lock_f)
vsm_vsmw_lock(void)
{
	AZ(pthread_mutex_lock(&vsm_mtx));
}

static void v_matchproto_(vsm_lock_f)
vsm_vsmw_unlock(void)
{
	AZ(pthread_mutex_unlock(&vsm_mtx));
}

/*--------------------------------------------------------------------*/

void
VSM_Init(void)
{
	unsigned u;

	assert(UINT_MAX % VSL_SEGMENTS == VSL_SEGMENTS - 1);

	AZ(pthread_mutex_init(&vsl_mtx, NULL));
	AZ(pthread_mutex_init(&vsc_mtx, NULL));
	AZ(pthread_mutex_init(&vsm_mtx, NULL));

	vsc_lock = vsm_vsc_lock;
	vsc_unlock = vsm_vsc_unlock;
	vsmw_lock = vsm_vsmw_lock;
	vsmw_unlock = vsm_vsmw_unlock;

	VSC_C_main = VSC_main_New(NULL, NULL, "");
	AN(VSC_C_main);

	AN(heritage.proc_vsmw);
	vsl_head = VSMW_Allocf(heritage.proc_vsmw, NULL, VSL_CLASS,
	    cache_param->vsl_space, VSL_CLASS);
	AN(vsl_head);
	vsl_segsize = ((cache_param->vsl_space - sizeof *vsl_head) /
	    sizeof *vsl_end) / VSL_SEGMENTS;
	vsl_end = vsl_head->log + vsl_segsize * VSL_SEGMENTS;
	/* Make segment_n always overflow on first log wrap to make any
	   problems with regard to readers on that event visible */
	vsl_segment_n = UINT_MAX - (VSL_SEGMENTS - 1);
	AZ(vsl_segment_n % VSL_SEGMENTS);
	vsl_ptr = vsl_head->log;
	*vsl_ptr = VSL_ENDMARKER;

	memset(vsl_head, 0, sizeof *vsl_head);
	vsl_head->segsize = vsl_segsize;
	vsl_head->offset[0] = 0;
	vsl_head->segment_n = vsl_segment_n;
	for (u = 1; u < VSL_SEGMENTS; u++)
		vsl_head->offset[u] = -1;
	VWMB();
	memcpy(vsl_head->marker, VSL_HEAD_MARKER, sizeof vsl_head->marker);
}
