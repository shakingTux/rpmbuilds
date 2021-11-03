/*
 * NB:  This file is machine generated, DO NOT EDIT!
 *
 * Edit ./vmod_debug.vcc and run make instead
 */

#ifndef VDEF_H_INCLUDED
#  error "Include vdef.h first"
#endif
#ifndef VRT_H_INCLUDED
#  error "Include vrt.h first"
#endif

#define VPFX(a) xyzzy_##a
#define VARGS(a) arg_xyzzy_debug_##a
#define VENUM(a) enum_xyzzy_debug_##a
//lint -esym(755, VPFX)
//lint -esym(767, VPFX)
//lint -esym(755, VARGS)
//lint -esym(767, VARGS)
//lint -esym(755, VENUM)
//lint -esym(767, VENUM)
//lint -esym(755, VARGS)
//lint -esym(755, VENUM)

extern VCL_ENUM VENUM(des);
extern VCL_ENUM VENUM(first);
extern VCL_ENUM VENUM(geoff);
extern VCL_ENUM VENUM(kristian);
extern VCL_ENUM VENUM(last);
extern VCL_ENUM VENUM(martin);
extern VCL_ENUM VENUM(miss);
extern VCL_ENUM VENUM(mithrandir);
extern VCL_ENUM VENUM(one);
extern VCL_ENUM VENUM(phk);
extern VCL_ENUM VENUM(slink);
extern VCL_ENUM VENUM(three);
extern VCL_ENUM VENUM(two);

//lint -esym(14, enum_xyzzy_debug_des)
//lint -esym(759, enum_xyzzy_debug_des)
//lint -esym(765, enum_xyzzy_debug_des)
//lint -esym(14, enum_xyzzy_debug_first)
//lint -esym(759, enum_xyzzy_debug_first)
//lint -esym(765, enum_xyzzy_debug_first)
//lint -esym(14, enum_xyzzy_debug_geoff)
//lint -esym(759, enum_xyzzy_debug_geoff)
//lint -esym(765, enum_xyzzy_debug_geoff)
//lint -esym(14, enum_xyzzy_debug_kristian)
//lint -esym(759, enum_xyzzy_debug_kristian)
//lint -esym(765, enum_xyzzy_debug_kristian)
//lint -esym(14, enum_xyzzy_debug_last)
//lint -esym(759, enum_xyzzy_debug_last)
//lint -esym(765, enum_xyzzy_debug_last)
//lint -esym(14, enum_xyzzy_debug_martin)
//lint -esym(759, enum_xyzzy_debug_martin)
//lint -esym(765, enum_xyzzy_debug_martin)
//lint -esym(14, enum_xyzzy_debug_miss)
//lint -esym(759, enum_xyzzy_debug_miss)
//lint -esym(765, enum_xyzzy_debug_miss)
//lint -esym(14, enum_xyzzy_debug_mithrandir)
//lint -esym(759, enum_xyzzy_debug_mithrandir)
//lint -esym(765, enum_xyzzy_debug_mithrandir)
//lint -esym(14, enum_xyzzy_debug_one)
//lint -esym(759, enum_xyzzy_debug_one)
//lint -esym(765, enum_xyzzy_debug_one)
//lint -esym(14, enum_xyzzy_debug_phk)
//lint -esym(759, enum_xyzzy_debug_phk)
//lint -esym(765, enum_xyzzy_debug_phk)
//lint -esym(14, enum_xyzzy_debug_slink)
//lint -esym(759, enum_xyzzy_debug_slink)
//lint -esym(765, enum_xyzzy_debug_slink)
//lint -esym(14, enum_xyzzy_debug_three)
//lint -esym(759, enum_xyzzy_debug_three)
//lint -esym(765, enum_xyzzy_debug_three)
//lint -esym(14, enum_xyzzy_debug_two)
//lint -esym(759, enum_xyzzy_debug_two)
//lint -esym(765, enum_xyzzy_debug_two)

