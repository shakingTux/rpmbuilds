/*
 * NB:  This file is machine generated, DO NOT EDIT!
 *
 * Edit ./vmod_cookie.vcc and run make instead
 */

#include "config.h"
#include <stdio.h>
#include "vdef.h"
#include "vrt.h"
#include "vcc_cookie_if.h"
#include "vmod_abi.h"


typedef VCL_VOID td_vmod_cookie_clean(VRT_CTX,
    struct vmod_priv *);
typedef VCL_VOID td_vmod_cookie_delete(VRT_CTX,
    struct vmod_priv *, VCL_STRING);
typedef VCL_VOID td_vmod_cookie_filter(VRT_CTX,
    struct vmod_priv *, VCL_STRING);
typedef VCL_VOID td_vmod_cookie_filter_re(VRT_CTX,
    struct vmod_priv *, struct vmod_priv *, VCL_STRING);
typedef VCL_VOID td_vmod_cookie_keep(VRT_CTX,
    struct vmod_priv *, VCL_STRING);
typedef VCL_VOID td_vmod_cookie_keep_re(VRT_CTX,
    struct vmod_priv *, struct vmod_priv *, VCL_STRING);
typedef VCL_STRING td_vmod_cookie_format_rfc1123(VRT_CTX,
    VCL_TIME, VCL_DURATION);
typedef VCL_STRING td_vmod_cookie_get(VRT_CTX,
    struct vmod_priv *, VCL_STRING);
typedef VCL_STRING td_vmod_cookie_get_re(VRT_CTX,
    struct vmod_priv *, struct vmod_priv *, VCL_STRING);
typedef VCL_STRING td_vmod_cookie_get_string(VRT_CTX,
    struct vmod_priv *);
typedef VCL_BOOL td_vmod_cookie_isset(VRT_CTX,
    struct vmod_priv *, VCL_STRING);
typedef VCL_VOID td_vmod_cookie_parse(VRT_CTX,
    struct vmod_priv *, VCL_STRING);
typedef VCL_VOID td_vmod_cookie_set(VRT_CTX, struct vmod_priv *,
    VCL_STRING, VCL_STRING);

struct Vmod_vmod_cookie_Func {
	td_vmod_cookie_clean		*clean;
	td_vmod_cookie_delete		*delete;
	td_vmod_cookie_filter		*filter;
	td_vmod_cookie_filter_re	*filter_re;
	td_vmod_cookie_keep		*keep;
	td_vmod_cookie_keep_re		*keep_re;
	td_vmod_cookie_format_rfc1123	*format_rfc1123;
	td_vmod_cookie_get		*get;
	td_vmod_cookie_get_re		*get_re;
	td_vmod_cookie_get_string	*get_string;
	td_vmod_cookie_isset		*isset;
	td_vmod_cookie_parse		*parse;
	td_vmod_cookie_set		*set;
};

/*lint -esym(754, Vmod_vmod_cookie_Func::*) */

static const struct Vmod_vmod_cookie_Func Vmod_vmod_cookie_Func = {
	.clean =			vmod_clean,
	.delete =			vmod_delete,
	.filter =			vmod_filter,
	.filter_re =			vmod_filter_re,
	.keep =				vmod_keep,
	.keep_re =			vmod_keep_re,
	.format_rfc1123 =		vmod_format_rfc1123,
	.get =				vmod_get,
	.get_re =			vmod_get_re,
	.get_string =			vmod_get_string,
	.isset =			vmod_isset,
	.parse =			vmod_parse,
	.set =				vmod_set,

};

