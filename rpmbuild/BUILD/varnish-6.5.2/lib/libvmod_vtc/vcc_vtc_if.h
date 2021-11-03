/*
 * NB:  This file is machine generated, DO NOT EDIT!
 *
 * Edit ./vmod_vtc.vcc and run make instead
 */

#ifndef VDEF_H_INCLUDED
#  error "Include vdef.h first"
#endif
#ifndef VRT_H_INCLUDED
#  error "Include vrt.h first"
#endif

#define VPFX(a) vmod_##a
#define VARGS(a) arg_vmod_vtc_##a
#define VENUM(a) enum_vmod_vtc_##a
//lint -esym(755, VPFX)
//lint -esym(767, VPFX)
//lint -esym(755, VARGS)
//lint -esym(767, VARGS)
//lint -esym(755, VENUM)
//lint -esym(767, VENUM)
//lint -esym(755, VARGS)
//lint -esym(755, VENUM)

extern VCL_ENUM VENUM(backend);
extern VCL_ENUM VENUM(client);
extern VCL_ENUM VENUM(f);
extern VCL_ENUM VENUM(r);
extern VCL_ENUM VENUM(s);
extern VCL_ENUM VENUM(session);
extern VCL_ENUM VENUM(thread);
extern VCL_ENUM VENUM(v1);
extern VCL_ENUM VENUM(v2);

//lint -esym(14, enum_vmod_vtc_backend)
//lint -esym(759, enum_vmod_vtc_backend)
//lint -esym(765, enum_vmod_vtc_backend)
//lint -esym(14, enum_vmod_vtc_client)
//lint -esym(759, enum_vmod_vtc_client)
//lint -esym(765, enum_vmod_vtc_client)
//lint -esym(14, enum_vmod_vtc_f)
//lint -esym(759, enum_vmod_vtc_f)
//lint -esym(765, enum_vmod_vtc_f)
//lint -esym(14, enum_vmod_vtc_r)
//lint -esym(759, enum_vmod_vtc_r)
//lint -esym(765, enum_vmod_vtc_r)
//lint -esym(14, enum_vmod_vtc_s)
//lint -esym(759, enum_vmod_vtc_s)
//lint -esym(765, enum_vmod_vtc_s)
//lint -esym(14, enum_vmod_vtc_session)
//lint -esym(759, enum_vmod_vtc_session)
//lint -esym(765, enum_vmod_vtc_session)
//lint -esym(14, enum_vmod_vtc_thread)
//lint -esym(759, enum_vmod_vtc_thread)
//lint -esym(765, enum_vmod_vtc_thread)
//lint -esym(14, enum_vmod_vtc_v1)
//lint -esym(759, enum_vmod_vtc_v1)
//lint -esym(765, enum_vmod_vtc_v1)
//lint -esym(14, enum_vmod_vtc_v2)
//lint -esym(759, enum_vmod_vtc_v2)
//lint -esym(765, enum_vmod_vtc_v2)

VCL_VOID vmod_barrier_sync(VRT_CTX, VCL_STRING, VCL_DURATION);
VCL_BACKEND vmod_no_backend(VRT_CTX);
VCL_STEVEDORE vmod_no_stevedore(VRT_CTX);
VCL_IP vmod_no_ip(VRT_CTX);
VCL_VOID vmod_panic(VRT_CTX, VCL_STRANDS);
VCL_VOID vmod_sleep(VRT_CTX, VCL_DURATION);
VCL_VOID vmod_workspace_alloc(VRT_CTX, VCL_ENUM, VCL_INT);
VCL_BYTES vmod_workspace_reserve(VRT_CTX, VCL_ENUM, VCL_INT);
VCL_INT vmod_workspace_free(VRT_CTX, VCL_ENUM);
VCL_VOID vmod_workspace_snapshot(VRT_CTX, VCL_ENUM);
VCL_VOID vmod_workspace_reset(VRT_CTX, VCL_ENUM);
VCL_BOOL vmod_workspace_overflowed(VRT_CTX, VCL_ENUM);
VCL_VOID vmod_workspace_overflow(VRT_CTX, VCL_ENUM);
VCL_BLOB vmod_workspace_dump(VRT_CTX, VCL_ENUM, VCL_ENUM,
    VCL_BYTES, VCL_BYTES);
VCL_INT vmod_typesize(VRT_CTX, VCL_STRING);
VCL_BLOB vmod_proxy_header(VRT_CTX, VCL_ENUM, VCL_IP, VCL_IP,
    VCL_STRING);