vmod_event_f VPFX(event_function);
VCL_STRING xyzzy_author(VRT_CTX, VCL_ENUM, VCL_ENUM);
VCL_VOID xyzzy_test_priv_call(VRT_CTX, struct vmod_priv *);
VCL_VOID xyzzy_test_priv_vcl(VRT_CTX, struct vmod_priv *);
VCL_STRING xyzzy_test_priv_task(VRT_CTX, struct vmod_priv *,
    VCL_STRING);
VCL_STRING xyzzy_test_priv_top(VRT_CTX, struct vmod_priv *,
    VCL_STRING);
struct VPFX(debug_obj);
VCL_VOID xyzzy_obj__init(VRT_CTX, struct VPFX(debug_obj) **,
    const char *, VCL_STRING, VCL_ENUM);
VCL_VOID xyzzy_obj__fini(struct VPFX(debug_obj) **);
VCL_VOID xyzzy_obj_enum(VRT_CTX, struct VPFX(debug_obj) *,
    VCL_ENUM);
VCL_STRING xyzzy_obj_string(VRT_CTX, struct VPFX(debug_obj) *);
VCL_STRING xyzzy_obj_number(VRT_CTX, struct VPFX(debug_obj) *);
VCL_STRING xyzzy_obj_foo(VRT_CTX, struct VPFX(debug_obj) *,
    VCL_STRING);
VCL_TIME xyzzy_obj_date(VRT_CTX, struct VPFX(debug_obj) *);
VCL_VOID xyzzy_obj_test_priv_call(VRT_CTX,
    struct VPFX(debug_obj) *, struct vmod_priv *);
VCL_VOID xyzzy_obj_test_priv_vcl(VRT_CTX,
    struct VPFX(debug_obj) *, struct vmod_priv *);
VCL_STRING xyzzy_obj_test_priv_task(VRT_CTX,
    struct VPFX(debug_obj) *, struct vmod_priv *, VCL_STRING);
VCL_STRING xyzzy_obj_test_priv_top(VRT_CTX,
    struct VPFX(debug_obj) *, struct vmod_priv *, VCL_STRING);

VCL_VOID xyzzy_rot52(VRT_CTX, VCL_HTTP);

struct VARGS(argtest) {
	char			valid_opt;
	VCL_STRING		one;
	VCL_REAL		two;
	VCL_STRING		three;
	VCL_STRING		comma;
	VCL_INT			four;
	VCL_STRING		opt;
};
VCL_STRING xyzzy_argtest(VRT_CTX, struct VARGS(argtest)*);
VCL_INT xyzzy_vre_limit(VRT_CTX);
VCL_VOID xyzzy_register_obj_events(VRT_CTX, struct vmod_priv *);
VCL_VOID xyzzy_fail(VRT_CTX);
VCL_BOOL xyzzy_fail2(VRT_CTX);
struct VPFX(debug_dyn);
VCL_VOID xyzzy_dyn__init(VRT_CTX, struct VPFX(debug_dyn) **,
    const char *, VCL_STRING, VCL_STRING, VCL_PROBE);
VCL_VOID xyzzy_dyn__fini(struct VPFX(debug_dyn) **);
VCL_BACKEND xyzzy_dyn_backend(VRT_CTX,
    struct VPFX(debug_dyn) *);
VCL_VOID xyzzy_dyn_refresh(VRT_CTX, struct VPFX(debug_dyn) *,
    VCL_STRING, VCL_STRING, VCL_PROBE);

struct VPFX(debug_dyn_uds);
VCL_VOID xyzzy_dyn_uds__init(VRT_CTX,
    struct VPFX(debug_dyn_uds) **, const char *, VCL_STRING);
VCL_VOID xyzzy_dyn_uds__fini(struct VPFX(debug_dyn_uds) **);
VCL_BACKEND xyzzy_dyn_uds_backend(VRT_CTX,
    struct VPFX(debug_dyn_uds) *);
VCL_VOID xyzzy_dyn_uds_refresh(VRT_CTX,
    struct VPFX(debug_dyn_uds) *, VCL_STRING);

VCL_VOID xyzzy_vcl_discard_delay(VRT_CTX, struct vmod_priv *,
    VCL_DURATION);
