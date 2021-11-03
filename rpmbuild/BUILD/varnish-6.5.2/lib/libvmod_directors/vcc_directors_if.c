/*
 * NB:  This file is machine generated, DO NOT EDIT!
 *
 * Edit ./vmod_directors.vcc and run make instead
 */

#include "config.h"
#include <stdio.h>
#include "vdef.h"
#include "vrt.h"
#include "vcc_directors_if.h"
#include "vmod_abi.h"

VCL_ENUM VENUM(ALL) = "ALL";
VCL_ENUM VENUM(BLOB) = "BLOB";
VCL_ENUM VENUM(CHOSEN) = "CHOSEN";
VCL_ENUM VENUM(HASH) = "HASH";
VCL_ENUM VENUM(IGNORE) = "IGNORE";
VCL_ENUM VENUM(KEY) = "KEY";
VCL_ENUM VENUM(LAZY) = "LAZY";
VCL_ENUM VENUM(NOW) = "NOW";
VCL_ENUM VENUM(URL) = "URL";

struct VPFX(directors_round_robin);
typedef VCL_VOID td_vmod_directors_round_robin__init(VRT_CTX,
    struct VPFX(directors_round_robin) **, const char *);
typedef VCL_VOID td_vmod_directors_round_robin__fini(
    struct VPFX(directors_round_robin) **);
typedef VCL_VOID td_vmod_directors_round_robin_add_backend(
    VRT_CTX, struct VPFX(directors_round_robin) *, VCL_BACKEND);
typedef VCL_VOID td_vmod_directors_round_robin_remove_backend(
    VRT_CTX, struct VPFX(directors_round_robin) *, VCL_BACKEND);
typedef VCL_BACKEND td_vmod_directors_round_robin_backend(
    VRT_CTX, struct VPFX(directors_round_robin) *);

struct VPFX(directors_fallback);
typedef VCL_VOID td_vmod_directors_fallback__init(VRT_CTX,
    struct VPFX(directors_fallback) **, const char *, VCL_BOOL);
typedef VCL_VOID td_vmod_directors_fallback__fini(struct VPFX(
    directors_fallback) **);
typedef VCL_VOID td_vmod_directors_fallback_add_backend(VRT_CTX,
    struct VPFX(directors_fallback) *, VCL_BACKEND);
typedef VCL_VOID td_vmod_directors_fallback_remove_backend(
    VRT_CTX, struct VPFX(directors_fallback) *, VCL_BACKEND);
typedef VCL_BACKEND td_vmod_directors_fallback_backend(VRT_CTX,
    struct VPFX(directors_fallback) *);

struct VPFX(directors_random);
typedef VCL_VOID td_vmod_directors_random__init(VRT_CTX,
    struct VPFX(directors_random) **, const char *);
typedef VCL_VOID td_vmod_directors_random__fini(struct VPFX(
    directors_random) **);
typedef VCL_VOID td_vmod_directors_random_add_backend(VRT_CTX,
    struct VPFX(directors_random) *, VCL_BACKEND, VCL_REAL);
typedef VCL_VOID td_vmod_directors_random_remove_backend(
    VRT_CTX, struct VPFX(directors_random) *, VCL_BACKEND);
typedef VCL_BACKEND td_vmod_directors_random_backend(VRT_CTX,
    struct VPFX(directors_random) *);

struct VPFX(directors_hash);
typedef VCL_VOID td_vmod_directors_hash__init(VRT_CTX,
    struct VPFX(directors_hash) **, const char *);
typedef VCL_VOID td_vmod_directors_hash__fini(struct VPFX(
    directors_hash) **);
typedef VCL_VOID td_vmod_directors_hash_add_backend(VRT_CTX,
    struct VPFX(directors_hash) *, VCL_BACKEND, VCL_REAL);
typedef VCL_VOID td_vmod_directors_hash_remove_backend(VRT_CTX,
    struct VPFX(directors_hash) *, VCL_BACKEND);
typedef VCL_BACKEND td_vmod_directors_hash_backend(VRT_CTX,
    struct VPFX(directors_hash) *, VCL_STRANDS);

struct VPFX(directors_shard);
typedef VCL_VOID td_vmod_directors_shard__init(VRT_CTX,
    struct VPFX(directors_shard) **, const char *);
typedef VCL_VOID td_vmod_directors_shard__fini(struct VPFX(
    directors_shard) **);
typedef VCL_VOID td_vmod_directors_shard_set_warmup(VRT_CTX,
    struct VPFX(directors_shard) *, VCL_REAL);
typedef VCL_VOID td_vmod_directors_shard_set_rampup(VRT_CTX,
    struct VPFX(directors_shard) *, VCL_DURATION);
typedef VCL_VOID td_vmod_directors_shard_associate(VRT_CTX,
    struct VPFX(directors_shard) *, VCL_BLOB);
typedef VCL_BOOL td_vmod_directors_shard_add_backend(VRT_CTX,
    struct VPFX(directors_shard) *,
    struct VARGS(shard_add_backend)*);
typedef VCL_BOOL td_vmod_directors_shard_remove_backend(VRT_CTX,
    struct VPFX(directors_shard) *,
    struct VARGS(shard_remove_backend)*);
typedef VCL_BOOL td_vmod_directors_shard_clear(VRT_CTX,
    struct VPFX(directors_shard) *, struct vmod_priv *);
typedef VCL_BOOL td_vmod_directors_shard_reconfigure(VRT_CTX,
    struct VPFX(directors_shard) *, struct vmod_priv *, VCL_INT);
typedef VCL_INT td_vmod_directors_shard_key(VRT_CTX,
    struct VPFX(directors_shard) *, VCL_STRANDS);
typedef VCL_BACKEND td_vmod_directors_shard_backend(VRT_CTX,
    struct VPFX(directors_shard) *, struct VARGS(shard_backend)*);
typedef VCL_VOID td_vmod_directors_shard_debug(VRT_CTX,
    struct VPFX(directors_shard) *, VCL_INT);

struct VPFX(directors_shard_param);
typedef VCL_VOID td_vmod_directors_shard_param__init(VRT_CTX,
    struct VPFX(directors_shard_param) **, const char *);
typedef VCL_VOID td_vmod_directors_shard_param__fini(
    struct VPFX(directors_shard_param) **);
