/*
 * NB:  This file is machine generated, DO NOT EDIT!
 *
 * Edit ./vmod_vtc.vcc and run make instead
 */

#include "config.h"
#include <stdio.h>
#include "vdef.h"
#include "vrt.h"
#include "vcc_vtc_if.h"
#include "vmod_abi.h"

VCL_ENUM VENUM(backend) = "backend";
VCL_ENUM VENUM(client) = "client";
VCL_ENUM VENUM(f) = "f";
VCL_ENUM VENUM(r) = "r";
VCL_ENUM VENUM(s) = "s";
VCL_ENUM VENUM(session) = "session";
VCL_ENUM VENUM(thread) = "thread";
VCL_ENUM VENUM(v1) = "v1";
VCL_ENUM VENUM(v2) = "v2";

typedef VCL_VOID td_vmod_vtc_barrier_sync(VRT_CTX, VCL_STRING,
    VCL_DURATION);
typedef VCL_BACKEND td_vmod_vtc_no_backend(VRT_CTX);
typedef VCL_STEVEDORE td_vmod_vtc_no_stevedore(VRT_CTX);
typedef VCL_IP td_vmod_vtc_no_ip(VRT_CTX);
typedef VCL_VOID td_vmod_vtc_panic(VRT_CTX, VCL_STRANDS);
typedef VCL_VOID td_vmod_vtc_sleep(VRT_CTX, VCL_DURATION);
typedef VCL_VOID td_vmod_vtc_workspace_alloc(VRT_CTX, VCL_ENUM,
    VCL_INT);
typedef VCL_BYTES td_vmod_vtc_workspace_reserve(VRT_CTX,
    VCL_ENUM, VCL_INT);
typedef VCL_INT td_vmod_vtc_workspace_free(VRT_CTX, VCL_ENUM);
typedef VCL_VOID td_vmod_vtc_workspace_snapshot(VRT_CTX,
    VCL_ENUM);
typedef VCL_VOID td_vmod_vtc_workspace_reset(VRT_CTX, VCL_ENUM);
typedef VCL_BOOL td_vmod_vtc_workspace_overflowed(VRT_CTX,
    VCL_ENUM);
typedef VCL_VOID td_vmod_vtc_workspace_overflow(VRT_CTX,
    VCL_ENUM);
typedef VCL_BLOB td_vmod_vtc_workspace_dump(VRT_CTX, VCL_ENUM,
    VCL_ENUM, VCL_BYTES, VCL_BYTES);
typedef VCL_INT td_vmod_vtc_typesize(VRT_CTX, VCL_STRING);
typedef VCL_BLOB td_vmod_vtc_proxy_header(VRT_CTX, VCL_ENUM,
    VCL_IP, VCL_IP, VCL_STRING);

struct Vmod_vmod_vtc_Func {
	td_vmod_vtc_barrier_sync	*barrier_sync;
	td_vmod_vtc_no_backend		*no_backend;
	td_vmod_vtc_no_stevedore	*no_stevedore;
	td_vmod_vtc_no_ip		*no_ip;
	td_vmod_vtc_panic		*panic;
	td_vmod_vtc_sleep		*sleep;
	td_vmod_vtc_workspace_alloc	*workspace_alloc;
	td_vmod_vtc_workspace_reserve	*workspace_reserve;
	td_vmod_vtc_workspace_free	*workspace_free;
	td_vmod_vtc_workspace_snapshot	*workspace_snapshot;
	td_vmod_vtc_workspace_reset	*workspace_reset;
	td_vmod_vtc_workspace_overflowed	*workspace_overflowed;
	td_vmod_vtc_workspace_overflow	*workspace_overflow;
	td_vmod_vtc_workspace_dump	*workspace_dump;
	td_vmod_vtc_typesize		*typesize;
	td_vmod_vtc_proxy_header	*proxy_header;
	VCL_ENUM			*enum_backend;
	VCL_ENUM			*enum_client;
	VCL_ENUM			*enum_f;
	VCL_ENUM			*enum_r;
	VCL_ENUM			*enum_s;
	VCL_ENUM			*enum_session;
	VCL_ENUM			*enum_thread;
	VCL_ENUM			*enum_v1;
	VCL_ENUM			*enum_v2;
};

/*lint -esym(754, Vmod_vmod_vtc_Func::*) */

