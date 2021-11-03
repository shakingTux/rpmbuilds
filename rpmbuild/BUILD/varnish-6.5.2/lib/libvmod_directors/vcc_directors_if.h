/*
 * NB:  This file is machine generated, DO NOT EDIT!
 *
 * Edit ./vmod_directors.vcc and run make instead
 */

#ifndef VDEF_H_INCLUDED
#  error "Include vdef.h first"
#endif
#ifndef VRT_H_INCLUDED
#  error "Include vrt.h first"
#endif

#define VPFX(a) vmod_##a
#define VARGS(a) arg_vmod_directors_##a
#define VENUM(a) enum_vmod_directors_##a
//lint -esym(755, VPFX)
//lint -esym(767, VPFX)
//lint -esym(755, VARGS)
//lint -esym(767, VARGS)
//lint -esym(755, VENUM)
//lint -esym(767, VENUM)
//lint -esym(755, VARGS)
//lint -esym(755, VENUM)

extern VCL_ENUM VENUM(ALL);
extern VCL_ENUM VENUM(BLOB);
extern VCL_ENUM VENUM(CHOSEN);
extern VCL_ENUM VENUM(HASH);
extern VCL_ENUM VENUM(IGNORE);
extern VCL_ENUM VENUM(KEY);
extern VCL_ENUM VENUM(LAZY);
extern VCL_ENUM VENUM(NOW);
extern VCL_ENUM VENUM(URL);

//lint -esym(14, enum_vmod_directors_ALL)
//lint -esym(759, enum_vmod_directors_ALL)
//lint -esym(765, enum_vmod_directors_ALL)
//lint -esym(14, enum_vmod_directors_BLOB)
//lint -esym(759, enum_vmod_directors_BLOB)
//lint -esym(765, enum_vmod_directors_BLOB)
//lint -esym(14, enum_vmod_directors_CHOSEN)
//lint -esym(759, enum_vmod_directors_CHOSEN)
//lint -esym(765, enum_vmod_directors_CHOSEN)
//lint -esym(14, enum_vmod_directors_HASH)
//lint -esym(759, enum_vmod_directors_HASH)
//lint -esym(765, enum_vmod_directors_HASH)
//lint -esym(14, enum_vmod_directors_IGNORE)
//lint -esym(759, enum_vmod_directors_IGNORE)
//lint -esym(765, enum_vmod_directors_IGNORE)
//lint -esym(14, enum_vmod_directors_KEY)
//lint -esym(759, enum_vmod_directors_KEY)
//lint -esym(765, enum_vmod_directors_KEY)
//lint -esym(14, enum_vmod_directors_LAZY)
//lint -esym(759, enum_vmod_directors_LAZY)
//lint -esym(765, enum_vmod_directors_LAZY)
//lint -esym(14, enum_vmod_directors_NOW)
//lint -esym(759, enum_vmod_directors_NOW)
//lint -esym(765, enum_vmod_directors_NOW)
//lint -esym(14, enum_vmod_directors_URL)
//lint -esym(759, enum_vmod_directors_URL)
//lint -esym(765, enum_vmod_directors_URL)

struct VPFX(directors_round_robin);
VCL_VOID vmod_round_robin__init(VRT_CTX,
    struct VPFX(directors_round_robin) **, const char *);
VCL_VOID vmod_round_robin__fini(struct VPFX(
    directors_round_robin) **);
VCL_VOID vmod_round_robin_add_backend(VRT_CTX,
    struct VPFX(directors_round_robin) *, VCL_BACKEND);
VCL_VOID vmod_round_robin_remove_backend(VRT_CTX,
    struct VPFX(directors_round_robin) *, VCL_BACKEND);
VCL_BACKEND vmod_round_robin_backend(VRT_CTX,
    struct VPFX(directors_round_robin) *);

struct VPFX(directors_fallback);
VCL_VOID vmod_fallback__init(VRT_CTX,
    struct VPFX(directors_fallback) **, const char *, VCL_BOOL);
VCL_VOID vmod_fallback__fini(struct VPFX(
    directors_fallback) **);
VCL_VOID vmod_fallback_add_backend(VRT_CTX,
    struct VPFX(directors_fallback) *, VCL_BACKEND);
VCL_VOID vmod_fallback_remove_backend(VRT_CTX,
    struct VPFX(directors_fallback) *, VCL_BACKEND);
VCL_BACKEND vmod_fallback_backend(VRT_CTX,
    struct VPFX(directors_fallback) *);

struct VPFX(directors_random);
VCL_VOID vmod_random__init(VRT_CTX,
    struct VPFX(directors_random) **, const char *);
VCL_VOID vmod_random__fini(struct VPFX(directors_random) **);
VCL_VOID vmod_random_add_backend(VRT_CTX,
    struct VPFX(directors_random) *, VCL_BACKEND, VCL_REAL);
VCL_VOID vmod_random_remove_backend(VRT_CTX,
    struct VPFX(directors_random) *, VCL_BACKEND);
VCL_BACKEND vmod_random_backend(VRT_CTX,
    struct VPFX(directors_random) *);

struct VPFX(directors_hash);
VCL_VOID vmod_hash__init(VRT_CTX,
    struct VPFX(directors_hash) **, const char *);
