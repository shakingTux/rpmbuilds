/*
 * NB:  This file is machine generated, DO NOT EDIT!
 *
 * Edit vbe.vsc and run lib/libvcc/vsctool.py instead.
 */

struct VSC_vbe {
	uint64_t	happy;
	uint64_t	bereq_hdrbytes;
	uint64_t	bereq_bodybytes;
	uint64_t	beresp_hdrbytes;
	uint64_t	beresp_bodybytes;
	uint64_t	pipe_hdrbytes;
	uint64_t	pipe_out;
	uint64_t	pipe_in;
	uint64_t	conn;
	uint64_t	req;
	uint64_t	unhealthy;
	uint64_t	busy;
	uint64_t	fail;
	uint64_t	fail_eacces;
	uint64_t	fail_eaddrnotavail;
	uint64_t	fail_econnrefused;
	uint64_t	fail_enetunreach;
	uint64_t	fail_etimedout;
	uint64_t	fail_other;
	uint64_t	helddown;
};

#define VSC_vbe_size PRNDUP(sizeof(struct VSC_vbe))

struct VSC_vbe *VSC_vbe_New(struct vsmw_cluster *,
    struct vsc_seg **, const char *fmt, ...);
void VSC_vbe_Destroy(struct vsc_seg **);