static const char Vmod_Proto[] =
	"#define VPFX(a) vmod_##a\n"
	"#define VARGS(a) arg_vmod_cookie_##a\n"
	"#define VENUM(a) enum_vmod_cookie_##a\n"
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
	"typedef VCL_VOID td_vmod_cookie_clean(VRT_CTX,\n"
	"    struct vmod_priv *);\n"
	"typedef VCL_VOID td_vmod_cookie_delete(VRT_CTX,\n"
	"    struct vmod_priv *, VCL_STRING);\n"
	"typedef VCL_VOID td_vmod_cookie_filter(VRT_CTX,\n"
	"    struct vmod_priv *, VCL_STRING);\n"
	"typedef VCL_VOID td_vmod_cookie_filter_re(VRT_CTX,\n"
	"    struct vmod_priv *, struct vmod_priv *, VCL_STRING);\n"
	"typedef VCL_VOID td_vmod_cookie_keep(VRT_CTX,\n"
	"    struct vmod_priv *, VCL_STRING);\n"
	"typedef VCL_VOID td_vmod_cookie_keep_re(VRT_CTX,\n"
	"    struct vmod_priv *, struct vmod_priv *, VCL_STRING);\n"
	"typedef VCL_STRING td_vmod_cookie_format_rfc1123(VRT_CTX,\n"
	"    VCL_TIME, VCL_DURATION);\n"
	"typedef VCL_STRING td_vmod_cookie_get(VRT_CTX,\n"
	"    struct vmod_priv *, VCL_STRING);\n"
	"typedef VCL_STRING td_vmod_cookie_get_re(VRT_CTX,\n"
	"    struct vmod_priv *, struct vmod_priv *, VCL_STRING);\n"
	"typedef VCL_STRING td_vmod_cookie_get_string(VRT_CTX,\n"
	"    struct vmod_priv *);\n"
	"typedef VCL_BOOL td_vmod_cookie_isset(VRT_CTX,\n"
	"    struct vmod_priv *, VCL_STRING);\n"
	"typedef VCL_VOID td_vmod_cookie_parse(VRT_CTX,\n"
	"    struct vmod_priv *, VCL_STRING);\n"
	"typedef VCL_VOID td_vmod_cookie_set(VRT_CTX, struct vmod_priv *,\n"
	"    VCL_STRING, VCL_STRING);\n"
	"\n"
	"struct Vmod_vmod_cookie_Func {\n"
	"	td_vmod_cookie_clean		*clean;\n"
	"	td_vmod_cookie_delete		*delete;\n"
	"	td_vmod_cookie_filter		*filter;\n"
	"	td_vmod_cookie_filter_re	*filter_re;\n"
	"	td_vmod_cookie_keep		*keep;\n"
	"	td_vmod_cookie_keep_re		*keep_re;\n"
	"	td_vmod_cookie_format_rfc1123	*format_rfc1123;\n"
	"	td_vmod_cookie_get		*get;\n"
	"	td_vmod_cookie_get_re		*get_re;\n"
	"	td_vmod_cookie_get_string	*get_string;\n"
	"	td_vmod_cookie_isset		*isset;\n"
	"	td_vmod_cookie_parse		*parse;\n"
	"	td_vmod_cookie_set		*set;\n"
	"};\n"
	"#undef VPFX\n"
	"#undef VARGS\n"
	"#undef VENUM\n"
	"static struct Vmod_vmod_cookie_Func Vmod_vmod_cookie_Func;";