VCL_VOID vmod_hash__fini(struct VPFX(directors_hash) **);
VCL_VOID vmod_hash_add_backend(VRT_CTX,
    struct VPFX(directors_hash) *, VCL_BACKEND, VCL_REAL);
VCL_VOID vmod_hash_remove_backend(VRT_CTX,
    struct VPFX(directors_hash) *, VCL_BACKEND);
VCL_BACKEND vmod_hash_backend(VRT_CTX,
    struct VPFX(directors_hash) *, VCL_STRANDS);

struct VPFX(directors_shard);
VCL_VOID vmod_shard__init(VRT_CTX,
    struct VPFX(directors_shard) **, const char *);
VCL_VOID vmod_shard__fini(struct VPFX(directors_shard) **);
VCL_VOID vmod_shard_set_warmup(VRT_CTX,
    struct VPFX(directors_shard) *, VCL_REAL);
VCL_VOID vmod_shard_set_rampup(VRT_CTX,
    struct VPFX(directors_shard) *, VCL_DURATION);
VCL_VOID vmod_shard_associate(VRT_CTX,
    struct VPFX(directors_shard) *, VCL_BLOB);

struct VARGS(shard_add_backend) {
	char			valid_ident;
	char			valid_rampup;
	char			valid_weight;
	struct vmod_priv *	arg1;
	VCL_BACKEND		backend;
	VCL_STRING		ident;
	VCL_DURATION		rampup;
	VCL_REAL		weight;
};
VCL_BOOL vmod_shard_add_backend(VRT_CTX,
    struct VPFX(directors_shard) *,
    struct VARGS(shard_add_backend)*);

struct VARGS(shard_remove_backend) {
	char			valid_backend;
	char			valid_ident;
	struct vmod_priv *	arg1;
	VCL_BACKEND		backend;
	VCL_STRING		ident;
};
VCL_BOOL vmod_shard_remove_backend(VRT_CTX,
    struct VPFX(directors_shard) *,
    struct VARGS(shard_remove_backend)*);
VCL_BOOL vmod_shard_clear(VRT_CTX,
    struct VPFX(directors_shard) *, struct vmod_priv *);
VCL_BOOL vmod_shard_reconfigure(VRT_CTX,
    struct VPFX(directors_shard) *, struct vmod_priv *, VCL_INT);
VCL_INT vmod_shard_key(VRT_CTX, struct VPFX(directors_shard) *,
    VCL_STRANDS);

struct VARGS(shard_backend) {
	char			valid_by;
	char			valid_key;
	char			valid_key_blob;
	char			valid_alt;
	char			valid_warmup;
	char			valid_rampup;
	char			valid_healthy;
	char			valid_param;
	char			valid_resolve;
	VCL_ENUM		by;
	VCL_INT			key;
	VCL_BLOB		key_blob;
	VCL_INT			alt;
	VCL_REAL		warmup;
	VCL_BOOL		rampup;
	VCL_ENUM		healthy;
	VCL_BLOB		param;
	VCL_ENUM		resolve;
};
VCL_BACKEND vmod_shard_backend(VRT_CTX,
    struct VPFX(directors_shard) *, struct VARGS(shard_backend)*);
VCL_VOID vmod_shard_debug(VRT_CTX,
    struct VPFX(directors_shard) *, VCL_INT);

struct VPFX(directors_shard_param);
VCL_VOID vmod_shard_param__init(VRT_CTX,
    struct VPFX(directors_shard_param) **, const char *);
VCL_VOID vmod_shard_param__fini(struct VPFX(
    directors_shard_param) **);
VCL_VOID vmod_shard_param_clear(VRT_CTX,
    struct VPFX(directors_shard_param) *);

struct VARGS(shard_param_set) {
	char			valid_by;
	char			valid_key;
	char			valid_key_blob;
	char			valid_alt;
	char			valid_warmup;
	char			valid_rampup;
	char			valid_healthy;
	VCL_ENUM		by;
	VCL_INT			key;
	VCL_BLOB		key_blob;
	VCL_INT			alt;
	VCL_REAL		warmup;
	VCL_BOOL		rampup;
	VCL_ENUM		healthy;
};
VCL_VOID vmod_shard_param_set(VRT_CTX,
    struct VPFX(directors_shard_param) *,
    struct VARGS(shard_param_set)*);
VCL_STRING vmod_shard_param_get_by(VRT_CTX,
    struct VPFX(directors_shard_param) *);
VCL_INT vmod_shard_param_get_key(VRT_CTX,
    struct VPFX(directors_shard_param) *);
VCL_INT vmod_shard_param_get_alt(VRT_CTX,
    struct VPFX(directors_shard_param) *);
VCL_REAL vmod_shard_param_get_warmup(VRT_CTX,
    struct VPFX(directors_shard_param) *);
VCL_BOOL vmod_shard_param_get_rampup(VRT_CTX,
    struct VPFX(directors_shard_param) *);
VCL_STRING vmod_shard_param_get_healthy(VRT_CTX,
    struct VPFX(directors_shard_param) *);
VCL_BLOB vmod_shard_param_use(VRT_CTX,
    struct VPFX(directors_shard_param) *);

VCL_BACKEND vmod_lookup(VRT_CTX, VCL_STRING);
