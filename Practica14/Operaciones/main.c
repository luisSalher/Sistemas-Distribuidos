#include "operaciones.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    struct Terminos terminos;

    if (argc < 3) {
        printf("%s\n", "Faltan parametros");
        return -1;
    }

    terminos.a = atoi(argv[1]);
    terminos.b = atoi(argv[2]);

    printf("%d + %d = %f \n", terminos.a, terminos.b, suma(terminos));
    printf("%d * %d = %f \n", terminos.a, terminos.b, producto(terminos));
    printf("%d / %d = %f \n", terminos.a, terminos.b, cociente(terminos));

    return 0;
}