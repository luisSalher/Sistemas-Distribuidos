#include "Solicitud.h"

int main(int argc, char *argv[]) {
    if(argc<3){
        printf("indicar Puerto del servidor\n");
        return -1;
    }

    Solicitud cliente;
    char cadena[] = "Only love is all maroon";
    int ordenaCadena = 1;

    //for (int i=0; i<500; i++)
    printf("La respuesta del servidor es <%s>\n", cliente.doOperation(argv[1], atoi(argv[2]), ordenaCadena, cadena));

    return 0;
}
