/*
 * NB:  This file is machine generated, DO NOT EDIT!
 *
 * Edit smu.vsc and run lib/libvcc/vsctool.py instead.
 */

struct VSC_smu {
	uint64_t	c_req;
	uint64_t	c_fail;
	uint64_t	c_bytes;
	uint64_t	c_freed;
	uint64_t	g_alloc;
	uint64_t	g_bytes;
	uint64_t	g_space;
};

#define VSC_smu_size PRNDUP(sizeof(struct VSC_smu))

struct VSC_smu *VSC_smu_New(struct vsmw_cluster *,
    struct vsc_seg **, const char *fmt, ...);
void VSC_smu_Destroy(struct vsc_seg **);