VCL_BOOL xyzzy_match_acl(VRT_CTX, VCL_ACL, VCL_IP);
VCL_VOID xyzzy_test_probe(VRT_CTX, VCL_PROBE, VCL_PROBE);
VCL_VOID xyzzy_vsc_new(VRT_CTX);
VCL_VOID xyzzy_vsc_count(VRT_CTX, VCL_INT);
VCL_VOID xyzzy_vsc_destroy(VRT_CTX);
struct VPFX(debug_concat);
VCL_VOID xyzzy_concat__init(VRT_CTX,
    struct VPFX(debug_concat) **, const char *, VCL_STRANDS);
VCL_VOID xyzzy_concat__fini(struct VPFX(debug_concat) **);
VCL_STRING xyzzy_concat_get(VRT_CTX,
    struct VPFX(debug_concat) *);

VCL_STRING xyzzy_concatenate(VRT_CTX, VCL_STRANDS);
VCL_STRING xyzzy_collect(VRT_CTX, VCL_STRANDS);
VCL_VOID xyzzy_sethdr(VRT_CTX, VCL_HEADER, VCL_STRANDS);
VCL_DURATION xyzzy_priv_perf(VRT_CTX, VCL_INT, VCL_INT);
struct VPFX(debug_obj_opt);

struct VARGS(obj_opt__init) {
	char			valid_s;
	char			valid_b;
	struct vmod_priv *	arg1;
	struct vmod_priv *	arg2;
	struct vmod_priv *	arg3;
	VCL_STRING		s;
	VCL_BOOL		b;
};
VCL_VOID xyzzy_obj_opt__init(VRT_CTX,
    struct VPFX(debug_obj_opt) **, const char *,
    struct VARGS(obj_opt__init)*);
VCL_VOID xyzzy_obj_opt__fini(struct VPFX(debug_obj_opt) **);

struct VARGS(obj_opt_meth_opt) {
	char			valid_s;
	char			valid_b;
	struct vmod_priv *	arg1;
	struct vmod_priv *	arg2;
	struct vmod_priv *	arg3;
	VCL_STRING		s;
	VCL_BOOL		b;
};
VCL_STRING xyzzy_obj_opt_meth_opt(VRT_CTX,
    struct VPFX(debug_obj_opt) *, struct VARGS(obj_opt_meth_opt)*);

VCL_STRANDS xyzzy_return_strands(VRT_CTX, VCL_STRANDS);
VCL_VOID xyzzy_catflap(VRT_CTX, VCL_ENUM);
VCL_BYTES xyzzy_stk(VRT_CTX);
VCL_VOID xyzzy_vcl_prevent_cold(VRT_CTX, struct vmod_priv *);
VCL_VOID xyzzy_vcl_allow_cold(VRT_CTX, struct vmod_priv *);
VCL_VOID xyzzy_cold_backend(VRT_CTX, struct vmod_priv *);
VCL_VOID xyzzy_cooling_backend(VRT_CTX, struct vmod_priv *);
VCL_VOID xyzzy_sndbuf(VRT_CTX, VCL_BYTES);
VCL_VOID xyzzy_store_ip(VRT_CTX, VCL_IP);
VCL_IP xyzzy_get_ip(VRT_CTX);
struct VPFX(debug_director);
VCL_VOID xyzzy_director__init(VRT_CTX,
    struct VPFX(debug_director) **, const char *);
VCL_VOID xyzzy_director__fini(struct VPFX(debug_director) **);
VCL_BACKEND xyzzy_director_fail(VRT_CTX,
    struct VPFX(debug_director) *);

VCL_STRING xyzzy_client_ip(VRT_CTX);
VCL_STRING xyzzy_client_port(VRT_CTX);
VCL_VOID xyzzy_fail_rollback(VRT_CTX);
VCL_VOID xyzzy_ok_rollback(VRT_CTX);
VCL_STRING xyzzy_re_quote(VRT_CTX, VCL_STRING);

struct VARGS(priv_task_with_option) {
	char			valid_opt;
	struct vmod_priv *	priv;
	VCL_STRING		opt;
};
VCL_STRING xyzzy_priv_task_with_option(VRT_CTX,
    struct VARGS(priv_task_with_option)*);
