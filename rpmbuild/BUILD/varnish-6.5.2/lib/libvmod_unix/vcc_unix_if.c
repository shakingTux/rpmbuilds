/*
 * NB:  This file is machine generated, DO NOT EDIT!
 *
 * Edit ./vmod_unix.vcc and run make instead
 */

#include "config.h"
#include <stdio.h>
#include "vdef.h"
#include "vrt.h"
#include "vcc_unix_if.h"
#include "vmod_abi.h"


typedef VCL_STRING td_vmod_unix_user(VRT_CTX);
typedef VCL_STRING td_vmod_unix_group(VRT_CTX);
typedef VCL_INT td_vmod_unix_uid(VRT_CTX);
typedef VCL_INT td_vmod_unix_gid(VRT_CTX);

struct Vmod_vmod_unix_Func {
	td_vmod_unix_user		*user;
	td_vmod_unix_group		*group;
	td_vmod_unix_uid		*uid;
	td_vmod_unix_gid		*gid;
};

/*lint -esym(754, Vmod_vmod_unix_Func::*) */

static const struct Vmod_vmod_unix_Func Vmod_vmod_unix_Func = {
	.user =				vmod_user,
	.group =			vmod_group,
	.uid =				vmod_uid,
	.gid =				vmod_gid,

};

static const char Vmod_Proto[] =
	"#define VPFX(a) vmod_##a\n"
	"#define VARGS(a) arg_vmod_unix_##a\n"
	"#define VENUM(a) enum_vmod_unix_##a\n"
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
	"typedef VCL_STRING td_vmod_unix_user(VRT_CTX);\n"
	"typedef VCL_STRING td_vmod_unix_group(VRT_CTX);\n"
	"typedef VCL_INT td_vmod_unix_uid(VRT_CTX);\n"
	"typedef VCL_INT td_vmod_unix_gid(VRT_CTX);\n"
	"\n"
	"struct Vmod_vmod_unix_Func {\n"
	"	td_vmod_unix_user		*user;\n"
	"	td_vmod_unix_group		*group;\n"
	"	td_vmod_unix_uid		*uid;\n"
	"	td_vmod_unix_gid		*gid;\n"
	"};\n"
	"#undef VPFX\n"
	"#undef VARGS\n"
	"#undef VENUM\n"
	"static struct Vmod_vmod_unix_Func Vmod_vmod_unix_Func;";

static const char Vmod_Json[] = {
	"[ "
	"  [ "
	"    \"$VMOD\", "
	"    \"1.0\" "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"user\", "
	"    [ "
	"      [ "
	"        \"STRING\" "
	"      ], "
	"      \"Vmod_vmod_unix_Func.user\", "
	"      \"\" "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"group\", "
	"    [ "
	"      [ "
	"        \"STRING\" "
	"      ], "
	"      \"Vmod_vmod_unix_Func.group\", "
	"      \"\" "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"uid\", "
	"    [ "
	"      [ "
	"        \"INT\" "
	"      ], "
	"      \"Vmod_vmod_unix_Func.uid\", "
	"      \"\" "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"gid\", "
	"    [ "
	"      [ "
	"        \"INT\" "
	"      ], "
	"      \"Vmod_vmod_unix_Func.gid\", "
	"      \"\" "
	"    ] "
	"  ] "
	"]\n"
};

/*lint -esym(714, Vmod_unix_Data) */
/*lint -esym(759, Vmod_unix_Data) */
/*lint -esym(765, Vmod_unix_Data) */

extern const struct vmod_data Vmod_unix_Data;

const struct vmod_data Vmod_unix_Data = {
	.vrt_major =	0,
	.vrt_minor =	0,
	.name =		"unix",
	.func =		&Vmod_vmod_unix_Func,
	.func_len =	sizeof(Vmod_vmod_unix_Func),
	.func_name =	"Vmod_vmod_unix_Func",
	.proto =	Vmod_Proto,
	.json =		Vmod_Json,
	.abi =		VMOD_ABI_Version,
	.file_id =	"8a0aa56992f467a32ccec2e17273bc57d9088fd90beb71a10b41dc9242502455",
};
