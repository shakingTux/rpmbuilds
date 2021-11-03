/*
 * NB:  This file is machine generated, DO NOT EDIT!
 *
 * Edit lck.vsc and run lib/libvcc/vsctool.py instead.
 */

struct VSC_lck {
	uint64_t	creat;
	uint64_t	destroy;
	uint64_t	locks;
	uint64_t	dbg_busy;
	uint64_t	dbg_try_fail;
};

#define VSC_lck_size PRNDUP(sizeof(struct VSC_lck))

struct VSC_lck *VSC_lck_New(struct vsmw_cluster *,
    struct vsc_seg **, const char *fmt, ...);
void VSC_lck_Destroy(struct vsc_seg **);
