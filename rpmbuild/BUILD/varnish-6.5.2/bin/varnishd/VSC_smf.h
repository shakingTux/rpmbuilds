/*
 * NB:  This file is machine generated, DO NOT EDIT!
 *
 * Edit smf.vsc and run lib/libvcc/vsctool.py instead.
 */

struct VSC_smf {
	uint64_t	c_req;
	uint64_t	c_fail;
	uint64_t	c_bytes;
	uint64_t	c_freed;
	uint64_t	g_alloc;
	uint64_t	g_bytes;
	uint64_t	g_space;
	uint64_t	g_smf;
	uint64_t	g_smf_frag;
	uint64_t	g_smf_large;
};

#define VSC_smf_size PRNDUP(sizeof(struct VSC_smf))

struct VSC_smf *VSC_smf_New(struct vsmw_cluster *,
    struct vsc_seg **, const char *fmt, ...);
void VSC_smf_Destroy(struct vsc_seg **);
