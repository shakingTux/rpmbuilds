/*
 * NB:  This file is machine generated, DO NOT EDIT!
 *
 * Edit ./vmod_cookie.vcc and run make instead
 */

#ifndef VDEF_H_INCLUDED
#  error "Include vdef.h first"
#endif
#ifndef VRT_H_INCLUDED
#  error "Include vrt.h first"
#endif

#define VPFX(a) vmod_##a
#define VARGS(a) arg_vmod_cookie_##a
#define VENUM(a) enum_vmod_cookie_##a
//lint -esym(755, VPFX)
//lint -esym(767, VPFX)
//lint -esym(755, VARGS)
//lint -esym(767, VARGS)
//lint -esym(755, VENUM)
//lint -esym(767, VENUM)
//lint -esym(755, VARGS)
//lint -esym(755, VENUM)



VCL_VOID vmod_clean(VRT_CTX, struct vmod_priv *);
VCL_VOID vmod_delete(VRT_CTX, struct vmod_priv *, VCL_STRING);
VCL_VOID vmod_filter(VRT_CTX, struct vmod_priv *, VCL_STRING);
VCL_VOID vmod_filter_re(VRT_CTX, struct vmod_priv *,
    struct vmod_priv *, VCL_STRING);
VCL_VOID vmod_keep(VRT_CTX, struct vmod_priv *, VCL_STRING);
VCL_VOID vmod_keep_re(VRT_CTX, struct vmod_priv *,
    struct vmod_priv *, VCL_STRING);
VCL_STRING vmod_format_rfc1123(VRT_CTX, VCL_TIME, VCL_DURATION);
VCL_STRING vmod_get(VRT_CTX, struct vmod_priv *, VCL_STRING);
VCL_STRING vmod_get_re(VRT_CTX, struct vmod_priv *,
    struct vmod_priv *, VCL_STRING);
VCL_STRING vmod_get_string(VRT_CTX, struct vmod_priv *);
VCL_BOOL vmod_isset(VRT_CTX, struct vmod_priv *, VCL_STRING);
VCL_VOID vmod_parse(VRT_CTX, struct vmod_priv *, VCL_STRING);
VCL_VOID vmod_set(VRT_CTX, struct vmod_priv *, VCL_STRING,
    VCL_STRING);
