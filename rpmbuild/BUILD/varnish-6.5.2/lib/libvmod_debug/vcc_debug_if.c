/*
 * NB:  This file is machine generated, DO NOT EDIT!
 *
 * Edit ./vmod_debug.vcc and run make instead
 */

#include "config.h"
#include <stdio.h>
#include "vdef.h"
#include "vrt.h"
#include "vcc_debug_if.h"
#include "vmod_abi.h"

VCL_ENUM VENUM(des) = "des";
VCL_ENUM VENUM(first) = "first";
VCL_ENUM VENUM(geoff) = "geoff";
VCL_ENUM VENUM(kristian) = "kristian";
VCL_ENUM VENUM(last) = "last";
VCL_ENUM VENUM(martin) = "martin";
VCL_ENUM VENUM(miss) = "miss";
VCL_ENUM VENUM(mithrandir) = "mithrandir";
VCL_ENUM VENUM(one) = "one";
VCL_ENUM VENUM(phk) = "phk";
VCL_ENUM VENUM(slink) = "slink";
VCL_ENUM VENUM(three) = "three";
VCL_ENUM VENUM(two) = "two";

struct VPFX(debug_obj);
typedef VCL_VOID td_xyzzy_debug_obj__init(VRT_CTX,
    struct VPFX(debug_obj) **, const char *, VCL_STRING, VCL_ENUM);
typedef VCL_VOID td_xyzzy_debug_obj__fini(struct VPFX(
    debug_obj) **);
typedef VCL_VOID td_xyzzy_debug_obj_enum(VRT_CTX,
    struct VPFX(debug_obj) *, VCL_ENUM);
typedef VCL_STRING td_xyzzy_debug_obj_string(VRT_CTX,
    struct VPFX(debug_obj) *);
typedef VCL_STRING td_xyzzy_debug_obj_number(VRT_CTX,
    struct VPFX(debug_obj) *);
typedef VCL_STRING td_xyzzy_debug_obj_foo(VRT_CTX,
    struct VPFX(debug_obj) *, VCL_STRING);
typedef VCL_TIME td_xyzzy_debug_obj_date(VRT_CTX,
    struct VPFX(debug_obj) *);
typedef VCL_VOID td_xyzzy_debug_obj_test_priv_call(VRT_CTX,
    struct VPFX(debug_obj) *, struct vmod_priv *);
typedef VCL_VOID td_xyzzy_debug_obj_test_priv_vcl(VRT_CTX,
    struct VPFX(debug_obj) *, struct vmod_priv *);
typedef VCL_STRING td_xyzzy_debug_obj_test_priv_task(VRT_CTX,
    struct VPFX(debug_obj) *, struct vmod_priv *, VCL_STRING);
typedef VCL_STRING td_xyzzy_debug_obj_test_priv_top(VRT_CTX,
    struct VPFX(debug_obj) *, struct vmod_priv *, VCL_STRING);

struct VPFX(debug_dyn);
typedef VCL_VOID td_xyzzy_debug_dyn__init(VRT_CTX,
    struct VPFX(debug_dyn) **, const char *, VCL_STRING, VCL_STRING,
    VCL_PROBE);
typedef VCL_VOID td_xyzzy_debug_dyn__fini(struct VPFX(
    debug_dyn) **);
typedef VCL_BACKEND td_xyzzy_debug_dyn_backend(VRT_CTX,
    struct VPFX(debug_dyn) *);
typedef VCL_VOID td_xyzzy_debug_dyn_refresh(VRT_CTX,
    struct VPFX(debug_dyn) *, VCL_STRING, VCL_STRING, VCL_PROBE);

struct VPFX(debug_dyn_uds);
typedef VCL_VOID td_xyzzy_debug_dyn_uds__init(VRT_CTX,
    struct VPFX(debug_dyn_uds) **, const char *, VCL_STRING);
typedef VCL_VOID td_xyzzy_debug_dyn_uds__fini(struct VPFX(
    debug_dyn_uds) **);
typedef VCL_BACKEND td_xyzzy_debug_dyn_uds_backend(VRT_CTX,
    struct VPFX(debug_dyn_uds) *);
typedef VCL_VOID td_xyzzy_debug_dyn_uds_refresh(VRT_CTX,
    struct VPFX(debug_dyn_uds) *, VCL_STRING);

struct VPFX(debug_concat);
typedef VCL_VOID td_xyzzy_debug_concat__init(VRT_CTX,
    struct VPFX(debug_concat) **, const char *, VCL_STRANDS);
typedef VCL_VOID td_xyzzy_debug_concat__fini(struct VPFX(
    debug_concat) **);
typedef VCL_STRING td_xyzzy_debug_concat_get(VRT_CTX,
    struct VPFX(debug_concat) *);

struct VPFX(debug_obj_opt);
typedef VCL_VOID td_xyzzy_debug_obj_opt__init(VRT_CTX,
    struct VPFX(debug_obj_opt) **, const char *,
    struct VARGS(obj_opt__init)*);
typedef VCL_VOID td_xyzzy_debug_obj_opt__fini(struct VPFX(
    debug_obj_opt) **);
typedef VCL_STRING td_xyzzy_debug_obj_opt_meth_opt(VRT_CTX,
    struct VPFX(debug_obj_opt) *, struct VARGS(obj_opt_meth_opt)*);

struct VPFX(debug_director);
typedef VCL_VOID td_xyzzy_debug_director__init(VRT_CTX,
    struct VPFX(debug_director) **, const char *);
typedef VCL_VOID td_xyzzy_debug_director__fini(struct VPFX(
    debug_director) **);
typedef VCL_BACKEND td_xyzzy_debug_director_fail(VRT_CTX,
    struct VPFX(debug_director) *);

typedef VCL_STRING td_xyzzy_debug_author(VRT_CTX, VCL_ENUM,
    VCL_ENUM);
typedef VCL_VOID td_xyzzy_debug_test_priv_call(VRT_CTX,
    struct vmod_priv *);
typedef VCL_VOID td_xyzzy_debug_test_priv_vcl(VRT_CTX,
    struct vmod_priv *);
typedef VCL_STRING td_xyzzy_debug_test_priv_task(VRT_CTX,
    struct vmod_priv *, VCL_STRING);
typedef VCL_STRING td_xyzzy_debug_test_priv_top(VRT_CTX,
    struct vmod_priv *, VCL_STRING);
typedef VCL_VOID td_xyzzy_debug_rot52(VRT_CTX, VCL_HTTP);
typedef VCL_STRING td_xyzzy_debug_argtest(VRT_CTX,
    struct VARGS(argtest)*);
typedef VCL_INT td_xyzzy_debug_vre_limit(VRT_CTX);
typedef VCL_VOID td_xyzzy_debug_register_obj_events(VRT_CTX,
    struct vmod_priv *);
typedef VCL_VOID td_xyzzy_debug_fail(VRT_CTX);
typedef VCL_BOOL td_xyzzy_debug_fail2(VRT_CTX);
typedef VCL_VOID td_xyzzy_debug_vcl_discard_delay(VRT_CTX,
    struct vmod_priv *, VCL_DURATION);
typedef VCL_BOOL td_xyzzy_debug_match_acl(VRT_CTX, VCL_ACL,
    VCL_IP);
typedef VCL_VOID td_xyzzy_debug_test_probe(VRT_CTX, VCL_PROBE,
    VCL_PROBE);
typedef VCL_VOID td_xyzzy_debug_vsc_new(VRT_CTX);
typedef VCL_VOID td_xyzzy_debug_vsc_count(VRT_CTX, VCL_INT);
typedef VCL_VOID td_xyzzy_debug_vsc_destroy(VRT_CTX);
typedef VCL_STRING td_xyzzy_debug_concatenate(VRT_CTX,
    VCL_STRANDS);
typedef VCL_STRING td_xyzzy_debug_collect(VRT_CTX, VCL_STRANDS);
typedef VCL_VOID td_xyzzy_debug_sethdr(VRT_CTX, VCL_HEADER,
    VCL_STRANDS);
