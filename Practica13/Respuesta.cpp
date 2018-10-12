#include "Respuesta.h"

Respuesta::Respuesta(int port){
	socketlocal = new SocketDatagrama(port);
}

struct mensaje* Respuesta::getRequest(void){
    PaqueteDatagrama p(sizeof(struct mensaje));
    //socketlocal->recibe(p);
    printf("Recibidos: %d\n", socketlocal->recibe(p));

    struct mensaje * msg = (struct mensaje*) p.obtieneDatos();
    struct mensaje *recibido = (struct mensaje *)malloc(sizeof(mensaje));

    recibido->messageType = msg->messageType;
    recibido->requestId = msg->requestId;
    memset(recibido->IP, '\0', 16);
    memcpy(recibido->IP, p.obtieneDireccion(), strlen(p.obtieneDireccion()));
    recibido->puerto = p.obtienePuerto();
    recibido->operationId = msg->operationId;
    memcpy(recibido->arguments, msg->arguments, strlen(msg->arguments));

    printf("\nMENSAJE Recibido: \n");
    printf("messageType: %d\n", recibido->messageType);
    printf("requestId: %d\n", recibido->requestId);
    printf("IP: %s\n", recibido->IP);
    printf("puerto: %d\n", recibido->puerto);
    printf("operationId: %d\n", recibido->operationId);
    printf("arguments: %s\n", recibido->arguments);

    return recibido;
}

void Respuesta::sendReply(char *respuesta, char *ipCliente, int puertoCliente){
    struct mensaje *msj = (struct mensaje *) malloc(sizeof(struct mensaje));

    memcpy(msj->arguments, respuesta, strlen(respuesta));
    msj->messageType = 1;

    PaqueteDatagrama p((char *)msj, sizeof(struct mensaje), ipCliente, puertoCliente);

    printf("\nMENSAJE Respuesta: \n");
    printf("messageType: %d\n", msj->messageType);
    printf("requestId: %d\n", msj->requestId);
    printf("IP: %s\n", msj->IP);
    printf("puerto: %d\n", msj->puerto);
    printf("operationId: %d\n", msj->operationId);
    printf("arguments: %s\n", msj->arguments);

    printf("\nPAQUETE: %s\n", p.obtieneDatos());
    printf("IP cliente: %s\n", p.obtieneDireccion());
    printf("Puerto cliente: %d\n", p.obtienePuerto());

    socketlocal->envia(p);
}