static const struct Vmod_vmod_vtc_Func Vmod_vmod_vtc_Func = {
	.barrier_sync =			vmod_barrier_sync,
	.no_backend =			vmod_no_backend,
	.no_stevedore =			vmod_no_stevedore,
	.no_ip =			vmod_no_ip,
	.panic =			vmod_panic,
	.sleep =			vmod_sleep,
	.workspace_alloc =		vmod_workspace_alloc,
	.workspace_reserve =		vmod_workspace_reserve,
	.workspace_free =		vmod_workspace_free,
	.workspace_snapshot =		vmod_workspace_snapshot,
	.workspace_reset =		vmod_workspace_reset,
	.workspace_overflowed =		vmod_workspace_overflowed,
	.workspace_overflow =		vmod_workspace_overflow,
	.workspace_dump =		vmod_workspace_dump,
	.typesize =			vmod_typesize,
	.proxy_header =			vmod_proxy_header,

	.enum_backend =			&VENUM(backend),
	.enum_client =			&VENUM(client),
	.enum_f =			&VENUM(f),
	.enum_r =			&VENUM(r),
	.enum_s =			&VENUM(s),
	.enum_session =			&VENUM(session),
	.enum_thread =			&VENUM(thread),
	.enum_v1 =			&VENUM(v1),
	.enum_v2 =			&VENUM(v2),
};

static const char Vmod_Proto[] =
	"#define VPFX(a) vmod_##a\n"
	"#define VARGS(a) arg_vmod_vtc_##a\n"
	"#define VENUM(a) enum_vmod_vtc_##a\n"
	"//lint -esym(755, VPFX)\n"
	"//lint -esym(767, VPFX)\n"
	"//lint -esym(755, VARGS)\n"
	"//lint -esym(767, VARGS)\n"
	"//lint -esym(755, VENUM)\n"
	"//lint -esym(767, VENUM)\n"
	"//lint -esym(755, VARGS)\n"
	"//lint -esym(755, VENUM)\n"
	"\n"
	"/* Functions */\n"
	"typedef VCL_VOID td_vmod_vtc_barrier_sync(VRT_CTX, VCL_STRING,\n"
	"    VCL_DURATION);\n"
	"typedef VCL_BACKEND td_vmod_vtc_no_backend(VRT_CTX);\n"
	"typedef VCL_STEVEDORE td_vmod_vtc_no_stevedore(VRT_CTX);\n"
	"typedef VCL_IP td_vmod_vtc_no_ip(VRT_CTX);\n"
	"typedef VCL_VOID td_vmod_vtc_panic(VRT_CTX, VCL_STRANDS);\n"
	"typedef VCL_VOID td_vmod_vtc_sleep(VRT_CTX, VCL_DURATION);\n"
	"typedef VCL_VOID td_vmod_vtc_workspace_alloc(VRT_CTX, VCL_ENUM,\n"
	"    VCL_INT);\n"
	"typedef VCL_BYTES td_vmod_vtc_workspace_reserve(VRT_CTX,\n"
	"    VCL_ENUM, VCL_INT);\n"
	"typedef VCL_INT td_vmod_vtc_workspace_free(VRT_CTX, VCL_ENUM);\n"
	"typedef VCL_VOID td_vmod_vtc_workspace_snapshot(VRT_CTX,\n"
	"    VCL_ENUM);\n"
	"typedef VCL_VOID td_vmod_vtc_workspace_reset(VRT_CTX, VCL_ENUM);\n"
	"typedef VCL_BOOL td_vmod_vtc_workspace_overflowed(VRT_CTX,\n"
	"    VCL_ENUM);\n"
	"typedef VCL_VOID td_vmod_vtc_workspace_overflow(VRT_CTX,\n"
	"    VCL_ENUM);\n"
	"typedef VCL_BLOB td_vmod_vtc_workspace_dump(VRT_CTX, VCL_ENUM,\n"
	"    VCL_ENUM, VCL_BYTES, VCL_BYTES);\n"
	"typedef VCL_INT td_vmod_vtc_typesize(VRT_CTX, VCL_STRING);\n"
	"typedef VCL_BLOB td_vmod_vtc_proxy_header(VRT_CTX, VCL_ENUM,\n"
	"    VCL_IP, VCL_IP, VCL_STRING);\n"
	"\n"
	"struct Vmod_vmod_vtc_Func {\n"
	"	td_vmod_vtc_barrier_sync	*barrier_sync;\n"
	"	td_vmod_vtc_no_backend		*no_backend;\n"
	"	td_vmod_vtc_no_stevedore	*no_stevedore;\n"
	"	td_vmod_vtc_no_ip		*no_ip;\n"
	"	td_vmod_vtc_panic		*panic;\n"
	"	td_vmod_vtc_sleep		*sleep;\n"
	"	td_vmod_vtc_workspace_alloc	*workspace_alloc;\n"
	"	td_vmod_vtc_workspace_reserve	*workspace_reserve;\n"
	"	td_vmod_vtc_workspace_free	*workspace_free;\n"
	"	td_vmod_vtc_workspace_snapshot	*workspace_snapshot;\n"
	"	td_vmod_vtc_workspace_reset	*workspace_reset;\n"
	"	td_vmod_vtc_workspace_overflowed	*workspace_overflowed;\n"
	"	td_vmod_vtc_workspace_overflow	*workspace_overflow;\n"
	"	td_vmod_vtc_workspace_dump	*workspace_dump;\n"
	"	td_vmod_vtc_typesize		*typesize;\n"
	"	td_vmod_vtc_proxy_header	*proxy_header;\n"
	"	VCL_ENUM			*enum_backend;\n"
	"	VCL_ENUM			*enum_client;\n"
	"	VCL_ENUM			*enum_f;\n"
	"	VCL_ENUM			*enum_r;\n"
	"	VCL_ENUM			*enum_s;\n"
	"	VCL_ENUM			*enum_session;\n"
	"	VCL_ENUM			*enum_thread;\n"
	"	VCL_ENUM			*enum_v1;\n"
	"	VCL_ENUM			*enum_v2;\n"
	"};\n"
	"#undef VPFX\n"
	"#undef VARGS\n"
	"#undef VENUM\n"
	"static struct Vmod_vmod_vtc_Func Vmod_vmod_vtc_Func;";

