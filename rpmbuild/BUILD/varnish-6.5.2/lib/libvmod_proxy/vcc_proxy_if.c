/*
 * NB:  This file is machine generated, DO NOT EDIT!
 *
 * Edit ./vmod_proxy.vcc and run make instead
 */

#include "config.h"
#include <stdio.h>
#include "vdef.h"
#include "vrt.h"
#include "vcc_proxy_if.h"
#include "vmod_abi.h"


typedef VCL_STRING td_vmod_proxy_alpn(VRT_CTX);
typedef VCL_STRING td_vmod_proxy_authority(VRT_CTX);
typedef VCL_BOOL td_vmod_proxy_is_ssl(VRT_CTX);
typedef VCL_BOOL td_vmod_proxy_client_has_cert_sess(VRT_CTX);
typedef VCL_BOOL td_vmod_proxy_client_has_cert_conn(VRT_CTX);
typedef VCL_INT td_vmod_proxy_ssl_verify_result(VRT_CTX);
typedef VCL_STRING td_vmod_proxy_ssl_version(VRT_CTX);
typedef VCL_STRING td_vmod_proxy_client_cert_cn(VRT_CTX);
typedef VCL_STRING td_vmod_proxy_ssl_cipher(VRT_CTX);
typedef VCL_STRING td_vmod_proxy_cert_sign(VRT_CTX);
typedef VCL_STRING td_vmod_proxy_cert_key(VRT_CTX);

struct Vmod_vmod_proxy_Func {
	td_vmod_proxy_alpn		*alpn;
	td_vmod_proxy_authority		*authority;
	td_vmod_proxy_is_ssl		*is_ssl;
	td_vmod_proxy_client_has_cert_sess
					*client_has_cert_sess;
	td_vmod_proxy_client_has_cert_conn
					*client_has_cert_conn;
	td_vmod_proxy_ssl_verify_result	*ssl_verify_result;
	td_vmod_proxy_ssl_version	*ssl_version;
	td_vmod_proxy_client_cert_cn	*client_cert_cn;
	td_vmod_proxy_ssl_cipher	*ssl_cipher;
	td_vmod_proxy_cert_sign		*cert_sign;
	td_vmod_proxy_cert_key		*cert_key;
};

/*lint -esym(754, Vmod_vmod_proxy_Func::*) */

static const struct Vmod_vmod_proxy_Func Vmod_vmod_proxy_Func = {
	.alpn =				vmod_alpn,
	.authority =			vmod_authority,
	.is_ssl =			vmod_is_ssl,
	.client_has_cert_sess =		vmod_client_has_cert_sess,
	.client_has_cert_conn =		vmod_client_has_cert_conn,
	.ssl_verify_result =		vmod_ssl_verify_result,
	.ssl_version =			vmod_ssl_version,
	.client_cert_cn =		vmod_client_cert_cn,
	.ssl_cipher =			vmod_ssl_cipher,
	.cert_sign =			vmod_cert_sign,
	.cert_key =			vmod_cert_key,

};

static const char Vmod_Proto[] =
	"#define VPFX(a) vmod_##a\n"
	"#define VARGS(a) arg_vmod_proxy_##a\n"
	"#define VENUM(a) enum_vmod_proxy_##a\n"
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
	"typedef VCL_STRING td_vmod_proxy_alpn(VRT_CTX);\n"
	"typedef VCL_STRING td_vmod_proxy_authority(VRT_CTX);\n"
	"typedef VCL_BOOL td_vmod_proxy_is_ssl(VRT_CTX);\n"
	"typedef VCL_BOOL td_vmod_proxy_client_has_cert_sess(VRT_CTX);\n"
	"typedef VCL_BOOL td_vmod_proxy_client_has_cert_conn(VRT_CTX);\n"
	"typedef VCL_INT td_vmod_proxy_ssl_verify_result(VRT_CTX);\n"
	"typedef VCL_STRING td_vmod_proxy_ssl_version(VRT_CTX);\n"
	"typedef VCL_STRING td_vmod_proxy_client_cert_cn(VRT_CTX);\n"
	"typedef VCL_STRING td_vmod_proxy_ssl_cipher(VRT_CTX);\n"
	"typedef VCL_STRING td_vmod_proxy_cert_sign(VRT_CTX);\n"
	"typedef VCL_STRING td_vmod_proxy_cert_key(VRT_CTX);\n"
	"\n"
	"struct Vmod_vmod_proxy_Func {\n"
	"	td_vmod_proxy_alpn		*alpn;\n"
	"	td_vmod_proxy_authority		*authority;\n"
	"	td_vmod_proxy_is_ssl		*is_ssl;\n"
	"	td_vmod_proxy_client_has_cert_sess\n"
	"					*client_has_cert_sess;\n"
	"	td_vmod_proxy_client_has_cert_conn\n"
	"					*client_has_cert_conn;\n"
	"	td_vmod_proxy_ssl_verify_result	*ssl_verify_result;\n"
	"	td_vmod_proxy_ssl_version	*ssl_version;\n"
	"	td_vmod_proxy_client_cert_cn	*client_cert_cn;\n"
	"	td_vmod_proxy_ssl_cipher	*ssl_cipher;\n"
	"	td_vmod_proxy_cert_sign		*cert_sign;\n"
	"	td_vmod_proxy_cert_key		*cert_key;\n"
	"};\n"
	"#undef VPFX\n"
	"#undef VARGS\n"
	"#undef VENUM\n"
	"static struct Vmod_vmod_proxy_Func Vmod_vmod_proxy_Func;";

