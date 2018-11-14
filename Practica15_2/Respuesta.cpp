#include "Respuesta.h"
#include "Mensaje.h"

Respuesta::Respuesta(int port){
    socketlocal = new SocketDatagrama(port);
}

struct mensaje* Respuesta::getRequest(void){
    PaqueteDatagrama p(sizeof(struct mensaje));
    int tam = socketlocal->recibe(p);
    //int tam = socketlocal->recibeTimeout(p, 1, 500000);
    struct mensaje * msg = (struct mensaje*) p.obtieneDatos();
    struct mensaje *recibido = (struct mensaje *)malloc(sizeof(struct mensaje));
    recibido->messageType = msg->messageType;
    recibido->requestId = msg->requestId;
    memset(recibido->IP, '\0', 16);
    memcpy(recibido->IP, p.obtieneDireccion(), strlen(p.obtieneDireccion()));
    recibido->puerto = p.obtienePuerto();
    recibido->operationId = msg->operationId;
    memcpy(recibido->arguments, msg->arguments, strlen(msg->arguments));

    return recibido;
}

void Respuesta::sendReply(char *respuesta, char *ipCliente, int puertoCliente){
    struct mensaje *msj = (struct mensaje *) malloc(sizeof(struct mensaje));
    memcpy(msj->arguments, respuesta, strlen(respuesta));
    msj->messageType = 1;
    PaqueteDatagrama p((char *)msj, sizeof(struct mensaje), ipCliente, puertoCliente);
    socketlocal->envia(p);
}