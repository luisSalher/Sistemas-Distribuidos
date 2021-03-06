/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _OP_H_RPCGEN
#define _OP_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct NUM {
	float i;
	float j;
};
typedef struct NUM NUM;

#define OP_PROG 0x31111111
#define OP_VERS 1

#if defined(__STDC__) || defined(__cplusplus)
#define SUMA 1
extern  struct NUM * suma_1(struct NUM *, CLIENT *);
extern  struct NUM * suma_1_svc(struct NUM *, struct svc_req *);
#define PRODUCTO 2
extern  struct NUM * producto_1(struct NUM *, CLIENT *);
extern  struct NUM * producto_1_svc(struct NUM *, struct svc_req *);
#define COCIENTE 3
extern  struct NUM * cociente_1(struct NUM *, CLIENT *);
extern  struct NUM * cociente_1_svc(struct NUM *, struct svc_req *);
extern int op_prog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define SUMA 1
extern  struct NUM * suma_1();
extern  struct NUM * suma_1_svc();
#define PRODUCTO 2
extern  struct NUM * producto_1();
extern  struct NUM * producto_1_svc();
#define COCIENTE 3
extern  struct NUM * cociente_1();
extern  struct NUM * cociente_1_svc();
extern int op_prog_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_NUM (XDR *, NUM*);

#else /* K&R C */
extern bool_t xdr_NUM ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_OP_H_RPCGEN */