typedef VCL_DURATION td_xyzzy_debug_priv_perf(VRT_CTX, VCL_INT,
    VCL_INT);
typedef VCL_STRANDS td_xyzzy_debug_return_strands(VRT_CTX,
    VCL_STRANDS);
typedef VCL_VOID td_xyzzy_debug_catflap(VRT_CTX, VCL_ENUM);
typedef VCL_BYTES td_xyzzy_debug_stk(VRT_CTX);
typedef VCL_VOID td_xyzzy_debug_vcl_prevent_cold(VRT_CTX,
    struct vmod_priv *);
typedef VCL_VOID td_xyzzy_debug_vcl_allow_cold(VRT_CTX,
    struct vmod_priv *);
typedef VCL_VOID td_xyzzy_debug_cold_backend(VRT_CTX,
    struct vmod_priv *);
typedef VCL_VOID td_xyzzy_debug_cooling_backend(VRT_CTX,
    struct vmod_priv *);
typedef VCL_VOID td_xyzzy_debug_sndbuf(VRT_CTX, VCL_BYTES);
typedef VCL_VOID td_xyzzy_debug_store_ip(VRT_CTX, VCL_IP);
typedef VCL_IP td_xyzzy_debug_get_ip(VRT_CTX);
typedef VCL_STRING td_xyzzy_debug_client_ip(VRT_CTX);
typedef VCL_STRING td_xyzzy_debug_client_port(VRT_CTX);
typedef VCL_VOID td_xyzzy_debug_fail_rollback(VRT_CTX);
typedef VCL_VOID td_xyzzy_debug_ok_rollback(VRT_CTX);
typedef VCL_STRING td_xyzzy_debug_re_quote(VRT_CTX, VCL_STRING);
typedef VCL_STRING td_xyzzy_debug_priv_task_with_option(VRT_CTX,
    struct VARGS(priv_task_with_option)*);

struct Vmod_xyzzy_debug_Func {
	vmod_event_f			*_event;
	td_xyzzy_debug_author		*author;
	td_xyzzy_debug_test_priv_call	*test_priv_call;
	td_xyzzy_debug_test_priv_vcl	*test_priv_vcl;
	td_xyzzy_debug_test_priv_task	*test_priv_task;
	td_xyzzy_debug_test_priv_top	*test_priv_top;
	td_xyzzy_debug_obj__init	*obj__init;
	td_xyzzy_debug_obj__fini	*obj__fini;
	td_xyzzy_debug_obj_enum		*obj_enum;
	td_xyzzy_debug_obj_string	*obj_string;
	td_xyzzy_debug_obj_number	*obj_number;
	td_xyzzy_debug_obj_foo		*obj_foo;
	td_xyzzy_debug_obj_date		*obj_date;
	td_xyzzy_debug_obj_test_priv_call
					*obj_test_priv_call;
	td_xyzzy_debug_obj_test_priv_vcl	*obj_test_priv_vcl;
	td_xyzzy_debug_obj_test_priv_task
					*obj_test_priv_task;
	td_xyzzy_debug_obj_test_priv_top	*obj_test_priv_top;

	td_xyzzy_debug_rot52		*rot52;
	td_xyzzy_debug_argtest		*argtest;
	td_xyzzy_debug_vre_limit	*vre_limit;
	td_xyzzy_debug_register_obj_events
					*register_obj_events;
	td_xyzzy_debug_fail		*fail;
	td_xyzzy_debug_fail2		*fail2;
	td_xyzzy_debug_dyn__init	*dyn__init;
	td_xyzzy_debug_dyn__fini	*dyn__fini;
	td_xyzzy_debug_dyn_backend	*dyn_backend;
	td_xyzzy_debug_dyn_refresh	*dyn_refresh;

	td_xyzzy_debug_dyn_uds__init	*dyn_uds__init;
	td_xyzzy_debug_dyn_uds__fini	*dyn_uds__fini;
	td_xyzzy_debug_dyn_uds_backend	*dyn_uds_backend;
	td_xyzzy_debug_dyn_uds_refresh	*dyn_uds_refresh;

	td_xyzzy_debug_vcl_discard_delay	*vcl_discard_delay;
	td_xyzzy_debug_match_acl	*match_acl;
	td_xyzzy_debug_test_probe	*test_probe;
	td_xyzzy_debug_vsc_new		*vsc_new;
	td_xyzzy_debug_vsc_count	*vsc_count;
	td_xyzzy_debug_vsc_destroy	*vsc_destroy;
	td_xyzzy_debug_concat__init	*concat__init;
	td_xyzzy_debug_concat__fini	*concat__fini;
	td_xyzzy_debug_concat_get	*concat_get;

	td_xyzzy_debug_concatenate	*concatenate;
	td_xyzzy_debug_collect		*collect;
	td_xyzzy_debug_sethdr		*sethdr;
	td_xyzzy_debug_priv_perf	*priv_perf;
	td_xyzzy_debug_obj_opt__init	*obj_opt__init;
	td_xyzzy_debug_obj_opt__fini	*obj_opt__fini;
	td_xyzzy_debug_obj_opt_meth_opt	*obj_opt_meth_opt;

	td_xyzzy_debug_return_strands	*return_strands;
	td_xyzzy_debug_catflap		*catflap;
	td_xyzzy_debug_stk		*stk;
	td_xyzzy_debug_vcl_prevent_cold	*vcl_prevent_cold;
	td_xyzzy_debug_vcl_allow_cold	*vcl_allow_cold;
	td_xyzzy_debug_cold_backend	*cold_backend;
	td_xyzzy_debug_cooling_backend	*cooling_backend;
	td_xyzzy_debug_sndbuf		*sndbuf;
	td_xyzzy_debug_store_ip		*store_ip;
	td_xyzzy_debug_get_ip		*get_ip;
	td_xyzzy_debug_director__init	*director__init;
	td_xyzzy_debug_director__fini	*director__fini;
	td_xyzzy_debug_director_fail	*director_fail;

	td_xyzzy_debug_client_ip	*client_ip;
	td_xyzzy_debug_client_port	*client_port;
	td_xyzzy_debug_fail_rollback	*fail_rollback;
	td_xyzzy_debug_ok_rollback	*ok_rollback;
	td_xyzzy_debug_re_quote		*re_quote;
	td_xyzzy_debug_priv_task_with_option
					*priv_task_with_option;
	VCL_ENUM			*enum_des;
	VCL_ENUM			*enum_first;
	VCL_ENUM			*enum_geoff;
	VCL_ENUM			*enum_kristian;
	VCL_ENUM			*enum_last;
	VCL_ENUM			*enum_martin;
	VCL_ENUM			*enum_miss;
	VCL_ENUM			*enum_mithrandir;
	VCL_ENUM			*enum_one;
	VCL_ENUM			*enum_phk;
	VCL_ENUM			*enum_slink;
	VCL_ENUM			*enum_three;
	VCL_ENUM			*enum_two;
};

/*lint -esym(754, Vmod_xyzzy_debug_Func::*) */

