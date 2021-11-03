/*
 * NB:  This file is machine generated, DO NOT EDIT!
 *
 * Edit ./vmod_std.vcc and run make instead
 */

#ifndef VDEF_H_INCLUDED
#  error "Include vdef.h first"
#endif
#ifndef VRT_H_INCLUDED
#  error "Include vrt.h first"
#endif

#define VPFX(a) vmod_##a
#define VARGS(a) arg_vmod_std_##a
#define VENUM(a) enum_vmod_std_##a
//lint -esym(755, VPFX)
//lint -esym(767, VPFX)
//lint -esym(755, VARGS)
//lint -esym(767, VARGS)
//lint -esym(755, VENUM)
//lint -esym(767, VENUM)
//lint -esym(755, VARGS)
//lint -esym(755, VENUM)



VCL_REAL vmod_random(VRT_CTX, VCL_REAL, VCL_REAL);
VCL_REAL vmod_round(VRT_CTX, VCL_REAL);
VCL_VOID vmod_collect(VRT_CTX, VCL_HEADER, VCL_STRING);
VCL_STRING vmod_querysort(VRT_CTX, VCL_STRING);
VCL_STRING vmod_toupper(VRT_CTX, VCL_STRANDS);
VCL_STRING vmod_tolower(VRT_CTX, VCL_STRANDS);
VCL_STRING vmod_strstr(VRT_CTX, VCL_STRING, VCL_STRING);
VCL_BOOL vmod_fnmatch(VRT_CTX, VCL_STRING, VCL_STRING, VCL_BOOL,
    VCL_BOOL, VCL_BOOL);
VCL_STRING vmod_fileread(VRT_CTX, struct vmod_priv *,
    VCL_STRING);
VCL_BLOB vmod_blobread(VRT_CTX, struct vmod_priv *, VCL_STRING);
VCL_BOOL vmod_file_exists(VRT_CTX, VCL_STRING);
VCL_BOOL vmod_healthy(VRT_CTX, VCL_BACKEND);
VCL_INT vmod_port(VRT_CTX, VCL_IP);

struct VARGS(duration) {
	char			valid_s;
	char			valid_fallback;
	char			valid_real;
	char			valid_integer;
	VCL_STRING		s;
	VCL_DURATION		fallback;
	VCL_REAL		real;
	VCL_INT			integer;
};
VCL_DURATION vmod_duration(VRT_CTX, struct VARGS(duration)*);

struct VARGS(bytes) {
	char			valid_s;
	char			valid_fallback;
	char			valid_real;
	char			valid_integer;
	VCL_STRING		s;
	VCL_BYTES		fallback;
	VCL_REAL		real;
	VCL_INT			integer;
};
VCL_BYTES vmod_bytes(VRT_CTX, struct VARGS(bytes)*);

struct VARGS(integer) {
	char			valid_s;
	char			valid_fallback;
	char			valid_bool;
	char			valid_bytes;
	char			valid_duration;
	char			valid_real;
	char			valid_time;
	VCL_STRING		s;
	VCL_INT			fallback;
	VCL_BOOL		bool;
	VCL_BYTES		bytes;
	VCL_DURATION		duration;
	VCL_REAL		real;
	VCL_TIME		time;
};
VCL_INT vmod_integer(VRT_CTX, struct VARGS(integer)*);

struct VARGS(ip) {
	char			valid_fallback;
	char			valid_p;
	VCL_STRING		s;
	VCL_IP			fallback;
	VCL_BOOL		resolve;
	VCL_STRING		p;
};
VCL_IP vmod_ip(VRT_CTX, struct VARGS(ip)*);

struct VARGS(real) {
	char			valid_s;
	char			valid_fallback;
	char			valid_integer;
	char			valid_bool;
	char			valid_bytes;
	char			valid_duration;
	char			valid_time;
	VCL_STRING		s;
	VCL_REAL		fallback;
	VCL_INT			integer;
	VCL_BOOL		bool;
	VCL_BYTES		bytes;
	VCL_DURATION		duration;
	VCL_TIME		time;
};
VCL_REAL vmod_real(VRT_CTX, struct VARGS(real)*);

struct VARGS(time) {
	char			valid_s;
	char			valid_fallback;
	char			valid_real;
	char			valid_integer;
	VCL_STRING		s;
	VCL_TIME		fallback;
	VCL_REAL		real;
	VCL_INT			integer;
};
VCL_TIME vmod_time(VRT_CTX, struct VARGS(time)*);
VCL_VOID vmod_log(VRT_CTX, VCL_STRANDS);
VCL_VOID vmod_syslog(VRT_CTX, VCL_INT, VCL_STRANDS);
VCL_VOID vmod_timestamp(VRT_CTX, VCL_STRING);
VCL_BOOL vmod_syntax(VRT_CTX, VCL_REAL);
VCL_STRING vmod_getenv(VRT_CTX, VCL_STRING);
VCL_BOOL vmod_cache_req_body(VRT_CTX, VCL_BYTES);
VCL_VOID vmod_late_100_continue(VRT_CTX, VCL_BOOL);
VCL_VOID vmod_set_ip_tos(VRT_CTX, VCL_INT);
VCL_VOID vmod_rollback(VRT_CTX, VCL_HTTP);
VCL_INT vmod_real2integer(VRT_CTX, VCL_REAL, VCL_INT);
VCL_TIME vmod_real2time(VRT_CTX, VCL_REAL, VCL_TIME);
VCL_INT vmod_time2integer(VRT_CTX, VCL_TIME, VCL_INT);
VCL_REAL vmod_time2real(VRT_CTX, VCL_TIME, VCL_REAL);