typedef VCL_VOID td_vmod_directors_shard_param_clear(VRT_CTX,
    struct VPFX(directors_shard_param) *);
typedef VCL_VOID td_vmod_directors_shard_param_set(VRT_CTX,
    struct VPFX(directors_shard_param) *,
    struct VARGS(shard_param_set)*);
typedef VCL_STRING td_vmod_directors_shard_param_get_by(VRT_CTX,
    struct VPFX(directors_shard_param) *);
typedef VCL_INT td_vmod_directors_shard_param_get_key(VRT_CTX,
    struct VPFX(directors_shard_param) *);
typedef VCL_INT td_vmod_directors_shard_param_get_alt(VRT_CTX,
    struct VPFX(directors_shard_param) *);
typedef VCL_REAL td_vmod_directors_shard_param_get_warmup(
    VRT_CTX, struct VPFX(directors_shard_param) *);
typedef VCL_BOOL td_vmod_directors_shard_param_get_rampup(
    VRT_CTX, struct VPFX(directors_shard_param) *);
typedef VCL_STRING td_vmod_directors_shard_param_get_healthy(
    VRT_CTX, struct VPFX(directors_shard_param) *);
typedef VCL_BLOB td_vmod_directors_shard_param_use(VRT_CTX,
    struct VPFX(directors_shard_param) *);

typedef VCL_BACKEND td_vmod_directors_lookup(VRT_CTX,
    VCL_STRING);

struct Vmod_vmod_directors_Func {
	td_vmod_directors_round_robin__init
					*round_robin__init;
	td_vmod_directors_round_robin__fini
					*round_robin__fini;
	td_vmod_directors_round_robin_add_backend
					*round_robin_add_backend;
	td_vmod_directors_round_robin_remove_backend
					*round_robin_remove_backend;
	td_vmod_directors_round_robin_backend
					*round_robin_backend;

	td_vmod_directors_fallback__init	*fallback__init;
	td_vmod_directors_fallback__fini	*fallback__fini;
	td_vmod_directors_fallback_add_backend
					*fallback_add_backend;
	td_vmod_directors_fallback_remove_backend
					*fallback_remove_backend;
	td_vmod_directors_fallback_backend
					*fallback_backend;

	td_vmod_directors_random__init	*random__init;
	td_vmod_directors_random__fini	*random__fini;
	td_vmod_directors_random_add_backend
					*random_add_backend;
	td_vmod_directors_random_remove_backend
					*random_remove_backend;
	td_vmod_directors_random_backend	*random_backend;

	td_vmod_directors_hash__init	*hash__init;
	td_vmod_directors_hash__fini	*hash__fini;
	td_vmod_directors_hash_add_backend
					*hash_add_backend;
	td_vmod_directors_hash_remove_backend
					*hash_remove_backend;
	td_vmod_directors_hash_backend	*hash_backend;

	td_vmod_directors_shard__init	*shard__init;
	td_vmod_directors_shard__fini	*shard__fini;
	td_vmod_directors_shard_set_warmup
					*shard_set_warmup;
	td_vmod_directors_shard_set_rampup
					*shard_set_rampup;
	td_vmod_directors_shard_associate
					*shard_associate;
	td_vmod_directors_shard_add_backend
					*shard_add_backend;
	td_vmod_directors_shard_remove_backend
					*shard_remove_backend;
	td_vmod_directors_shard_clear	*shard_clear;
	td_vmod_directors_shard_reconfigure
					*shard_reconfigure;
	td_vmod_directors_shard_key	*shard_key;
	td_vmod_directors_shard_backend	*shard_backend;
	td_vmod_directors_shard_debug	*shard_debug;

	td_vmod_directors_shard_param__init
					*shard_param__init;
	td_vmod_directors_shard_param__fini
					*shard_param__fini;
	td_vmod_directors_shard_param_clear
					*shard_param_clear;
	td_vmod_directors_shard_param_set
					*shard_param_set;
	td_vmod_directors_shard_param_get_by
					*shard_param_get_by;
	td_vmod_directors_shard_param_get_key
					*shard_param_get_key;
	td_vmod_directors_shard_param_get_alt
					*shard_param_get_alt;
	td_vmod_directors_shard_param_get_warmup
					*shard_param_get_warmup;
	td_vmod_directors_shard_param_get_rampup
					*shard_param_get_rampup;
	td_vmod_directors_shard_param_get_healthy
					*shard_param_get_healthy;
	td_vmod_directors_shard_param_use
					*shard_param_use;

	td_vmod_directors_lookup	*lookup;
	VCL_ENUM			*enum_ALL;
	VCL_ENUM			*enum_BLOB;
	VCL_ENUM			*enum_CHOSEN;
	VCL_ENUM			*enum_HASH;
	VCL_ENUM			*enum_IGNORE;
	VCL_ENUM			*enum_KEY;
	VCL_ENUM			*enum_LAZY;
	VCL_ENUM			*enum_NOW;
	VCL_ENUM			*enum_URL;
};

/*lint -esym(754, Vmod_vmod_directors_Func::*) */