static const char Vmod_Json[] = {
	"[ "
	"  [ "
	"    \"$VMOD\", "
	"    \"1.0\" "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"barrier_sync\", "
	"    [ "
	"      [ "
	"        \"VOID\" "
	"      ], "
	"      \"Vmod_vmod_vtc_Func.barrier_sync\", "
	"      \"\", "
	"      [ "
	"        \"STRING\", "
	"        \"addr\" "
	"      ], "
	"      [ "
	"        \"DURATION\", "
	"        \"timeout\", "
	"        \"0\" "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"no_backend\", "
	"    [ "
	"      [ "
	"        \"BACKEND\" "
	"      ], "
	"      \"Vmod_vmod_vtc_Func.no_backend\", "
	"      \"\" "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"no_stevedore\", "
	"    [ "
	"      [ "
	"        \"STEVEDORE\" "
	"      ], "
	"      \"Vmod_vmod_vtc_Func.no_stevedore\", "
	"      \"\" "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"no_ip\", "
	"    [ "
	"      [ "
	"        \"IP\" "
	"      ], "
	"      \"Vmod_vmod_vtc_Func.no_ip\", "
	"      \"\" "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"panic\", "
	"    [ "
	"      [ "
	"        \"VOID\" "
	"      ], "
	"      \"Vmod_vmod_vtc_Func.panic\", "
	"      \"\", "
	"      [ "
	"        \"STRANDS\" "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"sleep\", "
	"    [ "
	"      [ "
	"        \"VOID\" "
	"      ], "
	"      \"Vmod_vmod_vtc_Func.sleep\", "
	"      \"\", "
	"      [ "
	"        \"DURATION\" "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"workspace_alloc\", "
	"    [ "
	"      [ "
	"        \"VOID\" "
	"      ], "
	"      \"Vmod_vmod_vtc_Func.workspace_alloc\", "
	"      \"\", "
	"      [ "
	"        \"ENUM\", "
	"        null, "
	"        null, "
	"        [ "
	"          \"client\", "
	"          \"backend\", "
	"          \"session\", "
	"          \"thread\" "
	"        ] "
	"      ], "
	"      [ "
	"        \"INT\", "
	"        \"size\" "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"workspace_reserve\", "
	"    [ "
	"      [ "
	"        \"BYTES\" "
	"      ], "
	"      \"Vmod_vmod_vtc_Func.workspace_reserve\", "
	"      \"\", "
	"      [ "
	"        \"ENUM\", "
	"        null, "
	"        null, "
	"        [ "
	"          \"client\", "
	"          \"backend\", "
	"          \"session\", "
	"          \"thread\" "
	"        ] "
	"      ], "
	"      [ "
	"        \"INT\", "
	"        \"size\" "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"workspace_free\", "
	"    [ "
	"      [ "
	"        \"INT\" "
	"      ], "
	"      \"Vmod_vmod_vtc_Func.workspace_free\", "
	"      \"\", "
	"      [ "
	"        \"ENUM\", "
	"        null, "
	"        null, "
	"        [ "
	"          \"client\", "
	"          \"backend\", "
	"          \"session\", "
	"          \"thread\" "
	"        ] "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"workspace_snapshot\", "
	"    [ "
	"      [ "
	"        \"VOID\" "
	"      ], "
	"      \"Vmod_vmod_vtc_Func.workspace_snapshot\", "
	"      \"\", "
	"      [ "
	"        \"ENUM\", "
	"        null, "
	"        null, "
	"        [ "
	"          \"client\", "
	"          \"backend\", "
	"          \"session\", "
	"          \"thread\" "
	"        ] "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"workspace_reset\", "
	"    [ "
	"      [ "
	"        \"VOID\" "
	"      ], "
	"      \"Vmod_vmod_vtc_Func.workspace_reset\", "
	"      \"\", "
	"      [ "
	"        \"ENUM\", "
	"        null, "
	"        null, "
	"        [ "
	"          \"client\", "
	"          \"backend\", "
	"          \"session\", "
	"          \"thread\" "
	"        ] "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"workspace_overflowed\", "
	"    [ "
	"      [ "
	"        \"BOOL\" "
	"      ], "
	"      \"Vmod_vmod_vtc_Func.workspace_overflowed\", "
	"      \"\", "
	"      [ "
	"        \"ENUM\", "
	"        null, "
	"        null, "
	"        [ "
	"          \"client\", "
	"          \"backend\", "
	"          \"session\", "
	"          \"thread\" "
	"        ] "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"workspace_overflow\", "
	"    [ "
	"      [ "
	"        \"VOID\" "
	"      ], "
	"      \"Vmod_vmod_vtc_Func.workspace_overflow\", "
	"      \"\", "
	"      [ "
	"        \"ENUM\", "
	"        null, "
	"        null, "
	"        [ "
	"          \"client\", "
	"          \"backend\", "
	"          \"session\", "
	"          \"thread\" "
	"        ] "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"workspace_dump\", "
	"    [ "
	"      [ "
	"        \"BLOB\" "
	"      ], "
	"      \"Vmod_vmod_vtc_Func.workspace_dump\", "
	"      \"\", "
	"      [ "
	"        \"ENUM\", "
	"        null, "
	"        null, "
	"        [ "
	"          \"client\", "
	"          \"backend\", "
	"          \"session\", "
	"          \"thread\" "
	"        ] "
	"      ], "
	"      [ "
	"        \"ENUM\", "
	"        null, "
	"        null, "
	"        [ "
	"          \"s\", "
	"          \"f\", "
	"          \"r\" "
	"        ] "
	"      ], "
	"      [ "
	"        \"BYTES\", "
	"        \"off\", "
	"        \"0\" "
	"      ], "
	"      [ "
	"        \"BYTES\", "
	"        \"len\", "
	"        \"64\" "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"typesize\", "
	"    [ "
	"      [ "
	"        \"INT\" "
	"      ], "
	"      \"Vmod_vmod_vtc_Func.typesize\", "
	"      \"\", "
	"      [ "
	"        \"STRING\" "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"proxy_header\", "
	"    [ "
	"      [ "
	"        \"BLOB\" "
	"      ], "
	"      \"Vmod_vmod_vtc_Func.proxy_header\", "
	"      \"\", "
	"      [ "
	"        \"ENUM\", "
	"        \"version\", "
	"        null, "
	"        [ "
	"          \"v1\", "
	"          \"v2\" "
	"        ] "
	"      ], "
	"      [ "
	"        \"IP\", "
	"        \"client\" "
	"      ], "
	"      [ "
	"        \"IP\", "
	"        \"server\" "
	"      ], "
	"      [ "
	"        \"STRING\", "
	"        \"authority\", "
	"        \"0\" "
	"      ] "
	"    ] "
	"  ] "
	"]\n"
};

/*lint -esym(714, Vmod_vtc_Data) */
/*lint -esym(759, Vmod_vtc_Data) */
/*lint -esym(765, Vmod_vtc_Data) */

extern const struct vmod_data Vmod_vtc_Data;

const struct vmod_data Vmod_vtc_Data = {
	.vrt_major =	0,
	.vrt_minor =	0,
	.name =		"vtc",
	.func =		&Vmod_vmod_vtc_Func,
	.func_len =	sizeof(Vmod_vmod_vtc_Func),
	.func_name =	"Vmod_vmod_vtc_Func",
	.proto =	Vmod_Proto,
	.json =		Vmod_Json,
	.abi =		VMOD_ABI_Version,
	.file_id =	"e86f63ddc31f110e697165890f0d62fc3bac2844729cd8a3aced41236f20bb84",
};
