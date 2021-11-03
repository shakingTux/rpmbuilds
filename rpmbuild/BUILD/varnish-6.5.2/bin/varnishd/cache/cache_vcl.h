/*-
 * Copyright (c) 2006 Verdens Gang AS
 * Copyright (c) 2006-2016 Varnish Software AS
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
 * NB: This is a private .h file for cache_vcl*.c
 * NB: No other code should include this file.
 *
 */

struct vfilter;
struct vcltemp;

VTAILQ_HEAD(vfilter_head, vfilter);


struct vcl {
	unsigned		magic;
#define VCL_MAGIC		0x214188f2
	VTAILQ_ENTRY(vcl)	list;
	void			*dlh;
	const struct VCL_conf	*conf;
	char			state[8];
	char			*loaded_name;
	unsigned		busy;
	unsigned		discard;
	const struct vcltemp	*temp;
	VTAILQ_HEAD(,vcldir)	director_list;
	VTAILQ_HEAD(,vclref)	ref_list;
	int			nrefs;
	struct vcl		*label;
	int			nlabels;
	struct vfilter_head	vfps;
	struct vfilter_head	vdps;
};

struct vclref {
	unsigned		magic;
#define VCLREF_MAGIC		0x47fb6848
	struct vcl		*vcl;
	VTAILQ_ENTRY(vclref)	list;
	char			*desc;
};

extern struct lock		vcl_mtx;
extern struct vcl		*vcl_active; /* protected by vcl_mtx */
struct vcl *vcl_find(const char *);
void VCL_Update(struct vcl **, struct vcl *);

struct vcltemp {
	const char * const	name;
	unsigned		is_warm;
	unsigned		is_cold;
};

/*
 * NB: The COOLING temperature is neither COLD nor WARM.
 * And LABEL is not a temperature, it's a different kind of VCL.
 */
extern const struct vcltemp VCL_TEMP_INIT[1];
extern const struct vcltemp VCL_TEMP_COLD[1];
extern const struct vcltemp VCL_TEMP_WARM[1];
extern const struct vcltemp VCL_TEMP_BUSY[1];
extern const struct vcltemp VCL_TEMP_COOLING[1];
