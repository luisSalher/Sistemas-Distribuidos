/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "rand.h"


void
rand_prog_1(char *host, int itera)
{
	CLIENT *clnt;
	void  *result_1;
	long  inicializa_random_1_arg = 0;
	double  *result_2;
	char *obtiene_siguiente_random_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, RAND_PROG, RAND_VERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	result_1 = inicializa_random_1(&inicializa_random_1_arg, clnt);
	if (result_1 == (void *) NULL) {
		clnt_perror (clnt, "call failed");
	}

    for(int i = 0; i < itera; i++){
        result_2 = obtiene_siguiente_random_1((void*)&obtiene_siguiente_random_1_arg, clnt);
        if (result_2 == (double *) NULL) {
            clnt_perror (clnt, "call failed");
        }
        printf("%d: %f\n", i, *result_2);
    }

#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 3) {
		printf ("uso: %s server_host numero\n", argv[0]);
		exit (1);
	}
	
	host = argv[1];
	rand_prog_1 (host, atoi(argv[2]));

exit (0);
}
