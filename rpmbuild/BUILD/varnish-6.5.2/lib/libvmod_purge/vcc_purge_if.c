/*
 * NB:  This file is machine generated, DO NOT EDIT!
 *
 * Edit ./vmod_purge.vcc and run make instead
 */

#include "config.h"
#include <stdio.h>
#include "vdef.h"
#include "vrt.h"
#include "vcc_purge_if.h"
#include "vmod_abi.h"


typedef VCL_INT td_vmod_purge_hard(VRT_CTX);
typedef VCL_INT td_vmod_purge_soft(VRT_CTX, VCL_DURATION,
    VCL_DURATION, VCL_DURATION);

struct Vmod_vmod_purge_Func {
	td_vmod_purge_hard		*hard;
	td_vmod_purge_soft		*soft;
};

/*lint -esym(754, Vmod_vmod_purge_Func::*) */

static const struct Vmod_vmod_purge_Func Vmod_vmod_purge_Func = {
	.hard =				vmod_hard,
	.soft =				vmod_soft,

};

static const char Vmod_Proto[] =
	"#define VPFX(a) vmod_##a\n"
	"#define VARGS(a) arg_vmod_purge_##a\n"
	"#define VENUM(a) enum_vmod_purge_##a\n"
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
	"typedef VCL_INT td_vmod_purge_hard(VRT_CTX);\n"
	"typedef VCL_INT td_vmod_purge_soft(VRT_CTX, VCL_DURATION,\n"
	"    VCL_DURATION, VCL_DURATION);\n"
	"\n"
	"struct Vmod_vmod_purge_Func {\n"
	"	td_vmod_purge_hard		*hard;\n"
	"	td_vmod_purge_soft		*soft;\n"
	"};\n"
	"#undef VPFX\n"
	"#undef VARGS\n"
	"#undef VENUM\n"
	"static struct Vmod_vmod_purge_Func Vmod_vmod_purge_Func;";

static const char Vmod_Json[] = {
	"[ "
	"  [ "
	"    \"$VMOD\", "
	"    \"1.0\" "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"hard\", "
	"    [ "
	"      [ "
	"        \"INT\" "
	"      ], "
	"      \"Vmod_vmod_purge_Func.hard\", "
	"      \"\" "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"soft\", "
	"    [ "
	"      [ "
	"        \"INT\" "
	"      ], "
	"      \"Vmod_vmod_purge_Func.soft\", "
	"      \"\", "
	"      [ "
	"        \"DURATION\", "
	"        \"ttl\", "
	"        \"0\" "
	"      ], "
	"      [ "
	"        \"DURATION\", "
	"        \"grace\", "
	"        \"-1\" "
	"      ], "
	"      [ "
	"        \"DURATION\", "
	"        \"keep\", "
	"        \"-1\" "
	"      ] "
	"    ] "
	"  ] "
	"]\n"
};

/*lint -esym(714, Vmod_purge_Data) */
/*lint -esym(759, Vmod_purge_Data) */
/*lint -esym(765, Vmod_purge_Data) */

extern const struct vmod_data Vmod_purge_Data;

const struct vmod_data Vmod_purge_Data = {
	.vrt_major =	0,
	.vrt_minor =	0,
	.name =		"purge",
	.func =		&Vmod_vmod_purge_Func,
	.func_len =	sizeof(Vmod_vmod_purge_Func),
	.func_name =	"Vmod_vmod_purge_Func",
	.proto =	Vmod_Proto,
	.json =		Vmod_Json,
	.abi =		VMOD_ABI_Version,
	.file_id =	"c9c4dcec5374aa74bc575bf8eb4b14ea3a397cf7f9b76c92e61f6d445c272954",
};
