/*
 * NB:  This file is machine generated, DO NOT EDIT!
 *
 * Edit ./vmod_proxy.vcc and run make instead
 */

#ifndef VDEF_H_INCLUDED
#  error "Include vdef.h first"
#endif
#ifndef VRT_H_INCLUDED
#  error "Include vrt.h first"
#endif

#define VPFX(a) vmod_##a
#define VARGS(a) arg_vmod_proxy_##a
#define VENUM(a) enum_vmod_proxy_##a
//lint -esym(755, VPFX)
//lint -esym(767, VPFX)
//lint -esym(755, VARGS)
//lint -esym(767, VARGS)
//lint -esym(755, VENUM)
//lint -esym(767, VENUM)
//lint -esym(755, VARGS)
//lint -esym(755, VENUM)



VCL_STRING vmod_alpn(VRT_CTX);
VCL_STRING vmod_authority(VRT_CTX);
VCL_BOOL vmod_is_ssl(VRT_CTX);
VCL_BOOL vmod_client_has_cert_sess(VRT_CTX);
VCL_BOOL vmod_client_has_cert_conn(VRT_CTX);
VCL_INT vmod_ssl_verify_result(VRT_CTX);
VCL_STRING vmod_ssl_version(VRT_CTX);
VCL_STRING vmod_client_cert_cn(VRT_CTX);
VCL_STRING vmod_ssl_cipher(VRT_CTX);
VCL_STRING vmod_cert_sign(VRT_CTX);
VCL_STRING vmod_cert_key(VRT_CTX);
