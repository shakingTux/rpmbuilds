/*-
 * Copyright (c) 2020 Varnish Software AS
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
 *
 */

#include "config.h"

#include <stdint.h>
#include <string.h>
#include <limits.h>
#include <sys/types.h>

#include "vdef.h"
#include "vas.h"
#include "vrt.h"
#include "venc.h"

#include "vsb.h"

/*
 * Yes: Cumbersome.  But if "..." syntax is used, C adds a NUL
 */

static const char base64_enc[64] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
    'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
    'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
    'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
    'o', 'p', 'r', 'q', 's', 't', 'u', 'v',
    'w', 'x', 'y', 'z', '0', '1', '2', '3',
    '4', '5', '6', '7', '8', '9', '+', '/'
};

/*
 * Encode base64 (RFC4648 section 4) into VSB.
 */

void
VENC_Encode_Base64(struct vsb *dst, const void *src, size_t len)
{
	const uint8_t *p = src;
	uint32_t u;
	char w[4];

	AN(dst);
	AN(src);
	for (; len >= 3; len -= 3, p += 3) {
		u = (p[0] << 16) | (p[1] << 8) | p[2];
		w[3] = base64_enc[u & 0x3f];
		u >>= 6;
		w[2] = base64_enc[u & 0x3f];
		u >>= 6;
		w[1] = base64_enc[u & 0x3f];
		u >>= 6;
		w[0] = base64_enc[u & 0x3f];
		if (VSB_bcat(dst, w, sizeof w))
			break;
	}
	if (len) {
		memset(w, '=', sizeof w);
		u = (p[0] << 16);
		if (len == 2)
		    u |= (p[1] << 8);
		w[0] = base64_enc[(u >> 18) & 0x3f];
		w[1] = base64_enc[(u >> 12) & 0x3f];
		if (len == 2)
			w[2] = base64_enc[(u >> 6) & 0x3f];
		VSB_bcat(dst, w, sizeof w);
	}
}

#define BV 64

static const uint8_t base64_dec[256] = {
    BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, BV,
    BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, BV,
    BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, 62, BV, BV, BV, 63,
    52, 53, 54, 55, 56, 57, 58, 59, 60, 61, BV, BV, BV,  0, BV, BV,
    BV,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14,
    15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, BV, BV, BV, BV, BV,
    BV, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
    41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, BV, BV, BV, BV, BV,
    BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, BV,
    BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, BV,
    BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, BV,
    BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, BV,
    BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, BV,
    BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, BV,
    BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, BV,
    BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, BV, BV
};

struct venc_state {
	unsigned		n;
	unsigned		f;
	uint8_t			w;
	struct vsb		*vsb;
	const uint8_t		*tbl;
};

static const char *
venc_decode_base64(struct venc_state *ves, const char *b, const char *e)
{
	unsigned i;

	AN(ves);
	AN(ves->vsb);
	AN(ves->tbl);

	AN(b);
	if (e == NULL)
		e = strchr(b, '\0');
	assert(e >= b);

	for (; b < e; b++) {
		i = ves->tbl[*(const uint8_t*)b];
		if (i == BV)
			return (b);
		if (*b == '=' && ves->n < 2)
			return (b);
		else if (*b == '=')
			ves->f++;
		else if (ves->f)
			return (b - 1);
		if (ves->f && ves->w)
			return (b - 1);
		switch(++ves->n) {
		case 1:
			ves->w = i << 2;
			break;
		case 2:
			ves->w |= i >> 4;
			VSB_putc(ves->vsb, ves->w);
			ves->w = i << 4;
			break;
		case 3:
			ves->w |= i >> 2;
			if (!ves->f)
				VSB_putc(ves->vsb, ves->w);
			ves->w = i << 6;
			break;
		case 4:
			ves->w |= i;
			if (!ves->f)
				VSB_putc(ves->vsb, ves->w);
			ves->w = 0;
			ves->n = 0;
			break;
		default:
			WRONG("Wrong turn in venc_decode_base64()");
		}
	}
	return (NULL);
}

/*
 * Decode base64 (RFC4648 section 4) into VSB.
 *
 * Returns NULL on success.
 * Returns pointer to offending input character on failure.
 */

const char *
VENC_Decode_Base64(struct vsb *dst, const char *b, const char *e)
{
	struct venc_state ves;
	const char *rv;

	memset(&ves, 0, sizeof ves);
	ves.vsb = dst;
	ves.tbl = base64_dec;

	rv = venc_decode_base64(&ves, b, e);
	if (rv)
		return (rv);
	if (ves.n)
		return (e);
	return (NULL);
}
