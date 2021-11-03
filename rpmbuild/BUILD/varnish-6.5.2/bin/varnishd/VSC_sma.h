/*
 * NB:  This file is machine generated, DO NOT EDIT!
 *
 * Edit sma.vsc and run lib/libvcc/vsctool.py instead.
 */

struct VSC_sma {
	uint64_t	c_req;
	uint64_t	c_fail;
	uint64_t	c_bytes;
	uint64_t	c_freed;
	uint64_t	g_alloc;
	uint64_t	g_bytes;
	uint64_t	g_space;
};

#define VSC_sma_size PRNDUP(sizeof(struct VSC_sma))

struct VSC_sma *VSC_sma_New(struct vsmw_cluster *,
    struct vsc_seg **, const char *fmt, ...);
void VSC_sma_Destroy(struct vsc_seg **);
