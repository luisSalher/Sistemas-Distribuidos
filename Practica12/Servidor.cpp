#include "SocketDatagrama.h"
#define PUERTO 7200

int main(int argc, char const *argv[]) {
    printf("%s\n", "SERVIDOR");

    SocketDatagrama socketCliente(PUERTO);
    PaqueteDatagrama paquete(2*sizeof(double));

    while(1) {
        printf("%s\n", "ESPERANDO...");
        printf("Recibidos = %d\n", socketCliente.recibe(paquete));
        printf("Mensaje de: %s:%d\n", paquete.obtieneDireccion(), paquete.obtienePuerto());   
    }

    return 0;
}