static const char Vmod_Json[] = {
	"[ "
	"  [ "
	"    \"$VMOD\", "
	"    \"1.0\" "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"clean\", "
	"    [ "
	"      [ "
	"        \"VOID\" "
	"      ], "
	"      \"Vmod_vmod_cookie_Func.clean\", "
	"      \"\", "
	"      [ "
	"        \"PRIV_TASK\" "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"delete\", "
	"    [ "
	"      [ "
	"        \"VOID\" "
	"      ], "
	"      \"Vmod_vmod_cookie_Func.delete\", "
	"      \"\", "
	"      [ "
	"        \"PRIV_TASK\" "
	"      ], "
	"      [ "
	"        \"STRING\", "
	"        \"cookiename\" "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"filter\", "
	"    [ "
	"      [ "
	"        \"VOID\" "
	"      ], "
	"      \"Vmod_vmod_cookie_Func.filter\", "
	"      \"\", "
	"      [ "
	"        \"PRIV_TASK\" "
	"      ], "
	"      [ "
	"        \"STRING\", "
	"        \"filterstring\" "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"filter_re\", "
	"    [ "
	"      [ "
	"        \"VOID\" "
	"      ], "
	"      \"Vmod_vmod_cookie_Func.filter_re\", "
	"      \"\", "
	"      [ "
	"        \"PRIV_TASK\" "
	"      ], "
	"      [ "
	"        \"PRIV_CALL\" "
	"      ], "
	"      [ "
	"        \"STRING\", "
	"        \"expression\" "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"keep\", "
	"    [ "
	"      [ "
	"        \"VOID\" "
	"      ], "
	"      \"Vmod_vmod_cookie_Func.keep\", "
	"      \"\", "
	"      [ "
	"        \"PRIV_TASK\" "
	"      ], "
	"      [ "
	"        \"STRING\", "
	"        \"filterstring\" "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"keep_re\", "
	"    [ "
	"      [ "
	"        \"VOID\" "
	"      ], "
	"      \"Vmod_vmod_cookie_Func.keep_re\", "
	"      \"\", "
	"      [ "
	"        \"PRIV_TASK\" "
	"      ], "
	"      [ "
	"        \"PRIV_CALL\" "
	"      ], "
	"      [ "
	"        \"STRING\", "
	"        \"expression\" "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"format_rfc1123\", "
	"    [ "
	"      [ "
	"        \"STRING\" "
	"      ], "
	"      \"Vmod_vmod_cookie_Func.format_rfc1123\", "
	"      \"\", "
	"      [ "
	"        \"TIME\", "
	"        \"now\" "
	"      ], "
	"      [ "
	"        \"DURATION\", "
	"        \"timedelta\" "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"get\", "
	"    [ "
	"      [ "
	"        \"STRING\" "
	"      ], "
	"      \"Vmod_vmod_cookie_Func.get\", "
	"      \"\", "
	"      [ "
	"        \"PRIV_TASK\" "
	"      ], "
	"      [ "
	"        \"STRING\", "
	"        \"cookiename\" "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"get_re\", "
	"    [ "
	"      [ "
	"        \"STRING\" "
	"      ], "
	"      \"Vmod_vmod_cookie_Func.get_re\", "
	"      \"\", "
	"      [ "
	"        \"PRIV_TASK\" "
	"      ], "
	"      [ "
	"        \"PRIV_CALL\" "
	"      ], "
	"      [ "
	"        \"STRING\", "
	"        \"expression\" "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"get_string\", "
	"    [ "
	"      [ "
	"        \"STRING\" "
	"      ], "
	"      \"Vmod_vmod_cookie_Func.get_string\", "
	"      \"\", "
	"      [ "
	"        \"PRIV_TASK\" "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"isset\", "
	"    [ "
	"      [ "
	"        \"BOOL\" "
	"      ], "
	"      \"Vmod_vmod_cookie_Func.isset\", "
	"      \"\", "
	"      [ "
	"        \"PRIV_TASK\" "
	"      ], "
	"      [ "
	"        \"STRING\", "
	"        \"cookiename\" "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"parse\", "
	"    [ "
	"      [ "
	"        \"VOID\" "
	"      ], "
	"      \"Vmod_vmod_cookie_Func.parse\", "
	"      \"\", "
	"      [ "
	"        \"PRIV_TASK\" "
	"      ], "
	"      [ "
	"        \"STRING\", "
	"        \"cookieheader\" "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"set\", "
	"    [ "
	"      [ "
	"        \"VOID\" "
	"      ], "
	"      \"Vmod_vmod_cookie_Func.set\", "
	"      \"\", "
	"      [ "
	"        \"PRIV_TASK\" "
	"      ], "
	"      [ "
	"        \"STRING\", "
	"        \"cookiename\" "
	"      ], "
	"      [ "
	"        \"STRING\", "
	"        \"value\" "
	"      ] "
	"    ] "
	"  ] "
	"]\n"
};

/*lint -esym(714, Vmod_cookie_Data) */
/*lint -esym(759, Vmod_cookie_Data) */
/*lint -esym(765, Vmod_cookie_Data) */

extern const struct vmod_data Vmod_cookie_Data;

const struct vmod_data Vmod_cookie_Data = {
	.vrt_major =	0,
	.vrt_minor =	0,
	.name =		"cookie",
	.func =		&Vmod_vmod_cookie_Func,
	.func_len =	sizeof(Vmod_vmod_cookie_Func),
	.func_name =	"Vmod_vmod_cookie_Func",
	.proto =	Vmod_Proto,
	.json =		Vmod_Json,
	.abi =		VMOD_ABI_Version,
	.file_id =	"58d49d41d5e5725332fcf704fad0bc54729b2954eda8b781c8227bef822a4ec4",
};
