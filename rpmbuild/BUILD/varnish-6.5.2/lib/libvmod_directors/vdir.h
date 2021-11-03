/*-
 * Copyright (c) 2013-2015 Varnish Software AS
 * All rights reserved.
 *
 * Author: Poul-Henning Kamp <phk@FreeBSD.org>
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

struct vbitmap;

struct vdir {
	unsigned				magic;
#define VDIR_MAGIC				0x99f4b726
	unsigned				n_backend;
	unsigned				l_backend;
	unsigned				n_healthy;
	pthread_rwlock_t			mtx;
	VCL_BACKEND				*backend;
	double					*weight;
	double					total_weight;
	VCL_BACKEND				dir;
	struct vbitmap				*healthy;
};

void vdir_new(VRT_CTX, struct vdir **vdp, const char *vcl_name,
    const struct vdi_methods *, void *priv);
void vdir_delete(struct vdir **vdp);
void vdir_rdlock(struct vdir *vd);
void vdir_wrlock(struct vdir *vd);
void vdir_unlock(struct vdir *vd);
void vdir_add_backend(VRT_CTX, struct vdir *, VCL_BACKEND, double weight);
void vdir_remove_backend(VRT_CTX, struct vdir *, VCL_BACKEND, unsigned *cur);
VCL_BOOL vdir_any_healthy(VRT_CTX, struct vdir *, VCL_TIME *);
void vdir_list(VRT_CTX, struct vdir *, struct vsb *, int, int, int);
void vdir_update_health(VRT_CTX, struct vdir *);
VCL_BACKEND vdir_pick_be(VRT_CTX, struct vdir *, double w);
