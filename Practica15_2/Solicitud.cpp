#include "Solicitud.h"
#include <cstdlib>
#include <cstring>

Solicitud::Solicitud() {
    socketlocal = new SocketDatagrama(0);
    peticion = 0;
}

char * Solicitud::doOperation(char *IP, int puerto, int operationId, char *arguments) {
    int contador = 0;
    struct mensaje *msj = (struct mensaje *) malloc(sizeof(struct mensaje));
    msj->messageType = 0;
    msj->requestId = peticion++;
    memcpy(msj->IP, IP, strlen(IP));
    msj->puerto = puerto;
    msj->operationId = operationId;
    memcpy(msj->arguments, arguments, strlen(arguments));

    PaqueteDatagrama paquete(sizeof(struct mensaje));
    paquete.inicializaIp(IP);
    paquete.inicializaPuerto(puerto);
    paquete.inicializaDatos((char *)msj);

    PaqueteDatagrama respuesta(sizeof(struct mensaje));
    socketlocal->envia(paquete);

    while((socketlocal->recibeTimeout(respuesta, 0, 500000) == -1) && contador < MAXSOLICITUDES) {
        contador++;
        //socketlocal->recibeTimeout(respuesta, 0, 500000);
        //socketlocal->recibe(respuesta);
        socketlocal->envia(paquete);
        printf("...\n");
    }

    struct mensaje *msj_respuesta = (struct mensaje *) malloc(sizeof(mensaje));

    msj_respuesta = (struct mensaje *) respuesta.obtieneDatos();

    return msj_respuesta->arguments;
}