static const struct Vmod_vmod_directors_Func Vmod_vmod_directors_Func = {
	.round_robin__init =		vmod_round_robin__init,
	.round_robin__fini =		vmod_round_robin__fini,
	.round_robin_add_backend =	vmod_round_robin_add_backend,
	.round_robin_remove_backend =	vmod_round_robin_remove_backend,
	.round_robin_backend =		vmod_round_robin_backend,

	.fallback__init =		vmod_fallback__init,
	.fallback__fini =		vmod_fallback__fini,
	.fallback_add_backend =		vmod_fallback_add_backend,
	.fallback_remove_backend =	vmod_fallback_remove_backend,
	.fallback_backend =		vmod_fallback_backend,

	.random__init =			vmod_random__init,
	.random__fini =			vmod_random__fini,
	.random_add_backend =		vmod_random_add_backend,
	.random_remove_backend =	vmod_random_remove_backend,
	.random_backend =		vmod_random_backend,

	.hash__init =			vmod_hash__init,
	.hash__fini =			vmod_hash__fini,
	.hash_add_backend =		vmod_hash_add_backend,
	.hash_remove_backend =		vmod_hash_remove_backend,
	.hash_backend =			vmod_hash_backend,

	.shard__init =			vmod_shard__init,
	.shard__fini =			vmod_shard__fini,
	.shard_set_warmup =		vmod_shard_set_warmup,
	.shard_set_rampup =		vmod_shard_set_rampup,
	.shard_associate =		vmod_shard_associate,
	.shard_add_backend =		vmod_shard_add_backend,
	.shard_remove_backend =		vmod_shard_remove_backend,
	.shard_clear =			vmod_shard_clear,
	.shard_reconfigure =		vmod_shard_reconfigure,
	.shard_key =			vmod_shard_key,
	.shard_backend =		vmod_shard_backend,
	.shard_debug =			vmod_shard_debug,

	.shard_param__init =		vmod_shard_param__init,
	.shard_param__fini =		vmod_shard_param__fini,
	.shard_param_clear =		vmod_shard_param_clear,
	.shard_param_set =		vmod_shard_param_set,
	.shard_param_get_by =		vmod_shard_param_get_by,
	.shard_param_get_key =		vmod_shard_param_get_key,
	.shard_param_get_alt =		vmod_shard_param_get_alt,
	.shard_param_get_warmup =	vmod_shard_param_get_warmup,
	.shard_param_get_rampup =	vmod_shard_param_get_rampup,
	.shard_param_get_healthy =	vmod_shard_param_get_healthy,
	.shard_param_use =		vmod_shard_param_use,

	.lookup =			vmod_lookup,

	.enum_ALL =			&VENUM(ALL),
	.enum_BLOB =			&VENUM(BLOB),
	.enum_CHOSEN =			&VENUM(CHOSEN),
	.enum_HASH =			&VENUM(HASH),
	.enum_IGNORE =			&VENUM(IGNORE),
	.enum_KEY =			&VENUM(KEY),
	.enum_LAZY =			&VENUM(LAZY),
	.enum_NOW =			&VENUM(NOW),
	.enum_URL =			&VENUM(URL),
};