static const struct Vmod_xyzzy_debug_Func Vmod_xyzzy_debug_Func = {
	._event =			xyzzy_event_function,
	.author =			xyzzy_author,
	.test_priv_call =		xyzzy_test_priv_call,
	.test_priv_vcl =		xyzzy_test_priv_vcl,
	.test_priv_task =		xyzzy_test_priv_task,
	.test_priv_top =		xyzzy_test_priv_top,
	.obj__init =			xyzzy_obj__init,
	.obj__fini =			xyzzy_obj__fini,
	.obj_enum =			xyzzy_obj_enum,
	.obj_string =			xyzzy_obj_string,
	.obj_number =			xyzzy_obj_number,
	.obj_foo =			xyzzy_obj_foo,
	.obj_date =			xyzzy_obj_date,
	.obj_test_priv_call =		xyzzy_obj_test_priv_call,
	.obj_test_priv_vcl =		xyzzy_obj_test_priv_vcl,
	.obj_test_priv_task =		xyzzy_obj_test_priv_task,
	.obj_test_priv_top =		xyzzy_obj_test_priv_top,

	.rot52 =			xyzzy_rot52,
	.argtest =			xyzzy_argtest,
	.vre_limit =			xyzzy_vre_limit,
	.register_obj_events =		xyzzy_register_obj_events,
	.fail =				xyzzy_fail,
	.fail2 =			xyzzy_fail2,
	.dyn__init =			xyzzy_dyn__init,
	.dyn__fini =			xyzzy_dyn__fini,
	.dyn_backend =			xyzzy_dyn_backend,
	.dyn_refresh =			xyzzy_dyn_refresh,

	.dyn_uds__init =		xyzzy_dyn_uds__init,
	.dyn_uds__fini =		xyzzy_dyn_uds__fini,
	.dyn_uds_backend =		xyzzy_dyn_uds_backend,
	.dyn_uds_refresh =		xyzzy_dyn_uds_refresh,

	.vcl_discard_delay =		xyzzy_vcl_discard_delay,
	.match_acl =			xyzzy_match_acl,
	.test_probe =			xyzzy_test_probe,
	.vsc_new =			xyzzy_vsc_new,
	.vsc_count =			xyzzy_vsc_count,
	.vsc_destroy =			xyzzy_vsc_destroy,
	.concat__init =			xyzzy_concat__init,
	.concat__fini =			xyzzy_concat__fini,
	.concat_get =			xyzzy_concat_get,

	.concatenate =			xyzzy_concatenate,
	.collect =			xyzzy_collect,
	.sethdr =			xyzzy_sethdr,
	.priv_perf =			xyzzy_priv_perf,
	.obj_opt__init =		xyzzy_obj_opt__init,
	.obj_opt__fini =		xyzzy_obj_opt__fini,
	.obj_opt_meth_opt =		xyzzy_obj_opt_meth_opt,

	.return_strands =		xyzzy_return_strands,
	.catflap =			xyzzy_catflap,
	.stk =				xyzzy_stk,
	.vcl_prevent_cold =		xyzzy_vcl_prevent_cold,
	.vcl_allow_cold =		xyzzy_vcl_allow_cold,
	.cold_backend =			xyzzy_cold_backend,
	.cooling_backend =		xyzzy_cooling_backend,
	.sndbuf =			xyzzy_sndbuf,
	.store_ip =			xyzzy_store_ip,
	.get_ip =			xyzzy_get_ip,
	.director__init =		xyzzy_director__init,
	.director__fini =		xyzzy_director__fini,
	.director_fail =		xyzzy_director_fail,

	.client_ip =			xyzzy_client_ip,
	.client_port =			xyzzy_client_port,
	.fail_rollback =		xyzzy_fail_rollback,
	.ok_rollback =			xyzzy_ok_rollback,
	.re_quote =			xyzzy_re_quote,
	.priv_task_with_option =	xyzzy_priv_task_with_option,

	.enum_des =			&VENUM(des),
	.enum_first =			&VENUM(first),
	.enum_geoff =			&VENUM(geoff),
	.enum_kristian =		&VENUM(kristian),
	.enum_last =			&VENUM(last),
	.enum_martin =			&VENUM(martin),
	.enum_miss =			&VENUM(miss),
	.enum_mithrandir =		&VENUM(mithrandir),
	.enum_one =			&VENUM(one),
	.enum_phk =			&VENUM(phk),
	.enum_slink =			&VENUM(slink),
	.enum_three =			&VENUM(three),
	.enum_two =			&VENUM(two),
};

