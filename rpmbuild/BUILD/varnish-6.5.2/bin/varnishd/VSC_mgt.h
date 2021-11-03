/*
 * NB:  This file is machine generated, DO NOT EDIT!
 *
 * Edit mgt.vsc and run lib/libvcc/vsctool.py instead.
 */

struct VSC_mgt {
	uint64_t	uptime;
	uint64_t	child_start;
	uint64_t	child_exit;
	uint64_t	child_stop;
	uint64_t	child_died;
	uint64_t	child_dump;
	uint64_t	child_panic;
};

#define VSC_mgt_size PRNDUP(sizeof(struct VSC_mgt))

struct VSC_mgt *VSC_mgt_New(struct vsmw_cluster *,
    struct vsc_seg **, const char *fmt, ...);
void VSC_mgt_Destroy(struct vsc_seg **);
