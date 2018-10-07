#include "SocketDatagrama.h"
#include <iostream>

#define PUERTO 7200
#define PUERTO1 7201
#define PUERTO2 7202

int main(int argc, char const *argv[]) {
    
    char *server_ip = "127.0.0.1";
    char *server_ip2 = "127.0.0.10";
    char *server_ip3 = "127.0.0.20";
    unsigned int mensaje1[3];
    unsigned int mensaje2[3];
    unsigned int mensaje3[3];
    unsigned int n=4294967291;

    printf("%s\n", "CLIENTE");

    SocketDatagrama socketCliente(6666);
    printf("%s\n", "ENVIANDO PAQUETE...");
    mensaje1[0] = n;
    mensaje1[1] = 1;
    mensaje1[2] = n/3;
    mensaje2[0] = n;
    mensaje2[1] = mensaje1[2] + 1;
    mensaje2[2] = (n/3) * 2;
    mensaje3[0] = n;
    mensaje3[1] = mensaje2[2] + 1;
    mensaje3[2] = n - 1;
    PaqueteDatagrama paquete1((char *)mensaje1, sizeof(mensaje1) * sizeof(int), server_ip, PUERTO);
    PaqueteDatagrama paquete2((char *)mensaje2, sizeof(mensaje2) * sizeof(int), server_ip, PUERTO1);
    PaqueteDatagrama paquete3((char *)mensaje3, sizeof(mensaje3) * sizeof(int), server_ip, PUERTO2);
    printf("Mandando paquete a: %s:%d\n", paquete1.obtieneDireccion(), paquete1.obtienePuerto());
    
    
    socketCliente.envia(paquete1);
    socketCliente.envia(paquete2);
    socketCliente.envia(paquete3);
    printf("%s\n", "PAQUETE ENVIADO");
    
    socketCliente.recibe(paquete1);
    socketCliente.recibe(paquete2);
    socketCliente.recibe(paquete3);
    
    printf("\nPaquete recibido de: %s:%d \n", paquete1.obtieneDireccion(), PUERTO);
    printf("\nPaquete recibido de: %s:%d \n", paquete2.obtieneDireccion(), PUERTO1);
    printf("\nPaquete recibido de: %s:%d \n", paquete3.obtieneDireccion(), PUERTO2);
    
    unsigned int *num1 = (unsigned int *)paquete1.obtieneDatos();
    unsigned int *num2 = (unsigned int *)paquete2.obtieneDatos();
    unsigned int *num3 = (unsigned int *)paquete3.obtieneDatos();
    
     printf("%d,%d,%d\n",num1[0],num2[0],num3[0]);

    return 0;
} 