static const char Vmod_Proto[] =
	"#define VPFX(a) xyzzy_##a\n"
	"#define VARGS(a) arg_xyzzy_debug_##a\n"
	"#define VENUM(a) enum_xyzzy_debug_##a\n"
	"//lint -esym(755, VPFX)\n"
	"//lint -esym(767, VPFX)\n"
	"//lint -esym(755, VARGS)\n"
	"//lint -esym(767, VARGS)\n"
	"//lint -esym(755, VENUM)\n"
	"//lint -esym(767, VENUM)\n"
	"//lint -esym(755, VARGS)\n"
	"//lint -esym(755, VENUM)\n"
	"\n"
	"struct VPFX(debug_obj);\n"
	"typedef VCL_VOID td_xyzzy_debug_obj__init(VRT_CTX,\n"
	"    struct VPFX(debug_obj) **, const char *, VCL_STRING, VCL_ENUM);\n"
	"typedef VCL_VOID td_xyzzy_debug_obj__fini(struct VPFX(\n"
	"    debug_obj) **);\n"
	"typedef VCL_VOID td_xyzzy_debug_obj_enum(VRT_CTX,\n"
	"    struct VPFX(debug_obj) *, VCL_ENUM);\n"
	"typedef VCL_STRING td_xyzzy_debug_obj_string(VRT_CTX,\n"
	"    struct VPFX(debug_obj) *);\n"
	"typedef VCL_STRING td_xyzzy_debug_obj_number(VRT_CTX,\n"
	"    struct VPFX(debug_obj) *);\n"
	"typedef VCL_STRING td_xyzzy_debug_obj_foo(VRT_CTX,\n"
	"    struct VPFX(debug_obj) *, VCL_STRING);\n"
	"typedef VCL_TIME td_xyzzy_debug_obj_date(VRT_CTX,\n"
	"    struct VPFX(debug_obj) *);\n"
	"typedef VCL_VOID td_xyzzy_debug_obj_test_priv_call(VRT_CTX,\n"
	"    struct VPFX(debug_obj) *, struct vmod_priv *);\n"
	"typedef VCL_VOID td_xyzzy_debug_obj_test_priv_vcl(VRT_CTX,\n"
	"    struct VPFX(debug_obj) *, struct vmod_priv *);\n"
	"typedef VCL_STRING td_xyzzy_debug_obj_test_priv_task(VRT_CTX,\n"
	"    struct VPFX(debug_obj) *, struct vmod_priv *, VCL_STRING);\n"
	"typedef VCL_STRING td_xyzzy_debug_obj_test_priv_top(VRT_CTX,\n"
	"    struct VPFX(debug_obj) *, struct vmod_priv *, VCL_STRING);\n"
	"\n"
	"struct VPFX(debug_dyn);\n"
	"typedef VCL_VOID td_xyzzy_debug_dyn__init(VRT_CTX,\n"
	"    struct VPFX(debug_dyn) **, const char *, VCL_STRING, VCL_STRING,\n"
	"    VCL_PROBE);\n"
	"typedef VCL_VOID td_xyzzy_debug_dyn__fini(struct VPFX(\n"
	"    debug_dyn) **);\n"
	"typedef VCL_BACKEND td_xyzzy_debug_dyn_backend(VRT_CTX,\n"
	"    struct VPFX(debug_dyn) *);\n"
	"typedef VCL_VOID td_xyzzy_debug_dyn_refresh(VRT_CTX,\n"
	"    struct VPFX(debug_dyn) *, VCL_STRING, VCL_STRING, VCL_PROBE);\n"
	"\n"
	"struct VPFX(debug_dyn_uds);\n"
	"typedef VCL_VOID td_xyzzy_debug_dyn_uds__init(VRT_CTX,\n"
	"    struct VPFX(debug_dyn_uds) **, const char *, VCL_STRING);\n"
	"typedef VCL_VOID td_xyzzy_debug_dyn_uds__fini(struct VPFX(\n"
	"    debug_dyn_uds) **);\n"
	"typedef VCL_BACKEND td_xyzzy_debug_dyn_uds_backend(VRT_CTX,\n"
	"    struct VPFX(debug_dyn_uds) *);\n"
	"typedef VCL_VOID td_xyzzy_debug_dyn_uds_refresh(VRT_CTX,\n"
	"    struct VPFX(debug_dyn_uds) *, VCL_STRING);\n"
	"\n"
	"struct VPFX(debug_concat);\n"
	"typedef VCL_VOID td_xyzzy_debug_concat__init(VRT_CTX,\n"
	"    struct VPFX(debug_concat) **, const char *, VCL_STRANDS);\n"
	"typedef VCL_VOID td_xyzzy_debug_concat__fini(struct VPFX(\n"
	"    debug_concat) **);\n"
	"typedef VCL_STRING td_xyzzy_debug_concat_get(VRT_CTX,\n"
	"    struct VPFX(debug_concat) *);\n"
	"\n"
	"struct VPFX(debug_obj_opt);\n"
	"\n"
	"struct VARGS(obj_opt__init) {\n"
	"	char			valid_s;\n"
	"	char			valid_b;\n"
	"	struct vmod_priv *	arg1;\n"
	"	struct vmod_priv *	arg2;\n"
	"	struct vmod_priv *	arg3;\n"
	"	VCL_STRING		s;\n"
	"	VCL_BOOL		b;\n"
	"};\n"
	"typedef VCL_VOID td_xyzzy_debug_obj_opt__init(VRT_CTX,\n"
	"    struct VPFX(debug_obj_opt) **, const char *,\n"
	"    struct VARGS(obj_opt__init)*);\n"
	"typedef VCL_VOID td_xyzzy_debug_obj_opt__fini(struct VPFX(\n"
	"    debug_obj_opt) **);\n"
	"\n"
	"struct VARGS(obj_opt_meth_opt) {\n"
	"	char			valid_s;\n"
	"	char			valid_b;\n"
	"	struct vmod_priv *	arg1;\n"
	"	struct vmod_priv *	arg2;\n"
	"	struct vmod_priv *	arg3;\n"
	"	VCL_STRING		s;\n"
	"	VCL_BOOL		b;\n"
	"};\n"
	"typedef VCL_STRING td_xyzzy_debug_obj_opt_meth_opt(VRT_CTX,\n"
	"    struct VPFX(debug_obj_opt) *, struct VARGS(obj_opt_meth_opt)*);\n"
	"\n"
	"struct VPFX(debug_director);\n"
	"typedef VCL_VOID td_xyzzy_debug_director__init(VRT_CTX,\n"
	"    struct VPFX(debug_director) **, const char *);\n"
	"typedef VCL_VOID td_xyzzy_debug_director__fini(struct VPFX(\n"
	"    debug_director) **);\n"
	"typedef VCL_BACKEND td_xyzzy_debug_director_fail(VRT_CTX,\n"
	"    struct VPFX(debug_director) *);\n"
	"\n"
	"/* Functions */\n"
	"typedef VCL_STRING td_xyzzy_debug_author(VRT_CTX, VCL_ENUM,\n"
	"    VCL_ENUM);\n"
	"typedef VCL_VOID td_xyzzy_debug_test_priv_call(VRT_CTX,\n"
	"    struct vmod_priv *);\n"
	"typedef VCL_VOID td_xyzzy_debug_test_priv_vcl(VRT_CTX,\n"
	"    struct vmod_priv *);\n"
	"typedef VCL_STRING td_xyzzy_debug_test_priv_task(VRT_CTX,\n"
	"    struct vmod_priv *, VCL_STRING);\n"
	"typedef VCL_STRING td_xyzzy_debug_test_priv_top(VRT_CTX,\n"
	"    struct vmod_priv *, VCL_STRING);\n"
	"typedef VCL_VOID td_xyzzy_debug_rot52(VRT_CTX, VCL_HTTP);\n"
	"\n"
	"struct VARGS(argtest) {\n"
	"	char			valid_opt;\n"
	"	VCL_STRING		one;\n"
	"	VCL_REAL		two;\n"
	"	VCL_STRING		three;\n"
	"	VCL_STRING		comma;\n"
	"	VCL_INT			four;\n"
	"	VCL_STRING		opt;\n"
	"};\n"
	"typedef VCL_STRING td_xyzzy_debug_argtest(VRT_CTX,\n"
	"    struct VARGS(argtest)*);\n"
	"typedef VCL_INT td_xyzzy_debug_vre_limit(VRT_CTX);\n"
	"typedef VCL_VOID td_xyzzy_debug_register_obj_events(VRT_CTX,\n"
	"    struct vmod_priv *);\n"
	"typedef VCL_VOID td_xyzzy_debug_fail(VRT_CTX);\n"
	"typedef VCL_BOOL td_xyzzy_debug_fail2(VRT_CTX);\n"
	"typedef VCL_VOID td_xyzzy_debug_vcl_discard_delay(VRT_CTX,\n"
	"    struct vmod_priv *, VCL_DURATION);\n"
	"typedef VCL_BOOL td_xyzzy_debug_match_acl(VRT_CTX, VCL_ACL,\n"
	"    VCL_IP);\n"
	"typedef VCL_VOID td_xyzzy_debug_test_probe(VRT_CTX, VCL_PROBE,\n"
	"    VCL_PROBE);\n"
	"typedef VCL_VOID td_xyzzy_debug_vsc_new(VRT_CTX);\n"
	"typedef VCL_VOID td_xyzzy_debug_vsc_count(VRT_CTX, VCL_INT);\n"
	"typedef VCL_VOID td_xyzzy_debug_vsc_destroy(VRT_CTX);\n"
	"typedef VCL_STRING td_xyzzy_debug_concatenate(VRT_CTX,\n"
	"    VCL_STRANDS);\n"
	"typedef VCL_STRING td_xyzzy_debug_collect(VRT_CTX, VCL_STRANDS);\n"
	"typedef VCL_VOID td_xyzzy_debug_sethdr(VRT_CTX, VCL_HEADER,\n"
	"    VCL_STRANDS);\n"
	"typedef VCL_DURATION td_xyzzy_debug_priv_perf(VRT_CTX, VCL_INT,\n"
	"    VCL_INT);\n"
	"typedef VCL_STRANDS td_xyzzy_debug_return_strands(VRT_CTX,\n"
	"    VCL_STRANDS);\n"
	"typedef VCL_VOID td_xyzzy_debug_catflap(VRT_CTX, VCL_ENUM);\n"
	"typedef VCL_BYTES td_xyzzy_debug_stk(VRT_CTX);\n"
	"typedef VCL_VOID td_xyzzy_debug_vcl_prevent_cold(VRT_CTX,\n"
	"    struct vmod_priv *);\n"
	"typedef VCL_VOID td_xyzzy_debug_vcl_allow_cold(VRT_CTX,\n"
	"    struct vmod_priv *);\n"
	"typedef VCL_VOID td_xyzzy_debug_cold_backend(VRT_CTX,\n"
	"    struct vmod_priv *);\n"
	"typedef VCL_VOID td_xyzzy_debug_cooling_backend(VRT_CTX,\n"
	"    struct vmod_priv *);\n"
	"typedef VCL_VOID td_xyzzy_debug_sndbuf(VRT_CTX, VCL_BYTES);\n"
	"typedef VCL_VOID td_xyzzy_debug_store_ip(VRT_CTX, VCL_IP);\n"
	"typedef VCL_IP td_xyzzy_debug_get_ip(VRT_CTX);\n"
	"typedef VCL_STRING td_xyzzy_debug_client_ip(VRT_CTX);\n"
	"typedef VCL_STRING td_xyzzy_debug_client_port(VRT_CTX);\n"
	"typedef VCL_VOID td_xyzzy_debug_fail_rollback(VRT_CTX);\n"
	"typedef VCL_VOID td_xyzzy_debug_ok_rollback(VRT_CTX);\n"
	"typedef VCL_STRING td_xyzzy_debug_re_quote(VRT_CTX, VCL_STRING);\n"
	"\n"
	"struct VARGS(priv_task_with_option) {\n"
	"	char			valid_opt;\n"
	"	struct vmod_priv *	priv;\n"
	"	VCL_STRING		opt;\n"
	"};\n"
	"typedef VCL_STRING td_xyzzy_debug_priv_task_with_option(VRT_CTX,\n"
	"    struct VARGS(priv_task_with_option)*);\n"
	"\n"
	"struct Vmod_xyzzy_debug_Func {\n"
	"	vmod_event_f			*_event;\n"
	"	td_xyzzy_debug_author		*author;\n"
	"	td_xyzzy_debug_test_priv_call	*test_priv_call;\n"
	"	td_xyzzy_debug_test_priv_vcl	*test_priv_vcl;\n"
	"	td_xyzzy_debug_test_priv_task	*test_priv_task;\n"
	"	td_xyzzy_debug_test_priv_top	*test_priv_top;\n"
	"	td_xyzzy_debug_obj__init	*obj__init;\n"
	"	td_xyzzy_debug_obj__fini	*obj__fini;\n"
	"	td_xyzzy_debug_obj_enum		*obj_enum;\n"
	"	td_xyzzy_debug_obj_string	*obj_string;\n"
	"	td_xyzzy_debug_obj_number	*obj_number;\n"
	"	td_xyzzy_debug_obj_foo		*obj_foo;\n"
	"	td_xyzzy_debug_obj_date		*obj_date;\n"
	"	td_xyzzy_debug_obj_test_priv_call\n"
	"					*obj_test_priv_call;\n"
	"	td_xyzzy_debug_obj_test_priv_vcl	*obj_test_priv_vcl;\n"
	"	td_xyzzy_debug_obj_test_priv_task\n"
	"					*obj_test_priv_task;\n"
	"	td_xyzzy_debug_obj_test_priv_top	*obj_test_priv_top;\n"
	"\n"
	"	td_xyzzy_debug_rot52		*rot52;\n"
	"	td_xyzzy_debug_argtest		*argtest;\n"
	"	td_xyzzy_debug_vre_limit	*vre_limit;\n"
	"	td_xyzzy_debug_register_obj_events\n"
	"					*register_obj_events;\n"
	"	td_xyzzy_debug_fail		*fail;\n"
	"	td_xyzzy_debug_fail2		*fail2;\n"
	"	td_xyzzy_debug_dyn__init	*dyn__init;\n"
	"	td_xyzzy_debug_dyn__fini	*dyn__fini;\n"
	"	td_xyzzy_debug_dyn_backend	*dyn_backend;\n"
	"	td_xyzzy_debug_dyn_refresh	*dyn_refresh;\n"
	"\n"
	"	td_xyzzy_debug_dyn_uds__init	*dyn_uds__init;\n"
	"	td_xyzzy_debug_dyn_uds__fini	*dyn_uds__fini;\n"
	"	td_xyzzy_debug_dyn_uds_backend	*dyn_uds_backend;\n"
	"	td_xyzzy_debug_dyn_uds_refresh	*dyn_uds_refresh;\n"
	"\n"
	"	td_xyzzy_debug_vcl_discard_delay	*vcl_discard_delay;\n"
	"	td_xyzzy_debug_match_acl	*match_acl;\n"
	"	td_xyzzy_debug_test_probe	*test_probe;\n"
	"	td_xyzzy_debug_vsc_new		*vsc_new;\n"
	"	td_xyzzy_debug_vsc_count	*vsc_count;\n"
	"	td_xyzzy_debug_vsc_destroy	*vsc_destroy;\n"
	"	td_xyzzy_debug_concat__init	*concat__init;\n"
	"	td_xyzzy_debug_concat__fini	*concat__fini;\n"
	"	td_xyzzy_debug_concat_get	*concat_get;\n"
	"\n"
	"	td_xyzzy_debug_concatenate	*concatenate;\n"
	"	td_xyzzy_debug_collect		*collect;\n"
	"	td_xyzzy_debug_sethdr		*sethdr;\n"
	"	td_xyzzy_debug_priv_perf	*priv_perf;\n"
	"	td_xyzzy_debug_obj_opt__init	*obj_opt__init;\n"
	"	td_xyzzy_debug_obj_opt__fini	*obj_opt__fini;\n"
	"	td_xyzzy_debug_obj_opt_meth_opt	*obj_opt_meth_opt;\n"
	"\n"
	"	td_xyzzy_debug_return_strands	*return_strands;\n"
	"	td_xyzzy_debug_catflap		*catflap;\n"
	"	td_xyzzy_debug_stk		*stk;\n"
	"	td_xyzzy_debug_vcl_prevent_cold	*vcl_prevent_cold;\n"
	"	td_xyzzy_debug_vcl_allow_cold	*vcl_allow_cold;\n"
	"	td_xyzzy_debug_cold_backend	*cold_backend;\n"
	"	td_xyzzy_debug_cooling_backend	*cooling_backend;\n"
	"	td_xyzzy_debug_sndbuf		*sndbuf;\n"
	"	td_xyzzy_debug_store_ip		*store_ip;\n"
	"	td_xyzzy_debug_get_ip		*get_ip;\n"
	"	td_xyzzy_debug_director__init	*director__init;\n"
	"	td_xyzzy_debug_director__fini	*director__fini;\n"
	"	td_xyzzy_debug_director_fail	*director_fail;\n"
	"\n"
	"	td_xyzzy_debug_client_ip	*client_ip;\n"
	"	td_xyzzy_debug_client_port	*client_port;\n"
	"	td_xyzzy_debug_fail_rollback	*fail_rollback;\n"
	"	td_xyzzy_debug_ok_rollback	*ok_rollback;\n"
	"	td_xyzzy_debug_re_quote		*re_quote;\n"
	"	td_xyzzy_debug_priv_task_with_option\n"
	"					*priv_task_with_option;\n"
	"	VCL_ENUM			*enum_des;\n"
	"	VCL_ENUM			*enum_first;\n"
	"	VCL_ENUM			*enum_geoff;\n"
	"	VCL_ENUM			*enum_kristian;\n"
	"	VCL_ENUM			*enum_last;\n"
	"	VCL_ENUM			*enum_martin;\n"
	"	VCL_ENUM			*enum_miss;\n"
	"	VCL_ENUM			*enum_mithrandir;\n"
	"	VCL_ENUM			*enum_one;\n"
	"	VCL_ENUM			*enum_phk;\n"
	"	VCL_ENUM			*enum_slink;\n"
	"	VCL_ENUM			*enum_three;\n"
	"	VCL_ENUM			*enum_two;\n"
	"};\n"
	"#undef VPFX\n"
	"#undef VARGS\n"
	"#undef VENUM\n"
	"static struct Vmod_xyzzy_debug_Func Vmod_xyzzy_debug_Func;";