static const char Vmod_Json[] = {
	"[ "
	"  [ "
	"    \"$VMOD\", "
	"    \"1.0\" "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"alpn\", "
	"    [ "
	"      [ "
	"        \"STRING\" "
	"      ], "
	"      \"Vmod_vmod_proxy_Func.alpn\", "
	"      \"\" "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"authority\", "
	"    [ "
	"      [ "
	"        \"STRING\" "
	"      ], "
	"      \"Vmod_vmod_proxy_Func.authority\", "
	"      \"\" "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"is_ssl\", "
	"    [ "
	"      [ "
	"        \"BOOL\" "
	"      ], "
	"      \"Vmod_vmod_proxy_Func.is_ssl\", "
	"      \"\" "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"client_has_cert_sess\", "
	"    [ "
	"      [ "
	"        \"BOOL\" "
	"      ], "
	"      \"Vmod_vmod_proxy_Func.client_has_cert_sess\", "
	"      \"\" "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"client_has_cert_conn\", "
	"    [ "
	"      [ "
	"        \"BOOL\" "
	"      ], "
	"      \"Vmod_vmod_proxy_Func.client_has_cert_conn\", "
	"      \"\" "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"ssl_verify_result\", "
	"    [ "
	"      [ "
	"        \"INT\" "
	"      ], "
	"      \"Vmod_vmod_proxy_Func.ssl_verify_result\", "
	"      \"\" "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"ssl_version\", "
	"    [ "
	"      [ "
	"        \"STRING\" "
	"      ], "
	"      \"Vmod_vmod_proxy_Func.ssl_version\", "
	"      \"\" "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"client_cert_cn\", "
	"    [ "
	"      [ "
	"        \"STRING\" "
	"      ], "
	"      \"Vmod_vmod_proxy_Func.client_cert_cn\", "
	"      \"\" "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"ssl_cipher\", "
	"    [ "
	"      [ "
	"        \"STRING\" "
	"      ], "
	"      \"Vmod_vmod_proxy_Func.ssl_cipher\", "
	"      \"\" "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"cert_sign\", "
	"    [ "
	"      [ "
	"        \"STRING\" "
	"      ], "
	"      \"Vmod_vmod_proxy_Func.cert_sign\", "
	"      \"\" "
	"    ] "
	"  ], "
	"  [ "
	"    \"$FUNC\", "
	"    \"cert_key\", "
	"    [ "
	"      [ "
	"        \"STRING\" "
	"      ], "
	"      \"Vmod_vmod_proxy_Func.cert_key\", "
	"      \"\" "
	"    ] "
	"  ] "
	"]\n"
};

/*lint -esym(714, Vmod_proxy_Data) */
/*lint -esym(759, Vmod_proxy_Data) */
/*lint -esym(765, Vmod_proxy_Data) */

extern const struct vmod_data Vmod_proxy_Data;

const struct vmod_data Vmod_proxy_Data = {
	.vrt_major =	0,
	.vrt_minor =	0,
	.name =		"proxy",
	.func =		&Vmod_vmod_proxy_Func,
	.func_len =	sizeof(Vmod_vmod_proxy_Func),
	.func_name =	"Vmod_vmod_proxy_Func",
	.proto =	Vmod_Proto,
	.json =		Vmod_Json,
	.abi =		VMOD_ABI_Version,
	.file_id =	"d70181dc5487d8058209d6535f413d21a5d049eb5a02b3c03d000b791a735e99",
};
