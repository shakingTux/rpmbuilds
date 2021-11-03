/*-
 * Copyright 2015-2016 UPLEX - Nils Goroll Systemoptimierung
 * All rights reserved.
 *
 * Authors: Nils Goroll <nils.goroll@uplex.de>
 *          Geoffrey Simmons <geoffrey.simmons@uplex.de>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include "config.h"

#include <string.h>

#include "vdef.h"
#include "vrt.h"
#include "vas.h"

#include "vmod_blob.h"

size_t
id_encode_l(size_t l)
{
	return (l + 1);
}

size_t
id_decode_l(size_t l)
{
	return (l);
}

ssize_t
id_encode(const enum encoding enc, const enum case_e kase,
    blob_dest_t buf, blob_len_t buflen,
    blob_src_t in, blob_len_t inlen)
{
	(void) enc;
	(void) kase;
	AN(buf);

	if (buflen < inlen + 1)
		return (-1);
	if (in == NULL || inlen == 0)
		return (0);

	memcpy(buf, in, inlen);
	return (inlen);
}

ssize_t
id_decode(const enum encoding enc, blob_dest_t buf,
    blob_len_t buflen, ssize_t n, VCL_STRANDS strings)
{
	const char *s;
	char *dest = buf;
	size_t len, outlen = 0, c = SIZE_MAX;
	int i;

	(void)enc;
	AN(buf);
	AN(strings);

	if (n >= 0)
		c = n;

	for (i = 0; c > 0 && i < strings->n; i++) {
		s = strings->p[i];
		if (s == NULL || *s == '\0')
			continue;
		len = strlen(s);
		if (len > c)
			len = c;
		c -= len;
		if ((outlen += len) > buflen) {
			errno = ENOMEM;
			return (-1);
		}
		memcpy(dest, s, len);
		dest += len;
	}

	return (outlen);
}
