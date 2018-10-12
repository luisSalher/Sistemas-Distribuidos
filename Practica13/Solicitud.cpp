#include "Solicitud.h"

Solicitud::Solicitud(){
	socketlocal = new SocketDatagrama(0);
}

char *Solicitud::doOperation(char *IP, int puerto, int operationId, char *arguments){
	struct mensaje *msj = (struct mensaje *) malloc(sizeof(mensaje));
	msj->messageType = 0;
    msj->requestId = 1;
    memcpy(msj->IP, IP, strlen(IP));
    msj->puerto = puerto;
    msj->operationId = operationId;
    memcpy(msj->arguments, arguments, strlen(arguments));

    PaqueteDatagrama paquete(sizeof(mensaje));
    paquete.inicializaIp(IP);
    paquete.inicializaPuerto(puerto);
    paquete.inicializaDatos((char *)msj);
    socketlocal->envia(paquete);

    printf("\nMENSAJE Solicitud: \n");
    printf("messageType: %d\n", msj->messageType);
    printf("requestId: %d\n", msj->requestId);
    printf("IP: %s\n", msj->IP);
    printf("puerto: %d\n", msj->puerto);
    printf("operationId: %d\n", msj->operationId);
    printf("arguments: %s\n", msj->arguments);

    PaqueteDatagrama respuesta(sizeof(struct mensaje));
    //socketlocal->recibe(respuesta);
    printf("Recibidos: %d\n", socketlocal->recibe(respuesta));
    struct mensaje *msj_respuesta = (struct mensaje *) malloc(sizeof(mensaje));
    msj_respuesta = (struct mensaje *) respuesta.obtieneDatos();

    printf("\nMENSAJE Recibido: \n");
    printf("messageType: %d\n", msj_respuesta->messageType);
    printf("requestId: %d\n", msj_respuesta->requestId);
    printf("IP: %s\n", msj_respuesta->IP);
    printf("puerto: %d\n", msj_respuesta->puerto);
    printf("operationId: %d\n", msj_respuesta->operationId);
    printf("arguments: %s\n", msj_respuesta->arguments);

    return msj_respuesta->arguments;
}







