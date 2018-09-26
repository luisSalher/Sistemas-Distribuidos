#include "SocketDatagrama.h"

#define PUERTO 7200

int main(int argc, char const *argv[]) {

    printf("%s\n", "CLIENTE");

    SocketDatagrama socketCliente(6666);
    printf("%s\n", "ENVIANDO PAQUETE...");
    float a[1];
    a[0] = 877;

    PaqueteDatagrama paquete((char *)a, 4, (char *) "127.0.0.1", PUERTO);
    printf("Mandando paquete a: %s:%d\n", paquete.obtieneDireccion(), paquete.obtienePuerto());
    
    socketCliente.envia(paquete);
    printf("%s\n", "PAQUETE ENVIADO");

    return 0;
}
