/*
 * NB:  This file is machine generated, DO NOT EDIT!
 *
 * Edit lck.vsc and run lib/libvcc/vsctool.py instead.
 */

#include "config.h"
#include <stdio.h>
#include <stdarg.h>
#include "vdef.h"
#include "vas.h"
#include "vrt.h"
#include "VSC_lck.h"

static const char vsc_lck_name[] = "LCK";

#define PARANOIA(a,n)				\
    v_static_assert(				\
	offsetof(struct VSC_lck, a) == n,	\
	"VSC element '" #a "' at wrong offset")

PARANOIA(creat, 0);
PARANOIA(destroy, 8);
PARANOIA(locks, 16);
PARANOIA(dbg_busy, 24);
PARANOIA(dbg_try_fail, 32);
#undef PARANOIA

static const unsigned char vsc_lck_json[1492] = {
	123,34,118,101,114,115,105,111,110,34,58,34,49,34,44,34,110,97,109,101,
	34,58,34,108,99,107,34,44,34,111,110,101,108,105,110,101,114,34,58,34,
	76,111,99,107,32,67,111,117,110,116,101,114,115,34,44,34,111,114,100,
	101,114,34,58,55,48,44,34,100,111,99,115,34,58,34,92,116,67,111,117,
	110,116,101,114,115,32,119,104,105,99,104,32,116,114,97,99,107,32,116,
	104,101,32,97,99,116,105,118,105,116,121,32,105,110,32,116,104,101,32,
	100,105,102,102,101,114,101,110,116,32,99,108,97,115,115,101,115,92,
	110,92,116,111,102,32,109,117,116,101,120,45,108,111,99,107,115,46,92,
	110,92,110,92,116,84,104,101,32,99,111,117,110,116,115,32,109,97,121,
	32,98,101,32,115,108,105,103,104,116,108,121,32,119,114,111,110,103,
	32,105,102,32,116,104,101,114,101,32,97,114,101,32,109,111,114,101,32,
	116,104,97,110,32,111,110,101,92,110,92,116,108,111,99,107,32,105,110,
	115,116,97,110,116,105,97,116,101,100,32,105,110,32,101,97,99,104,32,
	99,108,97,115,115,32,40,105,101,58,32,46,99,114,101,97,116,32,62,32,
	49,41,34,44,34,101,108,101,109,101,110,116,115,34,58,53,44,34,101,108,
	101,109,34,58,123,34,99,114,101,97,116,34,58,123,34,116,121,112,101,
	34,58,34,99,111,117,110,116,101,114,34,44,34,99,116,121,112,101,34,58,
	34,117,105,110,116,54,52,95,116,34,44,34,108,101,118,101,108,34,58,34,
	100,101,98,117,103,34,44,34,111,110,101,108,105,110,101,114,34,58,34,
	67,114,101,97,116,101,100,32,108,111,99,107,115,34,44,34,102,111,114,
	109,97,116,34,58,34,105,110,116,101,103,101,114,34,44,34,105,110,100,
	101,120,34,58,48,44,34,110,97,109,101,34,58,34,99,114,101,97,116,34,
	44,34,100,111,99,115,34,58,34,34,125,44,34,100,101,115,116,114,111,121,
	34,58,123,34,116,121,112,101,34,58,34,99,111,117,110,116,101,114,34,
	44,34,99,116,121,112,101,34,58,34,117,105,110,116,54,52,95,116,34,44,
	34,108,101,118,101,108,34,58,34,100,101,98,117,103,34,44,34,111,110,
	101,108,105,110,101,114,34,58,34,68,101,115,116,114,111,121,101,100,
	32,108,111,99,107,115,34,44,34,102,111,114,109,97,116,34,58,34,105,110,
	116,101,103,101,114,34,44,34,105,110,100,101,120,34,58,56,44,34,110,
	97,109,101,34,58,34,100,101,115,116,114,111,121,34,44,34,100,111,99,
	115,34,58,34,34,125,44,34,108,111,99,107,115,34,58,123,34,116,121,112,
	101,34,58,34,99,111,117,110,116,101,114,34,44,34,99,116,121,112,101,
	34,58,34,117,105,110,116,54,52,95,116,34,44,34,108,101,118,101,108,34,
	58,34,100,101,98,117,103,34,44,34,111,110,101,108,105,110,101,114,34,
	58,34,76,111,99,107,32,79,112,101,114,97,116,105,111,110,115,34,44,34,
	102,111,114,109,97,116,34,58,34,105,110,116,101,103,101,114,34,44,34,
	105,110,100,101,120,34,58,49,54,44,34,110,97,109,101,34,58,34,108,111,
	99,107,115,34,44,34,100,111,99,115,34,58,34,34,125,44,34,100,98,103,
	95,98,117,115,121,34,58,123,34,116,121,112,101,34,58,34,99,111,117,110,
	116,101,114,34,44,34,99,116,121,112,101,34,58,34,117,105,110,116,54,
	52,95,116,34,44,34,108,101,118,101,108,34,58,34,100,101,98,117,103,34,
	44,34,111,110,101,108,105,110,101,114,34,58,34,67,111,110,116,101,110,
	100,101,100,32,108,111,99,107,32,111,112,101,114,97,116,105,111,110,
	115,34,44,34,102,111,114,109,97,116,34,58,34,105,110,116,101,103,101,
	114,34,44,34,105,110,100,101,120,34,58,50,52,44,34,110,97,109,101,34,
	58,34,100,98,103,95,98,117,115,121,34,44,34,100,111,99,115,34,58,34,
	92,116,73,102,32,116,104,101,32,96,96,108,99,107,96,96,32,100,101,98,
	117,103,32,98,105,116,32,105,115,32,115,101,116,58,32,76,111,99,107,
	32,111,112,101,114,97,116,105,111,110,115,32,119,104,105,99,104,92,110,
	92,116,114,101,116,117,114,110,101,100,32,69,66,85,83,89,32,111,110,
	32,116,104,101,32,102,105,114,115,116,32,108,111,99,107,105,110,103,
	32,97,116,116,101,109,112,116,46,92,110,92,110,92,116,73,102,32,116,
	104,101,32,96,96,108,99,107,96,96,32,100,101,98,117,103,32,98,105,116,
	32,105,115,32,117,110,115,101,116,44,32,116,104,105,115,32,99,111,117,
	110,116,101,114,32,119,105,108,108,32,110,101,118,101,114,32,98,101,
	92,110,92,116,105,110,99,114,101,109,101,110,116,101,100,32,101,118,
	101,110,32,105,102,32,108,111,99,107,32,111,112,101,114,97,116,105,111,
	110,115,32,97,114,101,32,99,111,110,116,101,110,100,101,100,46,34,125,
	44,34,100,98,103,95,116,114,121,95,102,97,105,108,34,58,123,34,116,121,
	112,101,34,58,34,99,111,117,110,116,101,114,34,44,34,99,116,121,112,
	101,34,58,34,117,105,110,116,54,52,95,116,34,44,34,108,101,118,101,108,
	34,58,34,100,101,98,117,103,34,44,34,111,110,101,108,105,110,101,114,
	34,58,34,67,111,110,116,101,110,100,101,100,32,116,114,121,108,111,99,
	107,32,111,112,101,114,97,116,105,111,110,115,34,44,34,102,111,114,109,
	97,116,34,58,34,105,110,116,101,103,101,114,34,44,34,105,110,100,101,
	120,34,58,51,50,44,34,110,97,109,101,34,58,34,100,98,103,95,116,114,
	121,95,102,97,105,108,34,44,34,100,111,99,115,34,58,34,92,116,73,102,
	32,116,104,101,32,96,96,108,99,107,96,96,32,100,101,98,117,103,32,98,
	105,116,32,105,115,32,115,101,116,58,32,84,114,121,108,111,99,107,32,
	111,112,101,114,97,116,105,111,110,115,32,119,104,105,99,104,92,110,
	92,116,114,101,116,117,114,110,101,100,32,69,66,85,83,89,46,92,110,92,
	110,92,116,73,102,32,116,104,101,32,96,96,108,99,107,96,96,32,100,101,
	98,117,103,32,98,105,116,32,105,115,32,117,110,115,101,116,44,32,116,
	104,105,115,32,99,111,117,110,116,101,114,32,119,105,108,108,32,110,
	101,118,101,114,32,98,101,92,110,92,116,105,110,99,114,101,109,101,110,
	116,101,100,32,101,118,101,110,32,105,102,32,108,111,99,107,32,111,112,
	101,114,97,116,105,111,110,115,32,97,114,101,32,99,111,110,116,101,110,
	100,101,100,46,34,125,125,125,0
};

// {
//   "version": "1",
//   "name": "lck",
//   "oneliner": "Lock Counters",
//   "order": 70,
//   "docs": "\tCounters which track the activity in the different class[...]
//   "elements": 5,
//   "elem": {
//     "creat": {
//       "type": "counter",
//       "ctype": "uint64_t",
//       "level": "debug",
//       "oneliner": "Created locks",
//       "format": "integer",
//       "index": 0,
//       "name": "creat",
//       "docs": ""
//     },
//     "destroy": {
//       "type": "counter",
//       "ctype": "uint64_t",
//       "level": "debug",
//       "oneliner": "Destroyed locks",
//       "format": "integer",
//       "index": 8,
//       "name": "destroy",
//       "docs": ""
//     },
//     "locks": {
//       "type": "counter",
//       "ctype": "uint64_t",
//       "level": "debug",
//       "oneliner": "Lock Operations",
//       "format": "integer",
//       "index": 16,
//       "name": "locks",
//       "docs": ""
//     },
//     "dbg_busy": {
//       "type": "counter",
//       "ctype": "uint64_t",
//       "level": "debug",
//       "oneliner": "Contended lock operations",
//       "format": "integer",
//       "index": 24,
//       "name": "dbg_busy",
//       "docs": "\tIf the ``lck`` debug bit is set: Lock operations whi[...]
//     },
//     "dbg_try_fail": {
//       "type": "counter",
//       "ctype": "uint64_t",
//       "level": "debug",
//       "oneliner": "Contended trylock operations",
//       "format": "integer",
//       "index": 32,
//       "name": "dbg_try_fail",
//       "docs": "\tIf the ``lck`` debug bit is set: Trylock operations [...]
//     }
//   }
// }


struct VSC_lck*
VSC_lck_New(struct vsmw_cluster *vc,
    struct vsc_seg **sg, const char *fmt, ...)
{
	va_list ap;
	struct VSC_lck *retval;

	va_start(ap, fmt);
	retval = VRT_VSC_Alloc(vc, sg, vsc_lck_name, VSC_lck_size,
	    vsc_lck_json, sizeof vsc_lck_json, fmt, ap);
	va_end(ap);
	return(retval);
}

void
VSC_lck_Destroy(struct vsc_seg **sg)
{
	struct vsc_seg *p;

	AN(sg);
	p = *sg;
	*sg = NULL;
	VRT_VSC_Destroy(vsc_lck_name, p);
}
