#include "SocketDatagrama.h"
#include "Mensaje.h"
#include "Respuesta.h"
#include <cstdio>
#include <cstring>
#include <string>
#include <string.h>
#include <cstdlib>
#include <thread>

int main(int argc, char*argv[])
{
    //int nbd = 0;
    string coordenadas = " ";
    string coordenadasRecibidas = " ";
    Respuesta respuesta(7200);
    struct mensaje *msg;
    int idrequestLast = -1;
    int idrequest = -1;
    
    while(true) {
        msg = respuesta.getRequest();
        idrequest = msg->requestId;
        coordenadasRecibidas = msg->arguments; //Guardamos las coordenadas recibidas
        if (idrequest <= idrequestLast) {
            printf("RequestID: %d\n",msg -> requestId);
            printf("LAST RequestID: %d\n",idrequestLast);
            printf("Llego Tarde\n");
            continue;
            //respuesta.sendReply((char *)coordenadas.c_str(), msg->IP, msg->puerto); //Este se queda comentado
        }
        if(msg->operationId == 1){
            printf("\n%s\n", "operationId 1 -> Pintar");
            printf("%s\n",coordenadasRecibidas.c_str());
            respuesta.sendReply((char *)coordenadas.c_str(), msg->IP, msg->puerto);
        }
        else if(msg->operationId == 2){
            printf("%s\n", "operationId 2 -> Borrar");
            printf("%s\n",coordenadasRecibidas.c_str());
            respuesta.sendReply((char *)coordenadas.c_str(), msg->IP, msg->puerto);
        }
        idrequestLast = msg->requestId;       
    }
}




