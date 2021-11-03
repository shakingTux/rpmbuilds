/*
 * NB:  This file is machine generated, DO NOT EDIT!
 *
 * Edit ./vmod_blob.vcc and run make instead
 */

#ifndef VDEF_H_INCLUDED
#  error "Include vdef.h first"
#endif
#ifndef VRT_H_INCLUDED
#  error "Include vrt.h first"
#endif

#define VPFX(a) vmod_##a
#define VARGS(a) arg_vmod_blob_##a
#define VENUM(a) enum_vmod_blob_##a
//lint -esym(755, VPFX)
//lint -esym(767, VPFX)
//lint -esym(755, VARGS)
//lint -esym(767, VARGS)
//lint -esym(755, VENUM)
//lint -esym(767, VENUM)
//lint -esym(755, VARGS)
//lint -esym(755, VENUM)

extern VCL_ENUM VENUM(BASE64);
extern VCL_ENUM VENUM(BASE64URL);
extern VCL_ENUM VENUM(BASE64URLNOPAD);
extern VCL_ENUM VENUM(DEFAULT);
extern VCL_ENUM VENUM(HEX);
extern VCL_ENUM VENUM(IDENTITY);
extern VCL_ENUM VENUM(LOWER);
extern VCL_ENUM VENUM(UPPER);
extern VCL_ENUM VENUM(URL);

//lint -esym(14, enum_vmod_blob_BASE64)
//lint -esym(759, enum_vmod_blob_BASE64)
//lint -esym(765, enum_vmod_blob_BASE64)
//lint -esym(14, enum_vmod_blob_BASE64URL)
//lint -esym(759, enum_vmod_blob_BASE64URL)
//lint -esym(765, enum_vmod_blob_BASE64URL)
//lint -esym(14, enum_vmod_blob_BASE64URLNOPAD)
//lint -esym(759, enum_vmod_blob_BASE64URLNOPAD)
//lint -esym(765, enum_vmod_blob_BASE64URLNOPAD)
//lint -esym(14, enum_vmod_blob_DEFAULT)
//lint -esym(759, enum_vmod_blob_DEFAULT)
//lint -esym(765, enum_vmod_blob_DEFAULT)
//lint -esym(14, enum_vmod_blob_HEX)
//lint -esym(759, enum_vmod_blob_HEX)
//lint -esym(765, enum_vmod_blob_HEX)
//lint -esym(14, enum_vmod_blob_IDENTITY)
//lint -esym(759, enum_vmod_blob_IDENTITY)
//lint -esym(765, enum_vmod_blob_IDENTITY)
//lint -esym(14, enum_vmod_blob_LOWER)
//lint -esym(759, enum_vmod_blob_LOWER)
//lint -esym(765, enum_vmod_blob_LOWER)
//lint -esym(14, enum_vmod_blob_UPPER)
//lint -esym(759, enum_vmod_blob_UPPER)
//lint -esym(765, enum_vmod_blob_UPPER)
//lint -esym(14, enum_vmod_blob_URL)
//lint -esym(759, enum_vmod_blob_URL)
//lint -esym(765, enum_vmod_blob_URL)

VCL_BLOB vmod_decode(VRT_CTX, VCL_ENUM, VCL_INT, VCL_STRANDS);
VCL_STRING vmod_encode(VRT_CTX, VCL_ENUM, VCL_ENUM, VCL_BLOB);
VCL_STRING vmod_transcode(VRT_CTX, VCL_ENUM, VCL_ENUM, VCL_ENUM,
    VCL_INT, VCL_STRANDS);
VCL_BOOL vmod_same(VRT_CTX, VCL_BLOB, VCL_BLOB);
VCL_BOOL vmod_equal(VRT_CTX, VCL_BLOB, VCL_BLOB);
VCL_INT vmod_length(VRT_CTX, VCL_BLOB);
VCL_BLOB vmod_sub(VRT_CTX, VCL_BLOB, VCL_BYTES, VCL_BYTES);
struct VPFX(blob_blob);
VCL_VOID vmod_blob__init(VRT_CTX, struct VPFX(blob_blob) **,
    const char *, VCL_ENUM, VCL_STRANDS);
VCL_VOID vmod_blob__fini(struct VPFX(blob_blob) **);
VCL_BLOB vmod_blob_get(VRT_CTX, struct VPFX(blob_blob) *);
VCL_STRING vmod_blob_encode(VRT_CTX, struct VPFX(blob_blob) *,
    VCL_ENUM, VCL_ENUM);

