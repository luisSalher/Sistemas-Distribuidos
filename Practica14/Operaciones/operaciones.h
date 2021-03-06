/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _OPERACIONES_H_RPCGEN
#define _OPERACIONES_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct Terminos {
	double a;
	double b;
	double resultado;
};
typedef struct Terminos Terminos;

#define OPERACIONES_PROG 0x31111111
#define OPERACIONES_VERS 1

#if defined(__STDC__) || defined(__cplusplus)
#define SUMA 1
extern  struct Terminos * suma_1(struct Terminos *, CLIENT *);
extern  struct Terminos * suma_1_svc(struct Terminos *, struct svc_req *);
#define PRODUCTO 2
extern  struct Terminos * producto_1(struct Terminos *, CLIENT *);
extern  struct Terminos * producto_1_svc(struct Terminos *, struct svc_req *);
#define COCIENTE 3
extern  struct Terminos * cociente_1(struct Terminos *, CLIENT *);
extern  struct Terminos * cociente_1_svc(struct Terminos *, struct svc_req *);
extern int operaciones_prog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define SUMA 1
extern  struct Terminos * suma_1();
extern  struct Terminos * suma_1_svc();
#define PRODUCTO 2
extern  struct Terminos * producto_1();
extern  struct Terminos * producto_1_svc();
#define COCIENTE 3
extern  struct Terminos * cociente_1();
extern  struct Terminos * cociente_1_svc();
extern int operaciones_prog_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_Terminos (XDR *, Terminos*);

#else /* K&R C */
extern bool_t xdr_Terminos ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_OPERACIONES_H_RPCGEN */