static const char Vmod_Proto[] =
	"#define VPFX(a) vmod_##a\n"
	"#define VARGS(a) arg_vmod_directors_##a\n"
	"#define VENUM(a) enum_vmod_directors_##a\n"
	"//lint -esym(755, VPFX)\n"
	"//lint -esym(767, VPFX)\n"
	"//lint -esym(755, VARGS)\n"
	"//lint -esym(767, VARGS)\n"
	"//lint -esym(755, VENUM)\n"
	"//lint -esym(767, VENUM)\n"
	"//lint -esym(755, VARGS)\n"
	"//lint -esym(755, VENUM)\n"
	"\n"
	"struct VPFX(directors_round_robin);\n"
	"typedef VCL_VOID td_vmod_directors_round_robin__init(VRT_CTX,\n"
	"    struct VPFX(directors_round_robin) **, const char *);\n"
	"typedef VCL_VOID td_vmod_directors_round_robin__fini(\n"
	"    struct VPFX(directors_round_robin) **);\n"
	"typedef VCL_VOID td_vmod_directors_round_robin_add_backend(\n"
	"    VRT_CTX, struct VPFX(directors_round_robin) *, VCL_BACKEND);\n"
	"typedef VCL_VOID td_vmod_directors_round_robin_remove_backend(\n"
	"    VRT_CTX, struct VPFX(directors_round_robin) *, VCL_BACKEND);\n"
	"typedef VCL_BACKEND td_vmod_directors_round_robin_backend(\n"
	"    VRT_CTX, struct VPFX(directors_round_robin) *);\n"
	"\n"
	"struct VPFX(directors_fallback);\n"
	"typedef VCL_VOID td_vmod_directors_fallback__init(VRT_CTX,\n"
	"    struct VPFX(directors_fallback) **, const char *, VCL_BOOL);\n"
	"typedef VCL_VOID td_vmod_directors_fallback__fini(struct VPFX(\n"
	"    directors_fallback) **);\n"
	"typedef VCL_VOID td_vmod_directors_fallback_add_backend(VRT_CTX,\n"
	"    struct VPFX(directors_fallback) *, VCL_BACKEND);\n"
	"typedef VCL_VOID td_vmod_directors_fallback_remove_backend(\n"
	"    VRT_CTX, struct VPFX(directors_fallback) *, VCL_BACKEND);\n"
	"typedef VCL_BACKEND td_vmod_directors_fallback_backend(VRT_CTX,\n"
	"    struct VPFX(directors_fallback) *);\n"
	"\n"
	"struct VPFX(directors_random);\n"
	"typedef VCL_VOID td_vmod_directors_random__init(VRT_CTX,\n"
	"    struct VPFX(directors_random) **, const char *);\n"
	"typedef VCL_VOID td_vmod_directors_random__fini(struct VPFX(\n"
	"    directors_random) **);\n"
	"typedef VCL_VOID td_vmod_directors_random_add_backend(VRT_CTX,\n"
	"    struct VPFX(directors_random) *, VCL_BACKEND, VCL_REAL);\n"
	"typedef VCL_VOID td_vmod_directors_random_remove_backend(\n"
	"    VRT_CTX, struct VPFX(directors_random) *, VCL_BACKEND);\n"
	"typedef VCL_BACKEND td_vmod_directors_random_backend(VRT_CTX,\n"
	"    struct VPFX(directors_random) *);\n"
	"\n"
	"struct VPFX(directors_hash);\n"
	"typedef VCL_VOID td_vmod_directors_hash__init(VRT_CTX,\n"
	"    struct VPFX(directors_hash) **, const char *);\n"
	"typedef VCL_VOID td_vmod_directors_hash__fini(struct VPFX(\n"
	"    directors_hash) **);\n"
	"typedef VCL_VOID td_vmod_directors_hash_add_backend(VRT_CTX,\n"
	"    struct VPFX(directors_hash) *, VCL_BACKEND, VCL_REAL);\n"
	"typedef VCL_VOID td_vmod_directors_hash_remove_backend(VRT_CTX,\n"
	"    struct VPFX(directors_hash) *, VCL_BACKEND);\n"
	"typedef VCL_BACKEND td_vmod_directors_hash_backend(VRT_CTX,\n"
	"    struct VPFX(directors_hash) *, VCL_STRANDS);\n"
	"\n"
	"struct VPFX(directors_shard);\n"
	"typedef VCL_VOID td_vmod_directors_shard__init(VRT_CTX,\n"
	"    struct VPFX(directors_shard) **, const char *);\n"
	"typedef VCL_VOID td_vmod_directors_shard__fini(struct VPFX(\n"
	"    directors_shard) **);\n"
	"typedef VCL_VOID td_vmod_directors_shard_set_warmup(VRT_CTX,\n"
	"    struct VPFX(directors_shard) *, VCL_REAL);\n"
	"typedef VCL_VOID td_vmod_directors_shard_set_rampup(VRT_CTX,\n"
	"    struct VPFX(directors_shard) *, VCL_DURATION);\n"
	"typedef VCL_VOID td_vmod_directors_shard_associate(VRT_CTX,\n"
	"    struct VPFX(directors_shard) *, VCL_BLOB);\n"
	"\n"
	"struct VARGS(shard_add_backend) {\n"
	"	char			valid_ident;\n"
	"	char			valid_rampup;\n"
	"	char			valid_weight;\n"
	"	struct vmod_priv *	arg1;\n"
	"	VCL_BACKEND		backend;\n"
	"	VCL_STRING		ident;\n"
	"	VCL_DURATION		rampup;\n"
	"	VCL_REAL		weight;\n"
	"};\n"
	"typedef VCL_BOOL td_vmod_directors_shard_add_backend(VRT_CTX,\n"
	"    struct VPFX(directors_shard) *,\n"
	"    struct VARGS(shard_add_backend)*);\n"
	"\n"
	"struct VARGS(shard_remove_backend) {\n"
	"	char			valid_backend;\n"
	"	char			valid_ident;\n"
	"	struct vmod_priv *	arg1;\n"
	"	VCL_BACKEND		backend;\n"
	"	VCL_STRING		ident;\n"
	"};\n"
	"typedef VCL_BOOL td_vmod_directors_shard_remove_backend(VRT_CTX,\n"
	"    struct VPFX(directors_shard) *,\n"
	"    struct VARGS(shard_remove_backend)*);\n"
	"typedef VCL_BOOL td_vmod_directors_shard_clear(VRT_CTX,\n"
	"    struct VPFX(directors_shard) *, struct vmod_priv *);\n"
	"typedef VCL_BOOL td_vmod_directors_shard_reconfigure(VRT_CTX,\n"
	"    struct VPFX(directors_shard) *, struct vmod_priv *, VCL_INT);\n"
	"typedef VCL_INT td_vmod_directors_shard_key(VRT_CTX,\n"
	"    struct VPFX(directors_shard) *, VCL_STRANDS);\n"
	"\n"
	"struct VARGS(shard_backend) {\n"
	"	char			valid_by;\n"
	"	char			valid_key;\n"
	"	char			valid_key_blob;\n"
	"	char			valid_alt;\n"
	"	char			valid_warmup;\n"
	"	char			valid_rampup;\n"
	"	char			valid_healthy;\n"
	"	char			valid_param;\n"
	"	char			valid_resolve;\n"
	"	VCL_ENUM		by;\n"
	"	VCL_INT			key;\n"
	"	VCL_BLOB		key_blob;\n"
	"	VCL_INT			alt;\n"
	"	VCL_REAL		warmup;\n"
	"	VCL_BOOL		rampup;\n"
	"	VCL_ENUM		healthy;\n"
	"	VCL_BLOB		param;\n"
	"	VCL_ENUM		resolve;\n"
	"};\n"
	"typedef VCL_BACKEND td_vmod_directors_shard_backend(VRT_CTX,\n"
	"    struct VPFX(directors_shard) *, struct VARGS(shard_backend)*);\n"
	"typedef VCL_VOID td_vmod_directors_shard_debug(VRT_CTX,\n"
	"    struct VPFX(directors_shard) *, VCL_INT);\n"
	"\n"
	"struct VPFX(directors_shard_param);\n"
	"typedef VCL_VOID td_vmod_directors_shard_param__init(VRT_CTX,\n"
	"    struct VPFX(directors_shard_param) **, const char *);\n"
	"typedef VCL_VOID td_vmod_directors_shard_param__fini(\n"
	"    struct VPFX(directors_shard_param) **);\n"
	"typedef VCL_VOID td_vmod_directors_shard_param_clear(VRT_CTX,\n"
	"    struct VPFX(directors_shard_param) *);\n"
	"\n"
	"struct VARGS(shard_param_set) {\n"
	"	char			valid_by;\n"
	"	char			valid_key;\n"
	"	char			valid_key_blob;\n"
	"	char			valid_alt;\n"
	"	char			valid_warmup;\n"
	"	char			valid_rampup;\n"
	"	char			valid_healthy;\n"
	"	VCL_ENUM		by;\n"
	"	VCL_INT			key;\n"
	"	VCL_BLOB		key_blob;\n"
	"	VCL_INT			alt;\n"
	"	VCL_REAL		warmup;\n"
	"	VCL_BOOL		rampup;\n"
	"	VCL_ENUM		healthy;\n"
	"};\n"
	"typedef VCL_VOID td_vmod_directors_shard_param_set(VRT_CTX,\n"
	"    struct VPFX(directors_shard_param) *,\n"
	"    struct VARGS(shard_param_set)*);\n"
	"typedef VCL_STRING td_vmod_directors_shard_param_get_by(VRT_CTX,\n"
	"    struct VPFX(directors_shard_param) *);\n"
	"typedef VCL_INT td_vmod_directors_shard_param_get_key(VRT_CTX,\n"
	"    struct VPFX(directors_shard_param) *);\n"
	"typedef VCL_INT td_vmod_directors_shard_param_get_alt(VRT_CTX,\n"
	"    struct VPFX(directors_shard_param) *);\n"
	"typedef VCL_REAL td_vmod_directors_shard_param_get_warmup(\n"
	"    VRT_CTX, struct VPFX(directors_shard_param) *);\n"
	"typedef VCL_BOOL td_vmod_directors_shard_param_get_rampup(\n"
	"    VRT_CTX, struct VPFX(directors_shard_param) *);\n"
	"typedef VCL_STRING td_vmod_directors_shard_param_get_healthy(\n"
	"    VRT_CTX, struct VPFX(directors_shard_param) *);\n"
	"typedef VCL_BLOB td_vmod_directors_shard_param_use(VRT_CTX,\n"
	"    struct VPFX(directors_shard_param) *);\n"
	"\n"
	"/* Functions */\n"
	"typedef VCL_BACKEND td_vmod_directors_lookup(VRT_CTX,\n"
	"    VCL_STRING);\n"
	"\n"
	"struct Vmod_vmod_directors_Func {\n"
	"	td_vmod_directors_round_robin__init\n"
	"					*round_robin__init;\n"
	"	td_vmod_directors_round_robin__fini\n"
	"					*round_robin__fini;\n"
	"	td_vmod_directors_round_robin_add_backend\n"
	"					*round_robin_add_backend;\n"
	"	td_vmod_directors_round_robin_remove_backend\n"
	"					*round_robin_remove_backend;\n"
	"	td_vmod_directors_round_robin_backend\n"
	"					*round_robin_backend;\n"
	"\n"
	"	td_vmod_directors_fallback__init	*fallback__init;\n"
	"	td_vmod_directors_fallback__fini	*fallback__fini;\n"
	"	td_vmod_directors_fallback_add_backend\n"
	"					*fallback_add_backend;\n"
	"	td_vmod_directors_fallback_remove_backend\n"
	"					*fallback_remove_backend;\n"
	"	td_vmod_directors_fallback_backend\n"
	"					*fallback_backend;\n"
	"\n"
	"	td_vmod_directors_random__init	*random__init;\n"
	"	td_vmod_directors_random__fini	*random__fini;\n"
	"	td_vmod_directors_random_add_backend\n"
	"					*random_add_backend;\n"
	"	td_vmod_directors_random_remove_backend\n"
	"					*random_remove_backend;\n"
	"	td_vmod_directors_random_backend	*random_backend;\n"
	"\n"
	"	td_vmod_directors_hash__init	*hash__init;\n"
	"	td_vmod_directors_hash__fini	*hash__fini;\n"
	"	td_vmod_directors_hash_add_backend\n"
	"					*hash_add_backend;\n"
	"	td_vmod_directors_hash_remove_backend\n"
	"					*hash_remove_backend;\n"
	"	td_vmod_directors_hash_backend	*hash_backend;\n"
	"\n"
	"	td_vmod_directors_shard__init	*shard__init;\n"
	"	td_vmod_directors_shard__fini	*shard__fini;\n"
	"	td_vmod_directors_shard_set_warmup\n"
	"					*shard_set_warmup;\n"
	"	td_vmod_directors_shard_set_rampup\n"
	"					*shard_set_rampup;\n"
	"	td_vmod_directors_shard_associate\n"
	"					*shard_associate;\n"
	"	td_vmod_directors_shard_add_backend\n"
	"					*shard_add_backend;\n"
	"	td_vmod_directors_shard_remove_backend\n"
	"					*shard_remove_backend;\n"
	"	td_vmod_directors_shard_clear	*shard_clear;\n"
	"	td_vmod_directors_shard_reconfigure\n"
	"					*shard_reconfigure;\n"
	"	td_vmod_directors_shard_key	*shard_key;\n"
	"	td_vmod_directors_shard_backend	*shard_backend;\n"
	"	td_vmod_directors_shard_debug	*shard_debug;\n"
	"\n"
	"	td_vmod_directors_shard_param__init\n"
	"					*shard_param__init;\n"
	"	td_vmod_directors_shard_param__fini\n"
	"					*shard_param__fini;\n"
	"	td_vmod_directors_shard_param_clear\n"
	"					*shard_param_clear;\n"
	"	td_vmod_directors_shard_param_set\n"
	"					*shard_param_set;\n"
	"	td_vmod_directors_shard_param_get_by\n"
	"					*shard_param_get_by;\n"
	"	td_vmod_directors_shard_param_get_key\n"
	"					*shard_param_get_key;\n"
	"	td_vmod_directors_shard_param_get_alt\n"
	"					*shard_param_get_alt;\n"
	"	td_vmod_directors_shard_param_get_warmup\n"
	"					*shard_param_get_warmup;\n"
	"	td_vmod_directors_shard_param_get_rampup\n"
	"					*shard_param_get_rampup;\n"
	"	td_vmod_directors_shard_param_get_healthy\n"
	"					*shard_param_get_healthy;\n"
	"	td_vmod_directors_shard_param_use\n"
	"					*shard_param_use;\n"
	"\n"
	"	td_vmod_directors_lookup	*lookup;\n"
	"	VCL_ENUM			*enum_ALL;\n"
	"	VCL_ENUM			*enum_BLOB;\n"
	"	VCL_ENUM			*enum_CHOSEN;\n"
	"	VCL_ENUM			*enum_HASH;\n"
	"	VCL_ENUM			*enum_IGNORE;\n"
	"	VCL_ENUM			*enum_KEY;\n"
	"	VCL_ENUM			*enum_LAZY;\n"
	"	VCL_ENUM			*enum_NOW;\n"
	"	VCL_ENUM			*enum_URL;\n"
	"};\n"
	"#undef VPFX\n"
	"#undef VARGS\n"
	"#undef VENUM\n"
	"static struct Vmod_vmod_directors_Func Vmod_vmod_directors_Func;";

