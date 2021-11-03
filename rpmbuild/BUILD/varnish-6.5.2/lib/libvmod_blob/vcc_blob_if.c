/*
 * NB:  This file is machine generated, DO NOT EDIT!
 *
 * Edit ./vmod_blob.vcc and run make instead
 */

#include "config.h"
#include <stdio.h>
#include "vdef.h"
#include "vrt.h"
#include "vcc_blob_if.h"
#include "vmod_abi.h"

VCL_ENUM VENUM(BASE64) = "BASE64";
VCL_ENUM VENUM(BASE64URL) = "BASE64URL";
VCL_ENUM VENUM(BASE64URLNOPAD) = "BASE64URLNOPAD";
VCL_ENUM VENUM(DEFAULT) = "DEFAULT";
VCL_ENUM VENUM(HEX) = "HEX";
VCL_ENUM VENUM(IDENTITY) = "IDENTITY";
VCL_ENUM VENUM(LOWER) = "LOWER";
VCL_ENUM VENUM(UPPER) = "UPPER";
VCL_ENUM VENUM(URL) = "URL";

struct VPFX(blob_blob);
typedef VCL_VOID td_vmod_blob_blob__init(VRT_CTX,
    struct VPFX(blob_blob) **, const char *, VCL_ENUM, VCL_STRANDS);
typedef VCL_VOID td_vmod_blob_blob__fini(struct VPFX(
    blob_blob) **);
typedef VCL_BLOB td_vmod_blob_blob_get(VRT_CTX,
    struct VPFX(blob_blob) *);
typedef VCL_STRING td_vmod_blob_blob_encode(VRT_CTX,
    struct VPFX(blob_blob) *, VCL_ENUM, VCL_ENUM);

typedef VCL_BLOB td_vmod_blob_decode(VRT_CTX, VCL_ENUM, VCL_INT,
    VCL_STRANDS);
typedef VCL_STRING td_vmod_blob_encode(VRT_CTX, VCL_ENUM,
    VCL_ENUM, VCL_BLOB);
typedef VCL_STRING td_vmod_blob_transcode(VRT_CTX, VCL_ENUM,
    VCL_ENUM, VCL_ENUM, VCL_INT, VCL_STRANDS);
typedef VCL_BOOL td_vmod_blob_same(VRT_CTX, VCL_BLOB, VCL_BLOB);
typedef VCL_BOOL td_vmod_blob_equal(VRT_CTX, VCL_BLOB,
    VCL_BLOB);
typedef VCL_INT td_vmod_blob_length(VRT_CTX, VCL_BLOB);
typedef VCL_BLOB td_vmod_blob_sub(VRT_CTX, VCL_BLOB, VCL_BYTES,
    VCL_BYTES);

struct Vmod_vmod_blob_Func {
	td_vmod_blob_decode		*decode;
	td_vmod_blob_encode		*encode;
	td_vmod_blob_transcode		*transcode;
	td_vmod_blob_same		*same;
	td_vmod_blob_equal		*equal;
	td_vmod_blob_length		*length;
	td_vmod_blob_sub		*sub;
	td_vmod_blob_blob__init		*blob__init;
	td_vmod_blob_blob__fini		*blob__fini;
	td_vmod_blob_blob_get		*blob_get;
	td_vmod_blob_blob_encode	*blob_encode;

	VCL_ENUM			*enum_BASE64;
	VCL_ENUM			*enum_BASE64URL;
	VCL_ENUM			*enum_BASE64URLNOPAD;
	VCL_ENUM			*enum_DEFAULT;
	VCL_ENUM			*enum_HEX;
	VCL_ENUM			*enum_IDENTITY;
	VCL_ENUM			*enum_LOWER;
	VCL_ENUM			*enum_UPPER;
	VCL_ENUM			*enum_URL;
};

/*lint -esym(754, Vmod_vmod_blob_Func::*) */

