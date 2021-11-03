/*
 * NB:  This file is machine generated, DO NOT EDIT!
 *
 * Edit mempool.vsc and run lib/libvcc/vsctool.py instead.
 */

struct VSC_mempool {
	uint64_t	live;
	uint64_t	pool;
	uint64_t	sz_wanted;
	uint64_t	sz_actual;
	uint64_t	allocs;
	uint64_t	frees;
	uint64_t	recycle;
	uint64_t	timeout;
	uint64_t	toosmall;
	uint64_t	surplus;
	uint64_t	randry;
};

#define VSC_mempool_size PRNDUP(sizeof(struct VSC_mempool))

struct VSC_mempool *VSC_mempool_New(struct vsmw_cluster *,
    struct vsc_seg **, const char *fmt, ...);
void VSC_mempool_Destroy(struct vsc_seg **);