static const char Vmod_Json[] = {
	"[ "
	"  [ "
	"    \"$VMOD\", "
	"    \"1.0\" "
	"  ], "
	"  [ "
	"    \"$EVENT\", "
	"    \"Vmod_xyzzy_debug_Func._event\" "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"author\", "
	"    [ "
	"      [ "
	"        \"STRING\" "
	"      ], "
	"      \"Vmod_xyzzy_debug_Func.author\", "
	"      \"\", "
	"      [ "
	"        \"ENUM\", "
	"        \"person\", "
	"        \"phk\", "
	"        [ "
	"          \"phk\", "
	"          \"des\", "
	"          \"kristian\", "
	"          \"mithrandir\" "
	"        ] "
	"      ], "
	"      [ "
	"        \"ENUM\", "
	"        \"someone\", "
	"        \"phk\", "
	"        [ "
	"          \"phk\", "
	"          \"slink\", "
	"          \"geoff\" "
	"        ] "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"test_priv_call\", "
	"    [ "
	"      [ "
	"        \"VOID\" "
	"      ], "
	"      \"Vmod_xyzzy_debug_Func.test_priv_call\", "
	"      \"\", "
	"      [ "
	"        \"PRIV_CALL\" "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"test_priv_vcl\", "
	"    [ "
	"      [ "
	"        \"VOID\" "
	"      ], "
	"      \"Vmod_xyzzy_debug_Func.test_priv_vcl\", "
	"      \"\", "
	"      [ "
	"        \"PRIV_VCL\" "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"test_priv_task\", "
	"    [ "
	"      [ "
	"        \"STRING\" "
	"      ], "
	"      \"Vmod_xyzzy_debug_Func.test_priv_task\", "
	"      \"\", "
	"      [ "
	"        \"PRIV_TASK\" "
	"      ], "
	"      [ "
	"        \"STRING\", "
	"        \"s\", "
	"        \"\\\"\\\"\" "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"test_priv_top\", "
	"    [ "
	"      [ "
	"        \"STRING\" "
	"      ], "
	"      \"Vmod_xyzzy_debug_Func.test_priv_top\", "
	"      \"\", "
	"      [ "
	"        \"PRIV_TOP\" "
	"      ], "
	"      [ "
	"        \"STRING\" "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$OBJ\", "
	"    \"obj\", "
	"    { "
	"      \"NULL_OK\": false "
	"    }, "
	"    \"struct xyzzy_debug_obj\", "
	"    [ "
	"      \"$INIT\", "
	"      [ "
	"        [ "
	"          \"VOID\" "
	"        ], "
	"        \"Vmod_xyzzy_debug_Func.obj__init\", "
	"        \"\", "
	"        [ "
	"          \"STRING\", "
	"          \"string\", "
	"          \"\\\"default\\\"\" "
	"        ], "
	"        [ "
	"          \"ENUM\", "
	"          \"number\", "
	"          \"one\", "
	"          [ "
	"            \"one\", "
	"            \"two\", "
	"            \"three\" "
	"          ] "
	"        ] "
	"      ] "
	"    ], "
	"    [ "
	"      \"$FINI\", "
	"      [ "
	"        [ "
	"          \"VOID\" "
	"        ], "
	"        \"Vmod_xyzzy_debug_Func.obj__fini\", "
	"        \"\" "
	"      ] "
	"    ], "
	"    [ "
	"      \"$METHOD\", "
	"      \"enum\", "
	"      [ "
	"        [ "
	"          \"VOID\" "
	"        ], "
	"        \"Vmod_xyzzy_debug_Func.obj_enum\", "
	"        \"\", "
	"        [ "
	"          \"ENUM\", "
	"          null, "
	"          null, "
	"          [ "
	"            \"phk\", "
	"            \"des\", "
	"            \"kristian\", "
	"            \"mithrandir\", "
	"            \"martin\" "
	"          ] "
	"        ] "
	"      ] "
	"    ], "
	"    [ "
	"      \"$METHOD\", "
	"      \"string\", "
	"      [ "
	"        [ "
	"          \"STRING\" "
	"        ], "
	"        \"Vmod_xyzzy_debug_Func.obj_string\", "
	"        \"\" "
	"      ] "
	"    ], "
	"    [ "
	"      \"$METHOD\", "
	"      \"number\", "
	"      [ "
	"        [ "
	"          \"STRING\" "
	"        ], "
	"        \"Vmod_xyzzy_debug_Func.obj_number\", "
	"        \"\" "
	"      ] "
	"    ], "
	"    [ "
	"      \"$METHOD\", "
	"      \"foo\", "
	"      [ "
	"        [ "
	"          \"STRING\" "
	"        ], "
	"        \"Vmod_xyzzy_debug_Func.obj_foo\", "
	"        \"\", "
	"        [ "
	"          \"STRING\", "
	"          \"why\" "
	"        ] "
	"      ] "
	"    ], "
	"    [ "
	"      \"$METHOD\", "
	"      \"date\", "
	"      [ "
	"        [ "
	"          \"TIME\" "
	"        ], "
	"        \"Vmod_xyzzy_debug_Func.obj_date\", "
	"        \"\" "
	"      ] "
	"    ], "
	"    [ "
	"      \"$METHOD\", "
	"      \"test_priv_call\", "
	"      [ "
	"        [ "
	"          \"VOID\" "
	"        ], "
	"        \"Vmod_xyzzy_debug_Func.obj_test_priv_call\", "
	"        \"\", "
	"        [ "
	"          \"PRIV_CALL\" "
	"        ] "
	"      ] "
	"    ], "
	"    [ "
	"      \"$METHOD\", "
	"      \"test_priv_vcl\", "
	"      [ "
	"        [ "
	"          \"VOID\" "
	"        ], "
	"        \"Vmod_xyzzy_debug_Func.obj_test_priv_vcl\", "
	"        \"\", "
	"        [ "
	"          \"PRIV_VCL\" "
	"        ] "
	"      ] "
	"    ], "
	"    [ "
	"      \"$METHOD\", "
	"      \"test_priv_task\", "
	"      [ "
	"        [ "
	"          \"STRING\" "
	"        ], "
	"        \"Vmod_xyzzy_debug_Func.obj_test_priv_task\", "
	"        \"\", "
	"        [ "
	"          \"PRIV_TASK\" "
	"        ], "
	"        [ "
	"          \"STRING\", "
	"          \"s\", "
	"          \"\\\"\\\"\" "
	"        ] "
	"      ] "
	"    ], "
	"    [ "
	"      \"$METHOD\", "
	"      \"test_priv_top\", "
	"      [ "
	"        [ "
	"          \"STRING\" "
	"        ], "
	"        \"Vmod_xyzzy_debug_Func.obj_test_priv_top\", "
	"        \"\", "
	"        [ "
	"          \"PRIV_TOP\" "
	"        ], "
	"        [ "
	"          \"STRING\" "
	"        ] "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"rot52\", "
	"    [ "
	"      [ "
	"        \"VOID\" "
	"      ], "
	"      \"Vmod_xyzzy_debug_Func.rot52\", "
	"      \"\", "
	"      [ "
	"        \"HTTP\", "
	"        \"hdr\" "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"argtest\", "
	"    [ "
	"      [ "
	"        \"STRING\" "
	"      ], "
	"      \"Vmod_xyzzy_debug_Func.argtest\", "
	"      \"struct arg_xyzzy_debug_argtest\", "
	"      [ "
	"        \"STRING\", "
	"        \"one\" "
	"      ], "
	"      [ "
	"        \"REAL\", "
	"        \"two\", "
	"        \"2\" "
	"      ], "
	"      [ "
	"        \"STRING\", "
	"        \"three\", "
	"        \"\\\"3\\\"\" "
	"      ], "
	"      [ "
	"        \"STRING\", "
	"        \"comma\", "
	"        \"\\\",\\\"\" "
	"      ], "
	"      [ "
	"        \"INT\", "
	"        \"four\", "
	"        \"4\" "
	"      ], "
	"      [ "
	"        \"STRING\", "
	"        \"opt\", "
	"        null, "
	"        null, "
	"        true "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"vre_limit\", "
	"    [ "
	"      [ "
	"        \"INT\" "
	"      ], "
	"      \"Vmod_xyzzy_debug_Func.vre_limit\", "
	"      \"\" "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"register_obj_events\", "
	"    [ "
	"      [ "
	"        \"VOID\" "
	"      ], "
	"      \"Vmod_xyzzy_debug_Func.register_obj_events\", "
	"      \"\", "
	"      [ "
	"        \"PRIV_VCL\" "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"fail\", "
	"    [ "
	"      [ "
	"        \"VOID\" "
	"      ], "
	"      \"Vmod_xyzzy_debug_Func.fail\", "
	"      \"\" "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"fail2\", "
	"    [ "
	"      [ "
	"        \"BOOL\" "
	"      ], "
	"      \"Vmod_xyzzy_debug_Func.fail2\", "
	"      \"\" "
	"    ] "
	"  ], "
	"  [ "
	"    \"$OBJ\", "
	"    \"dyn\", "
	"    { "
	"      \"NULL_OK\": false "
	"    }, "
	"    \"struct xyzzy_debug_dyn\", "
	"    [ "
	"      \"$INIT\", "
	"      [ "
	"        [ "
	"          \"VOID\" "
	"        ], "
	"        \"Vmod_xyzzy_debug_Func.dyn__init\", "
	"        \"\", "
	"        [ "
	"          \"STRING\", "
	"          \"addr\" "
	"        ], "
	"        [ "
	"          \"STRING\", "
	"          \"port\" "
	"        ], "
	"        [ "
	"          \"PROBE\", "
	"          \"probe\", "
	"          \"0\" "
	"        ] "
	"      ] "
	"    ], "
	"    [ "
	"      \"$FINI\", "
	"      [ "
	"        [ "
	"          \"VOID\" "
	"        ], "
	"        \"Vmod_xyzzy_debug_Func.dyn__fini\", "
	"        \"\" "
	"      ] "
	"    ], "
	"    [ "
	"      \"$METHOD\", "
	"      \"backend\", "
	"      [ "
	"        [ "
	"          \"BACKEND\" "
	"        ], "
	"        \"Vmod_xyzzy_debug_Func.dyn_backend\", "
	"        \"\" "
	"      ] "
	"    ], "
	"    [ "
	"      \"$METHOD\", "
	"      \"refresh\", "
	"      [ "
	"        [ "
	"          \"VOID\" "
	"        ], "
	"        \"Vmod_xyzzy_debug_Func.dyn_refresh\", "
	"        \"\", "
	"        [ "
	"          \"STRING\", "
	"          \"addr\" "
	"        ], "
	"        [ "
	"          \"STRING\", "
	"          \"port\" "
	"        ], "
	"        [ "
	"          \"PROBE\", "
	"          \"probe\", "
	"          \"0\" "
	"        ] "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$OBJ\", "
	"    \"dyn_uds\", "
	"    { "
	"      \"NULL_OK\": false "
	"    }, "
	"    \"struct xyzzy_debug_dyn_uds\", "
	"    [ "
	"      \"$INIT\", "
	"      [ "
	"        [ "
	"          \"VOID\" "
	"        ], "
	"        \"Vmod_xyzzy_debug_Func.dyn_uds__init\", "
	"        \"\", "
	"        [ "
	"          \"STRING\", "
	"          \"path\" "
	"        ] "
	"      ] "
	"    ], "
	"    [ "
	"      \"$FINI\", "
	"      [ "
	"        [ "
	"          \"VOID\" "
	"        ], "
	"        \"Vmod_xyzzy_debug_Func.dyn_uds__fini\", "
	"        \"\" "
	"      ] "
	"    ], "
	"    [ "
	"      \"$METHOD\", "
	"      \"backend\", "
	"      [ "
	"        [ "
	"          \"BACKEND\" "
	"        ], "
	"        \"Vmod_xyzzy_debug_Func.dyn_uds_backend\", "
	"        \"\" "
	"      ] "
	"    ], "
	"    [ "
	"      \"$METHOD\", "
	"      \"refresh\", "
	"      [ "
	"        [ "
	"          \"VOID\" "
	"        ], "
	"        \"Vmod_xyzzy_debug_Func.dyn_uds_refresh\", "
	"        \"\", "
	"        [ "
	"          \"STRING\", "
	"          \"path\" "
	"        ] "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"vcl_discard_delay\", "
	"    [ "
	"      [ "
	"        \"VOID\" "
	"      ], "
	"      \"Vmod_xyzzy_debug_Func.vcl_discard_delay\", "
	"      \"\", "
	"      [ "
	"        \"PRIV_VCL\" "
	"      ], "
	"      [ "
	"        \"DURATION\" "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"match_acl\", "
	"    [ "
	"      [ "
	"        \"BOOL\" "
	"      ], "
	"      \"Vmod_xyzzy_debug_Func.match_acl\", "
	"      \"\", "
	"      [ "
	"        \"ACL\", "
	"        \"acl\" "
	"      ], "
	"      [ "
	"        \"IP\", "
	"        \"ip\" "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"test_probe\", "
	"    [ "
	"      [ "
	"        \"VOID\" "
	"      ], "
	"      \"Vmod_xyzzy_debug_Func.test_probe\", "
	"      \"\", "
	"      [ "
	"        \"PROBE\", "
	"        \"probe\" "
	"      ], "
	"      [ "
	"        \"PROBE\", "
	"        \"same\", "
	"        \"0\" "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"vsc_new\", "
	"    [ "
	"      [ "
	"        \"VOID\" "
	"      ], "
	"      \"Vmod_xyzzy_debug_Func.vsc_new\", "
	"      \"\" "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"vsc_count\", "
	"    [ "
	"      [ "
	"        \"VOID\" "
	"      ], "
	"      \"Vmod_xyzzy_debug_Func.vsc_count\", "
	"      \"\", "
	"      [ "
	"        \"INT\", "
	"        \"val\", "
	"        \"1\" "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"vsc_destroy\", "
	"    [ "
	"      [ "
	"        \"VOID\" "
	"      ], "
	"      \"Vmod_xyzzy_debug_Func.vsc_destroy\", "
	"      \"\" "
	"    ] "
	"  ], "
	"  [ "
	"    \"$OBJ\", "
	"    \"concat\", "
	"    { "
	"      \"NULL_OK\": false "
	"    }, "
	"    \"struct xyzzy_debug_concat\", "
	"    [ "
	"      \"$INIT\", "
	"      [ "
	"        [ "
	"          \"VOID\" "
	"        ], "
	"        \"Vmod_xyzzy_debug_Func.concat__init\", "
	"        \"\", "
	"        [ "
	"          \"STRANDS\" "
	"        ] "
	"      ] "
	"    ], "
	"    [ "
	"      \"$FINI\", "
	"      [ "
	"        [ "
	"          \"VOID\" "
	"        ], "
	"        \"Vmod_xyzzy_debug_Func.concat__fini\", "
	"        \"\" "
	"      ] "
	"    ], "
	"    [ "
	"      \"$METHOD\", "
	"      \"get\", "
	"      [ "
	"        [ "
	"          \"STRING\" "
	"        ], "
	"        \"Vmod_xyzzy_debug_Func.concat_get\", "
	"        \"\" "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"concatenate\", "
	"    [ "
	"      [ "
	"        \"STRING\" "
	"      ], "
	"      \"Vmod_xyzzy_debug_Func.concatenate\", "
	"      \"\", "
	"      [ "
	"        \"STRANDS\" "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"collect\", "
	"    [ "
	"      [ "
	"        \"STRING\" "
	"      ], "
	"      \"Vmod_xyzzy_debug_Func.collect\", "
	"      \"\", "
	"      [ "
	"        \"STRANDS\" "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"sethdr\", "
	"    [ "
	"      [ "
	"        \"VOID\" "
	"      ], "
	"      \"Vmod_xyzzy_debug_Func.sethdr\", "
	"      \"\", "
	"      [ "
	"        \"HEADER\" "
	"      ], "
	"      [ "
	"        \"STRANDS\" "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"priv_perf\", "
	"    [ "
	"      [ "
	"        \"DURATION\" "
	"      ], "
	"      \"Vmod_xyzzy_debug_Func.priv_perf\", "
	"      \"\", "
	"      [ "
	"        \"INT\", "
	"        \"size\" "
	"      ], "
	"      [ "
	"        \"INT\", "
	"        \"rounds\", "
	"        \"10000\" "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$OBJ\", "
	"    \"obj_opt\", "
	"    { "
	"      \"NULL_OK\": true "
	"    }, "
	"    \"struct xyzzy_debug_obj_opt\", "
	"    [ "
	"      \"$INIT\", "
	"      [ "
	"        [ "
	"          \"VOID\" "
	"        ], "
	"        \"Vmod_xyzzy_debug_Func.obj_opt__init\", "
	"        \"struct arg_xyzzy_debug_obj_opt__init\", "
	"        [ "
	"          \"PRIV_CALL\" "
	"        ], "
	"        [ "
	"          \"PRIV_VCL\" "
	"        ], "
	"        [ "
	"          \"PRIV_TASK\" "
	"        ], "
	"        [ "
	"          \"STRING\", "
	"          \"s\", "
	"          null, "
	"          null, "
	"          true "
	"        ], "
	"        [ "
	"          \"BOOL\", "
	"          \"b\", "
	"          null, "
	"          null, "
	"          true "
	"        ] "
	"      ] "
	"    ], "
	"    [ "
	"      \"$FINI\", "
	"      [ "
	"        [ "
	"          \"VOID\" "
	"        ], "
	"        \"Vmod_xyzzy_debug_Func.obj_opt__fini\", "
	"        \"\" "
	"      ] "
	"    ], "
	"    [ "
	"      \"$METHOD\", "
	"      \"meth_opt\", "
	"      [ "
	"        [ "
	"          \"STRING\" "
	"        ], "
	"        \"Vmod_xyzzy_debug_Func.obj_opt_meth_opt\", "
	"        \"struct arg_xyzzy_debug_obj_opt_meth_opt\", "
	"        [ "
	"          \"PRIV_CALL\" "
	"        ], "
	"        [ "
	"          \"PRIV_VCL\" "
	"        ], "
	"        [ "
	"          \"PRIV_TASK\" "
	"        ], "
	"        [ "
	"          \"STRING\", "
	"          \"s\", "
	"          null, "
	"          null, "
	"          true "
	"        ], "
	"        [ "
	"          \"BOOL\", "
	"          \"b\", "
	"          null, "
	"          null, "
	"          true "
	"        ] "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"return_strands\", "
	"    [ "
	"      [ "
	"        \"STRANDS\" "
	"      ], "
	"      \"Vmod_xyzzy_debug_Func.return_strands\", "
	"      \"\", "
	"      [ "
	"        \"STRANDS\", "
	"        \"strand\" "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"catflap\", "
	"    [ "
	"      [ "
	"        \"VOID\" "
	"      ], "
	"      \"Vmod_xyzzy_debug_Func.catflap\", "
	"      \"\", "
	"      [ "
	"        \"ENUM\", "
	"        \"type\", "
	"        null, "
	"        [ "
	"          \"miss\", "
	"          \"first\", "
	"          \"last\" "
	"        ] "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"stk\", "
	"    [ "
	"      [ "
	"        \"BYTES\" "
	"      ], "
	"      \"Vmod_xyzzy_debug_Func.stk\", "
	"      \"\" "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"vcl_prevent_cold\", "
	"    [ "
	"      [ "
	"        \"VOID\" "
	"      ], "
	"      \"Vmod_xyzzy_debug_Func.vcl_prevent_cold\", "
	"      \"\", "
	"      [ "
	"        \"PRIV_VCL\" "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"vcl_allow_cold\", "
	"    [ "
	"      [ "
	"        \"VOID\" "
	"      ], "
	"      \"Vmod_xyzzy_debug_Func.vcl_allow_cold\", "
	"      \"\", "
	"      [ "
	"        \"PRIV_VCL\" "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"cold_backend\", "
	"    [ "
	"      [ "
	"        \"VOID\" "
	"      ], "
	"      \"Vmod_xyzzy_debug_Func.cold_backend\", "
	"      \"\", "
	"      [ "
	"        \"PRIV_VCL\" "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"cooling_backend\", "
	"    [ "
	"      [ "
	"        \"VOID\" "
	"      ], "
	"      \"Vmod_xyzzy_debug_Func.cooling_backend\", "
	"      \"\", "
	"      [ "
	"        \"PRIV_VCL\" "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"sndbuf\", "
	"    [ "
	"      [ "
	"        \"VOID\" "
	"      ], "
	"      \"Vmod_xyzzy_debug_Func.sndbuf\", "
	"      \"\", "
	"      [ "
	"        \"BYTES\", "
	"        \"sndbuf\" "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"store_ip\", "
	"    [ "
	"      [ "
	"        \"VOID\" "
	"      ], "
	"      \"Vmod_xyzzy_debug_Func.store_ip\", "
	"      \"\", "
	"      [ "
	"        \"IP\" "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"get_ip\", "
	"    [ "
	"      [ "
	"        \"IP\" "
	"      ], "
	"      \"Vmod_xyzzy_debug_Func.get_ip\", "
	"      \"\" "
	"    ] "
	"  ], "
	"  [ "
	"    \"$OBJ\", "
	"    \"director\", "
	"    { "
	"      \"NULL_OK\": false "
	"    }, "
	"    \"struct xyzzy_debug_director\", "
	"    [ "
	"      \"$INIT\", "
	"      [ "
	"        [ "
	"          \"VOID\" "
	"        ], "
	"        \"Vmod_xyzzy_debug_Func.director__init\", "
	"        \"\" "
	"      ] "
	"    ], "
	"    [ "
	"      \"$FINI\", "
	"      [ "
	"        [ "
	"          \"VOID\" "
	"        ], "
	"        \"Vmod_xyzzy_debug_Func.director__fini\", "
	"        \"\" "
	"      ] "
	"    ], "
	"    [ "
	"      \"$METHOD\", "
	"      \"fail\", "
	"      [ "
	"        [ "
	"          \"BACKEND\" "
	"        ], "
	"        \"Vmod_xyzzy_debug_Func.director_fail\", "
	"        \"\" "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"client_ip\", "
	"    [ "
	"      [ "
	"        \"STRING\" "
	"      ], "
	"      \"Vmod_xyzzy_debug_Func.client_ip\", "
	"      \"\" "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"client_port\", "
	"    [ "
	"      [ "
	"        \"STRING\" "
	"      ], "
	"      \"Vmod_xyzzy_debug_Func.client_port\", "
	"      \"\" "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"fail_rollback\", "
	"    [ "
	"      [ "
	"        \"VOID\" "
	"      ], "
	"      \"Vmod_xyzzy_debug_Func.fail_rollback\", "
	"      \"\" "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"ok_rollback\", "
	"    [ "
	"      [ "
	"        \"VOID\" "
	"      ], "
	"      \"Vmod_xyzzy_debug_Func.ok_rollback\", "
	"      \"\" "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"re_quote\", "
	"    [ "
	"      [ "
	"        \"STRING\" "
	"      ], "
	"      \"Vmod_xyzzy_debug_Func.re_quote\", "
	"      \"\", "
	"      [ "
	"        \"STRING\" "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"priv_task_with_option\", "
	"    [ "
	"      [ "
	"        \"STRING\" "
	"      ], "
	"      \"Vmod_xyzzy_debug_Func.priv_task_with_option\", "
	"      \"struct arg_xyzzy_debug_priv_task_with_option\", "
	"      [ "
	"        \"PRIV_TASK\", "
	"        \"priv\" "
	"      ], "
	"      [ "
	"        \"STRING\", "
	"        \"opt\", "
	"        null, "
	"        null, "
	"        true "
	"      ] "
	"    ] "
	"  ] "
	"]\n"
};

/*lint -esym(714, Vmod_debug_Data) */
/*lint -esym(759, Vmod_debug_Data) */
/*lint -esym(765, Vmod_debug_Data) */

extern const struct vmod_data Vmod_debug_Data;

const struct vmod_data Vmod_debug_Data = {
	.vrt_major =	0,
	.vrt_minor =	0,
	.name =		"debug",
	.func =		&Vmod_xyzzy_debug_Func,
	.func_len =	sizeof(Vmod_xyzzy_debug_Func),
	.func_name =	"Vmod_xyzzy_debug_Func",
	.proto =	Vmod_Proto,
	.json =		Vmod_Json,
	.abi =		VMOD_ABI_Version,
	.file_id =	"8b71ec32183afbb3785d66d57b5fcc4c04acc688f7a848f8abd1f71f78422c70",
};