static const struct Vmod_vmod_blob_Func Vmod_vmod_blob_Func = {
	.decode =			vmod_decode,
	.encode =			vmod_encode,
	.transcode =			vmod_transcode,
	.same =				vmod_same,
	.equal =			vmod_equal,
	.length =			vmod_length,
	.sub =				vmod_sub,
	.blob__init =			vmod_blob__init,
	.blob__fini =			vmod_blob__fini,
	.blob_get =			vmod_blob_get,
	.blob_encode =			vmod_blob_encode,


	.enum_BASE64 =			&VENUM(BASE64),
	.enum_BASE64URL =		&VENUM(BASE64URL),
	.enum_BASE64URLNOPAD =		&VENUM(BASE64URLNOPAD),
	.enum_DEFAULT =			&VENUM(DEFAULT),
	.enum_HEX =			&VENUM(HEX),
	.enum_IDENTITY =		&VENUM(IDENTITY),
	.enum_LOWER =			&VENUM(LOWER),
	.enum_UPPER =			&VENUM(UPPER),
	.enum_URL =			&VENUM(URL),
};

static const char Vmod_Proto[] =
	"#define VPFX(a) vmod_##a\n"
	"#define VARGS(a) arg_vmod_blob_##a\n"
	"#define VENUM(a) enum_vmod_blob_##a\n"
	"//lint -esym(755, VPFX)\n"
	"//lint -esym(767, VPFX)\n"
	"//lint -esym(755, VARGS)\n"
	"//lint -esym(767, VARGS)\n"
	"//lint -esym(755, VENUM)\n"
	"//lint -esym(767, VENUM)\n"
	"//lint -esym(755, VARGS)\n"
	"//lint -esym(755, VENUM)\n"
	"\n"
	"struct VPFX(blob_blob);\n"
	"typedef VCL_VOID td_vmod_blob_blob__init(VRT_CTX,\n"
	"    struct VPFX(blob_blob) **, const char *, VCL_ENUM, VCL_STRANDS);\n"
	"typedef VCL_VOID td_vmod_blob_blob__fini(struct VPFX(\n"
	"    blob_blob) **);\n"
	"typedef VCL_BLOB td_vmod_blob_blob_get(VRT_CTX,\n"
	"    struct VPFX(blob_blob) *);\n"
	"typedef VCL_STRING td_vmod_blob_blob_encode(VRT_CTX,\n"
	"    struct VPFX(blob_blob) *, VCL_ENUM, VCL_ENUM);\n"
	"\n"
	"/* Functions */\n"
	"typedef VCL_BLOB td_vmod_blob_decode(VRT_CTX, VCL_ENUM, VCL_INT,\n"
	"    VCL_STRANDS);\n"
	"typedef VCL_STRING td_vmod_blob_encode(VRT_CTX, VCL_ENUM,\n"
	"    VCL_ENUM, VCL_BLOB);\n"
	"typedef VCL_STRING td_vmod_blob_transcode(VRT_CTX, VCL_ENUM,\n"
	"    VCL_ENUM, VCL_ENUM, VCL_INT, VCL_STRANDS);\n"
	"typedef VCL_BOOL td_vmod_blob_same(VRT_CTX, VCL_BLOB, VCL_BLOB);\n"
	"typedef VCL_BOOL td_vmod_blob_equal(VRT_CTX, VCL_BLOB,\n"
	"    VCL_BLOB);\n"
	"typedef VCL_INT td_vmod_blob_length(VRT_CTX, VCL_BLOB);\n"
	"typedef VCL_BLOB td_vmod_blob_sub(VRT_CTX, VCL_BLOB, VCL_BYTES,\n"
	"    VCL_BYTES);\n"
	"\n"
	"struct Vmod_vmod_blob_Func {\n"
	"	td_vmod_blob_decode		*decode;\n"
	"	td_vmod_blob_encode		*encode;\n"
	"	td_vmod_blob_transcode		*transcode;\n"
	"	td_vmod_blob_same		*same;\n"
	"	td_vmod_blob_equal		*equal;\n"
	"	td_vmod_blob_length		*length;\n"
	"	td_vmod_blob_sub		*sub;\n"
	"	td_vmod_blob_blob__init		*blob__init;\n"
	"	td_vmod_blob_blob__fini		*blob__fini;\n"
	"	td_vmod_blob_blob_get		*blob_get;\n"
	"	td_vmod_blob_blob_encode	*blob_encode;\n"
	"\n"
	"	VCL_ENUM			*enum_BASE64;\n"
	"	VCL_ENUM			*enum_BASE64URL;\n"
	"	VCL_ENUM			*enum_BASE64URLNOPAD;\n"
	"	VCL_ENUM			*enum_DEFAULT;\n"
	"	VCL_ENUM			*enum_HEX;\n"
	"	VCL_ENUM			*enum_IDENTITY;\n"
	"	VCL_ENUM			*enum_LOWER;\n"
	"	VCL_ENUM			*enum_UPPER;\n"
	"	VCL_ENUM			*enum_URL;\n"
	"};\n"
	"#undef VPFX\n"
	"#undef VARGS\n"
	"#undef VENUM\n"
	"static struct Vmod_vmod_blob_Func Vmod_vmod_blob_Func;";