static const char Vmod_Json[] = {
	"[ "
	"  [ "
	"    \"$VMOD\", "
	"    \"1.0\" "
	"  ], "
	"  [ "
	"    \"$OBJ\", "
	"    \"round_robin\", "
	"    { "
	"      \"NULL_OK\": false "
	"    }, "
	"    \"struct vmod_directors_round_robin\", "
	"    [ "
	"      \"$INIT\", "
	"      [ "
	"        [ "
	"          \"VOID\" "
	"        ], "
	"        \"Vmod_vmod_directors_Func.round_robin__init\", "
	"        \"\" "
	"      ] "
	"    ], "
	"    [ "
	"      \"$FINI\", "
	"      [ "
	"        [ "
	"          \"VOID\" "
	"        ], "
	"        \"Vmod_vmod_directors_Func.round_robin__fini\", "
	"        \"\" "
	"      ] "
	"    ], "
	"    [ "
	"      \"$METHOD\", "
	"      \"add_backend\", "
	"      [ "
	"        [ "
	"          \"VOID\" "
	"        ], "
	"        \"Vmod_vmod_directors_Func.round_robin_add_backend\", "
	"        \"\", "
	"        [ "
	"          \"BACKEND\" "
	"        ] "
	"      ] "
	"    ], "
	"    [ "
	"      \"$METHOD\", "
	"      \"remove_backend\", "
	"      [ "
	"        [ "
	"          \"VOID\" "
	"        ], "
	"        \"Vmod_vmod_directors_Func.round_robin_remove_backend\", "
	"        \"\", "
	"        [ "
	"          \"BACKEND\" "
	"        ] "
	"      ] "
	"    ], "
	"    [ "
	"      \"$METHOD\", "
	"      \"backend\", "
	"      [ "
	"        [ "
	"          \"BACKEND\" "
	"        ], "
	"        \"Vmod_vmod_directors_Func.round_robin_backend\", "
	"        \"\" "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$OBJ\", "
	"    \"fallback\", "
	"    { "
	"      \"NULL_OK\": false "
	"    }, "
	"    \"struct vmod_directors_fallback\", "
	"    [ "
	"      \"$INIT\", "
	"      [ "
	"        [ "
	"          \"VOID\" "
	"        ], "
	"        \"Vmod_vmod_directors_Func.fallback__init\", "
	"        \"\", "
	"        [ "
	"          \"BOOL\", "
	"          \"sticky\", "
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
	"        \"Vmod_vmod_directors_Func.fallback__fini\", "
	"        \"\" "
	"      ] "
	"    ], "
	"    [ "
	"      \"$METHOD\", "
	"      \"add_backend\", "
	"      [ "
	"        [ "
	"          \"VOID\" "
	"        ], "
	"        \"Vmod_vmod_directors_Func.fallback_add_backend\", "
	"        \"\", "
	"        [ "
	"          \"BACKEND\" "
	"        ] "
	"      ] "
	"    ], "
	"    [ "
	"      \"$METHOD\", "
	"      \"remove_backend\", "
	"      [ "
	"        [ "
	"          \"VOID\" "
	"        ], "
	"        \"Vmod_vmod_directors_Func.fallback_remove_backend\", "
	"        \"\", "
	"        [ "
	"          \"BACKEND\" "
	"        ] "
	"      ] "
	"    ], "
	"    [ "
	"      \"$METHOD\", "
	"      \"backend\", "
	"      [ "
	"        [ "
	"          \"BACKEND\" "
	"        ], "
	"        \"Vmod_vmod_directors_Func.fallback_backend\", "
	"        \"\" "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$OBJ\", "
	"    \"random\", "
	"    { "
	"      \"NULL_OK\": false "
	"    }, "
	"    \"struct vmod_directors_random\", "
	"    [ "
	"      \"$INIT\", "
	"      [ "
	"        [ "
	"          \"VOID\" "
	"        ], "
	"        \"Vmod_vmod_directors_Func.random__init\", "
	"        \"\" "
	"      ] "
	"    ], "
	"    [ "
	"      \"$FINI\", "
	"      [ "
	"        [ "
	"          \"VOID\" "
	"        ], "
	"        \"Vmod_vmod_directors_Func.random__fini\", "
	"        \"\" "
	"      ] "
	"    ], "
	"    [ "
	"      \"$METHOD\", "
	"      \"add_backend\", "
	"      [ "
	"        [ "
	"          \"VOID\" "
	"        ], "
	"        \"Vmod_vmod_directors_Func.random_add_backend\", "
	"        \"\", "
	"        [ "
	"          \"BACKEND\" "
	"        ], "
	"        [ "
	"          \"REAL\" "
	"        ] "
	"      ] "
	"    ], "
	"    [ "
	"      \"$METHOD\", "
	"      \"remove_backend\", "
	"      [ "
	"        [ "
	"          \"VOID\" "
	"        ], "
	"        \"Vmod_vmod_directors_Func.random_remove_backend\", "
	"        \"\", "
	"        [ "
	"          \"BACKEND\" "
	"        ] "
	"      ] "
	"    ], "
	"    [ "
	"      \"$METHOD\", "
	"      \"backend\", "
	"      [ "
	"        [ "
	"          \"BACKEND\" "
	"        ], "
	"        \"Vmod_vmod_directors_Func.random_backend\", "
	"        \"\" "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$OBJ\", "
	"    \"hash\", "
	"    { "
	"      \"NULL_OK\": false "
	"    }, "
	"    \"struct vmod_directors_hash\", "
	"    [ "
	"      \"$INIT\", "
	"      [ "
	"        [ "
	"          \"VOID\" "
	"        ], "
	"        \"Vmod_vmod_directors_Func.hash__init\", "
	"        \"\" "
	"      ] "
	"    ], "
	"    [ "
	"      \"$FINI\", "
	"      [ "
	"        [ "
	"          \"VOID\" "
	"        ], "
	"        \"Vmod_vmod_directors_Func.hash__fini\", "
	"        \"\" "
	"      ] "
	"    ], "
	"    [ "
	"      \"$METHOD\", "
	"      \"add_backend\", "
	"      [ "
	"        [ "
	"          \"VOID\" "
	"        ], "
	"        \"Vmod_vmod_directors_Func.hash_add_backend\", "
	"        \"\", "
	"        [ "
	"          \"BACKEND\" "
	"        ], "
	"        [ "
	"          \"REAL\" "
	"        ] "
	"      ] "
	"    ], "
	"    [ "
	"      \"$METHOD\", "
	"      \"remove_backend\", "
	"      [ "
	"        [ "
	"          \"VOID\" "
	"        ], "
	"        \"Vmod_vmod_directors_Func.hash_remove_backend\", "
	"        \"\", "
	"        [ "
	"          \"BACKEND\" "
	"        ] "
	"      ] "
	"    ], "
	"    [ "
	"      \"$METHOD\", "
	"      \"backend\", "
	"      [ "
	"        [ "
	"          \"BACKEND\" "
	"        ], "
	"        \"Vmod_vmod_directors_Func.hash_backend\", "
	"        \"\", "
	"        [ "
	"          \"STRANDS\" "
	"        ] "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$OBJ\", "
	"    \"shard\", "
	"    { "
	"      \"NULL_OK\": false "
	"    }, "
	"    \"struct vmod_directors_shard\", "
	"    [ "
	"      \"$INIT\", "
	"      [ "
	"        [ "
	"          \"VOID\" "
	"        ], "
	"        \"Vmod_vmod_directors_Func.shard__init\", "
	"        \"\" "
	"      ] "
	"    ], "
	"    [ "
	"      \"$FINI\", "
	"      [ "
	"        [ "
	"          \"VOID\" "
	"        ], "
	"        \"Vmod_vmod_directors_Func.shard__fini\", "
	"        \"\" "
	"      ] "
	"    ], "
	"    [ "
	"      \"$METHOD\", "
	"      \"set_warmup\", "
	"      [ "
	"        [ "
	"          \"VOID\" "
	"        ], "
	"        \"Vmod_vmod_directors_Func.shard_set_warmup\", "
	"        \"\", "
	"        [ "
	"          \"REAL\", "
	"          \"probability\", "
	"          \"0.0\" "
	"        ] "
	"      ] "
	"    ], "
	"    [ "
	"      \"$METHOD\", "
	"      \"set_rampup\", "
	"      [ "
	"        [ "
	"          \"VOID\" "
	"        ], "
	"        \"Vmod_vmod_directors_Func.shard_set_rampup\", "
	"        \"\", "
	"        [ "
	"          \"DURATION\", "
	"          \"duration\", "
	"          \"0\" "
	"        ] "
	"      ] "
	"    ], "
	"    [ "
	"      \"$METHOD\", "
	"      \"associate\", "
	"      [ "
	"        [ "
	"          \"VOID\" "
	"        ], "
	"        \"Vmod_vmod_directors_Func.shard_associate\", "
	"        \"\", "
	"        [ "
	"          \"BLOB\", "
	"          \"param\", "
	"          \"0\" "
	"        ] "
	"      ] "
	"    ], "
	"    [ "
	"      \"$METHOD\", "
	"      \"add_backend\", "
	"      [ "
	"        [ "
	"          \"BOOL\" "
	"        ], "
	"        \"Vmod_vmod_directors_Func.shard_add_backend\", "
	"        \"struct arg_vmod_directors_shard_add_backend\", "
	"        [ "
	"          \"PRIV_TASK\" "
	"        ], "
	"        [ "
	"          \"BACKEND\", "
	"          \"backend\" "
	"        ], "
	"        [ "
	"          \"STRING\", "
	"          \"ident\", "
	"          null, "
	"          null, "
	"          true "
	"        ], "
	"        [ "
	"          \"DURATION\", "
	"          \"rampup\", "
	"          null, "
	"          null, "
	"          true "
	"        ], "
	"        [ "
	"          \"REAL\", "
	"          \"weight\", "
	"          null, "
	"          null, "
	"          true "
	"        ] "
	"      ] "
	"    ], "
	"    [ "
	"      \"$METHOD\", "
	"      \"remove_backend\", "
	"      [ "
	"        [ "
	"          \"BOOL\" "
	"        ], "
	"        \"Vmod_vmod_directors_Func.shard_remove_backend\", "
	"        \"struct arg_vmod_directors_shard_remove_backend\", "
	"        [ "
	"          \"PRIV_TASK\" "
	"        ], "
	"        [ "
	"          \"BACKEND\", "
	"          \"backend\", "
	"          \"0\", "
	"          null, "
	"          true "
	"        ], "
	"        [ "
	"          \"STRING\", "
	"          \"ident\", "
	"          \"0\", "
	"          null, "
	"          true "
	"        ] "
	"      ] "
	"    ], "
	"    [ "
	"      \"$METHOD\", "
	"      \"clear\", "
	"      [ "
	"        [ "
	"          \"BOOL\" "
	"        ], "
	"        \"Vmod_vmod_directors_Func.shard_clear\", "
	"        \"\", "
	"        [ "
	"          \"PRIV_TASK\" "
	"        ] "
	"      ] "
	"    ], "
	"    [ "
	"      \"$METHOD\", "
	"      \"reconfigure\", "
	"      [ "
	"        [ "
	"          \"BOOL\" "
	"        ], "
	"        \"Vmod_vmod_directors_Func.shard_reconfigure\", "
	"        \"\", "
	"        [ "
	"          \"PRIV_TASK\" "
	"        ], "
	"        [ "
	"          \"INT\", "
	"          \"replicas\", "
	"          \"67\" "
	"        ] "
	"      ] "
	"    ], "
	"    [ "
	"      \"$METHOD\", "
	"      \"key\", "
	"      [ "
	"        [ "
	"          \"INT\" "
	"        ], "
	"        \"Vmod_vmod_directors_Func.shard_key\", "
	"        \"\", "
	"        [ "
	"          \"STRANDS\" "
	"        ] "
	"      ] "
	"    ], "
	"    [ "
	"      \"$METHOD\", "
	"      \"backend\", "
	"      [ "
	"        [ "
	"          \"BACKEND\" "
	"        ], "
	"        \"Vmod_vmod_directors_Func.shard_backend\", "
	"        \"struct arg_vmod_directors_shard_backend\", "
	"        [ "
	"          \"ENUM\", "
	"          \"by\", "
	"          \"HASH\", "
	"          [ "
	"            \"HASH\", "
	"            \"URL\", "
	"            \"KEY\", "
	"            \"BLOB\" "
	"          ], "
	"          true "
	"        ], "
	"        [ "
	"          \"INT\", "
	"          \"key\", "
	"          null, "
	"          null, "
	"          true "
	"        ], "
	"        [ "
	"          \"BLOB\", "
	"          \"key_blob\", "
	"          null, "
	"          null, "
	"          true "
	"        ], "
	"        [ "
	"          \"INT\", "
	"          \"alt\", "
	"          \"0\", "
	"          null, "
	"          true "
	"        ], "
	"        [ "
	"          \"REAL\", "
	"          \"warmup\", "
	"          \"-1\", "
	"          null, "
	"          true "
	"        ], "
	"        [ "
	"          \"BOOL\", "
	"          \"rampup\", "
	"          \"1\", "
	"          null, "
	"          true "
	"        ], "
	"        [ "
	"          \"ENUM\", "
	"          \"healthy\", "
	"          \"CHOSEN\", "
	"          [ "
	"            \"CHOSEN\", "
	"            \"IGNORE\", "
	"            \"ALL\" "
	"          ], "
	"          true "
	"        ], "
	"        [ "
	"          \"BLOB\", "
	"          \"param\", "
	"          null, "
	"          null, "
	"          true "
	"        ], "
	"        [ "
	"          \"ENUM\", "
	"          \"resolve\", "
	"          null, "
	"          [ "
	"            \"NOW\", "
	"            \"LAZY\" "
	"          ], "
	"          true "
	"        ] "
	"      ] "
	"    ], "
	"    [ "
	"      \"$METHOD\", "
	"      \"debug\", "
	"      [ "
	"        [ "
	"          \"VOID\" "
	"        ], "
	"        \"Vmod_vmod_directors_Func.shard_debug\", "
	"        \"\", "
	"        [ "
	"          \"INT\" "
	"        ] "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$OBJ\", "
	"    \"shard_param\", "
	"    { "
	"      \"NULL_OK\": false "
	"    }, "
	"    \"struct vmod_directors_shard_param\", "
	"    [ "
	"      \"$INIT\", "
	"      [ "
	"        [ "
	"          \"VOID\" "
	"        ], "
	"        \"Vmod_vmod_directors_Func.shard_param__init\", "
	"        \"\" "
	"      ] "
	"    ], "
	"    [ "
	"      \"$FINI\", "
	"      [ "
	"        [ "
	"          \"VOID\" "
	"        ], "
	"        \"Vmod_vmod_directors_Func.shard_param__fini\", "
	"        \"\" "
	"      ] "
	"    ], "
	"    [ "
	"      \"$METHOD\", "
	"      \"clear\", "
	"      [ "
	"        [ "
	"          \"VOID\" "
	"        ], "
	"        \"Vmod_vmod_directors_Func.shard_param_clear\", "
	"        \"\" "
	"      ] "
	"    ], "
	"    [ "
	"      \"$METHOD\", "
	"      \"set\", "
	"      [ "
	"        [ "
	"          \"VOID\" "
	"        ], "
	"        \"Vmod_vmod_directors_Func.shard_param_set\", "
	"        \"struct arg_vmod_directors_shard_param_set\", "
	"        [ "
	"          \"ENUM\", "
	"          \"by\", "
	"          null, "
	"          [ "
	"            \"HASH\", "
	"            \"URL\", "
	"            \"KEY\", "
	"            \"BLOB\" "
	"          ], "
	"          true "
	"        ], "
	"        [ "
	"          \"INT\", "
	"          \"key\", "
	"          null, "
	"          null, "
	"          true "
	"        ], "
	"        [ "
	"          \"BLOB\", "
	"          \"key_blob\", "
	"          null, "
	"          null, "
	"          true "
	"        ], "
	"        [ "
	"          \"INT\", "
	"          \"alt\", "
	"          null, "
	"          null, "
	"          true "
	"        ], "
	"        [ "
	"          \"REAL\", "
	"          \"warmup\", "
	"          null, "
	"          null, "
	"          true "
	"        ], "
	"        [ "
	"          \"BOOL\", "
	"          \"rampup\", "
	"          null, "
	"          null, "
	"          true "
	"        ], "
	"        [ "
	"          \"ENUM\", "
	"          \"healthy\", "
	"          null, "
	"          [ "
	"            \"CHOSEN\", "
	"            \"IGNORE\", "
	"            \"ALL\" "
	"          ], "
	"          true "
	"        ] "
	"      ] "
	"    ], "
	"    [ "
	"      \"$METHOD\", "
	"      \"get_by\", "
	"      [ "
	"        [ "
	"          \"STRING\" "
	"        ], "
	"        \"Vmod_vmod_directors_Func.shard_param_get_by\", "
	"        \"\" "
	"      ] "
	"    ], "
	"    [ "
	"      \"$METHOD\", "
	"      \"get_key\", "
	"      [ "
	"        [ "
	"          \"INT\" "
	"        ], "
	"        \"Vmod_vmod_directors_Func.shard_param_get_key\", "
	"        \"\" "
	"      ] "
	"    ], "
	"    [ "
	"      \"$METHOD\", "
	"      \"get_alt\", "
	"      [ "
	"        [ "
	"          \"INT\" "
	"        ], "
	"        \"Vmod_vmod_directors_Func.shard_param_get_alt\", "
	"        \"\" "
	"      ] "
	"    ], "
	"    [ "
	"      \"$METHOD\", "
	"      \"get_warmup\", "
	"      [ "
	"        [ "
	"          \"REAL\" "
	"        ], "
	"        \"Vmod_vmod_directors_Func.shard_param_get_warmup\", "
	"        \"\" "
	"      ] "
	"    ], "
	"    [ "
	"      \"$METHOD\", "
	"      \"get_rampup\", "
	"      [ "
	"        [ "
	"          \"BOOL\" "
	"        ], "
	"        \"Vmod_vmod_directors_Func.shard_param_get_rampup\", "
	"        \"\" "
	"      ] "
	"    ], "
	"    [ "
	"      \"$METHOD\", "
	"      \"get_healthy\", "
	"      [ "
	"        [ "
	"          \"STRING\" "
	"        ], "
	"        \"Vmod_vmod_directors_Func.shard_param_get_healthy\", "
	"        \"\" "
	"      ] "
	"    ], "
	"    [ "
	"      \"$METHOD\", "
	"      \"use\", "
	"      [ "
	"        [ "
	"          \"BLOB\" "
	"        ], "
	"        \"Vmod_vmod_directors_Func.shard_param_use\", "
	"        \"\" "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"lookup\", "
	"    [ "
	"      [ "
	"        \"BACKEND\" "
	"      ], "
	"      \"Vmod_vmod_directors_Func.lookup\", "
	"      \"\", "
	"      [ "
	"        \"STRING\" "
	"      ] "
	"    ] "
	"  ] "
	"]\n"
};

/*lint -esym(714, Vmod_directors_Data) */
/*lint -esym(759, Vmod_directors_Data) */
/*lint -esym(765, Vmod_directors_Data) */

extern const struct vmod_data Vmod_directors_Data;

const struct vmod_data Vmod_directors_Data = {
	.vrt_major =	0,
	.vrt_minor =	0,
	.name =		"directors",
	.func =		&Vmod_vmod_directors_Func,
	.func_len =	sizeof(Vmod_vmod_directors_Func),
	.func_name =	"Vmod_vmod_directors_Func",
	.proto =	Vmod_Proto,
	.json =		Vmod_Json,
	.abi =		VMOD_ABI_Version,
	.file_id =	"99a7698e231601626eb3c36baa2665d8fb08d07e254f11d26e7f5c26eb62bf23",
};
