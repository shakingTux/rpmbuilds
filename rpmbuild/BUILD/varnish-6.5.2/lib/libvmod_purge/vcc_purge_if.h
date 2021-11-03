/*
 * NB:  This file is machine generated, DO NOT EDIT!
 *
 * Edit ./vmod_purge.vcc and run make instead
 */

#ifndef VDEF_H_INCLUDED
#  error "Include vdef.h first"
#endif
#ifndef VRT_H_INCLUDED
#  error "Include vrt.h first"
#endif

#define VPFX(a) vmod_##a
#define VARGS(a) arg_vmod_purge_##a
#define VENUM(a) enum_vmod_purge_##a
//lint -esym(755, VPFX)
//lint -esym(767, VPFX)
//lint -esym(755, VARGS)
//lint -esym(767, VARGS)
//lint -esym(755, VENUM)
//lint -esym(767, VENUM)
//lint -esym(755, VARGS)
//lint -esym(755, VENUM)



VCL_INT vmod_hard(VRT_CTX);
VCL_INT vmod_soft(VRT_CTX, VCL_DURATION, VCL_DURATION,
    VCL_DURATION);