static const char Vmod_Json[] = {
	"[ "
	"  [ "
	"    \"$VMOD\", "
	"    \"1.0\" "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"decode\", "
	"    [ "
	"      [ "
	"        \"BLOB\" "
	"      ], "
	"      \"Vmod_vmod_blob_Func.decode\", "
	"      \"\", "
	"      [ "
	"        \"ENUM\", "
	"        \"decoding\", "
	"        \"IDENTITY\", "
	"        [ "
	"          \"IDENTITY\", "
	"          \"BASE64\", "
	"          \"BASE64URL\", "
	"          \"BASE64URLNOPAD\", "
	"          \"HEX\", "
	"          \"URL\" "
	"        ] "
	"      ], "
	"      [ "
	"        \"INT\", "
	"        \"length\", "
	"        \"0\" "
	"      ], "
	"      [ "
	"        \"STRANDS\", "
	"        \"encoded\" "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"encode\", "
	"    [ "
	"      [ "
	"        \"STRING\" "
	"      ], "
	"      \"Vmod_vmod_blob_Func.encode\", "
	"      \"\", "
	"      [ "
	"        \"ENUM\", "
	"        \"encoding\", "
	"        \"IDENTITY\", "
	"        [ "
	"          \"IDENTITY\", "
	"          \"BASE64\", "
	"          \"BASE64URL\", "
	"          \"BASE64URLNOPAD\", "
	"          \"HEX\", "
	"          \"URL\" "
	"        ] "
	"      ], "
	"      [ "
	"        \"ENUM\", "
	"        \"case\", "
	"        \"DEFAULT\", "
	"        [ "
	"          \"LOWER\", "
	"          \"UPPER\", "
	"          \"DEFAULT\" "
	"        ] "
	"      ], "
	"      [ "
	"        \"BLOB\", "
	"        \"blob\" "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"transcode\", "
	"    [ "
	"      [ "
	"        \"STRING\" "
	"      ], "
	"      \"Vmod_vmod_blob_Func.transcode\", "
	"      \"\", "
	"      [ "
	"        \"ENUM\", "
	"        \"decoding\", "
	"        \"IDENTITY\", "
	"        [ "
	"          \"IDENTITY\", "
	"          \"BASE64\", "
	"          \"BASE64URL\", "
	"          \"BASE64URLNOPAD\", "
	"          \"HEX\", "
	"          \"URL\" "
	"        ] "
	"      ], "
	"      [ "
	"        \"ENUM\", "
	"        \"encoding\", "
	"        \"IDENTITY\", "
	"        [ "
	"          \"IDENTITY\", "
	"          \"BASE64\", "
	"          \"BASE64URL\", "
	"          \"BASE64URLNOPAD\", "
	"          \"HEX\", "
	"          \"URL\" "
	"        ] "
	"      ], "
	"      [ "
	"        \"ENUM\", "
	"        \"case\", "
	"        \"DEFAULT\", "
	"        [ "
	"          \"LOWER\", "
	"          \"UPPER\", "
	"          \"DEFAULT\" "
	"        ] "
	"      ], "
	"      [ "
	"        \"INT\", "
	"        \"length\", "
	"        \"0\" "
	"      ], "
	"      [ "
	"        \"STRANDS\", "
	"        \"encoded\" "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"same\", "
	"    [ "
	"      [ "
	"        \"BOOL\" "
	"      ], "
	"      \"Vmod_vmod_blob_Func.same\", "
	"      \"\", "
	"      [ "
	"        \"BLOB\" "
	"      ], "
	"      [ "
	"        \"BLOB\" "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"equal\", "
	"    [ "
	"      [ "
	"        \"BOOL\" "
	"      ], "
	"      \"Vmod_vmod_blob_Func.equal\", "
	"      \"\", "
	"      [ "
	"        \"BLOB\" "
	"      ], "
	"      [ "
	"        \"BLOB\" "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"length\", "
	"    [ "
	"      [ "
	"        \"INT\" "
	"      ], "
	"      \"Vmod_vmod_blob_Func.length\", "
	"      \"\", "
	"      [ "
	"        \"BLOB\" "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"sub\", "
	"    [ "
	"      [ "
	"        \"BLOB\" "
	"      ], "
	"      \"Vmod_vmod_blob_Func.sub\", "
	"      \"\", "
	"      [ "
	"        \"BLOB\" "
	"      ], "
	"      [ "
	"        \"BYTES\", "
	"        \"length\" "
	"      ], "
	"      [ "
	"        \"BYTES\", "
	"        \"offset\", "
	"        \"0\" "
	"      ] "
	"    ] "
	"  ], "
	"  [ "
	"    \"$OBJ\", "
	"    \"blob\", "
	"    { "
	"      \"NULL_OK\": false "
	"    }, "
	"    \"struct vmod_blob_blob\", "
	"    [ "
	"      \"$INIT\", "
	"      [ "
	"        [ "
	"          \"VOID\" "
	"        ], "
	"        \"Vmod_vmod_blob_Func.blob__init\", "
	"        \"\", "
	"        [ "
	"          \"ENUM\", "
	"          \"decoding\", "
	"          \"IDENTITY\", "
	"          [ "
	"            \"IDENTITY\", "
	"            \"BASE64\", "
	"            \"BASE64URL\", "
	"            \"BASE64URLNOPAD\", "
	"            \"HEX\", "
	"            \"URL\" "
	"          ] "
	"        ], "
	"        [ "
	"          \"STRANDS\", "
	"          \"encoded\" "
	"        ] "
	"      ] "
	"    ], "
	"    [ "
	"      \"$FINI\", "
	"      [ "
	"        [ "
	"          \"VOID\" "
	"        ], "
	"        \"Vmod_vmod_blob_Func.blob__fini\", "
	"        \"\" "
	"      ] "
	"    ], "
	"    [ "
	"      \"$METHOD\", "
	"      \"get\", "
	"      [ "
	"        [ "
	"          \"BLOB\" "
	"        ], "
	"        \"Vmod_vmod_blob_Func.blob_get\", "
	"        \"\" "
	"      ] "
	"    ], "
	"    [ "
	"      \"$METHOD\", "
	"      \"encode\", "
	"      [ "
	"        [ "
	"          \"STRING\" "
	"        ], "
	"        \"Vmod_vmod_blob_Func.blob_encode\", "
	"        \"\", "
	"        [ "
	"          \"ENUM\", "
	"          \"encoding\", "
	"          \"IDENTITY\", "
	"          [ "
	"            \"IDENTITY\", "
	"            \"BASE64\", "
	"            \"BASE64URL\", "
	"            \"BASE64URLNOPAD\", "
	"            \"HEX\", "
	"            \"URL\" "
	"          ] "
	"        ], "
	"        [ "
	"          \"ENUM\", "
	"          \"case\", "
	"          \"DEFAULT\", "
	"          [ "
	"            \"LOWER\", "
	"            \"UPPER\", "
	"            \"DEFAULT\" "
	"          ] "
	"        ] "
	"      ] "
	"    ] "
	"  ] "
	"]\n"
};

/*lint -esym(714, Vmod_blob_Data) */
/*lint -esym(759, Vmod_blob_Data) */
/*lint -esym(765, Vmod_blob_Data) */

extern const struct vmod_data Vmod_blob_Data;

const struct vmod_data Vmod_blob_Data = {
	.vrt_major =	0,
	.vrt_minor =	0,
	.name =		"blob",
	.func =		&Vmod_vmod_blob_Func,
	.func_len =	sizeof(Vmod_vmod_blob_Func),
	.func_name =	"Vmod_vmod_blob_Func",
	.proto =	Vmod_Proto,
	.json =		Vmod_Json,
	.abi =		VMOD_ABI_Version,
	.file_id =	"5406c9235d04124205635d0e071c25aa583c34eee88e463c4a69292b68137492",
};
