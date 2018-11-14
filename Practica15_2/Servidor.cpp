#include "SocketDatagrama.h"
#include "Mensaje.h"
#include "Respuesta.h"
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>

int main(int argc, char*argv[])
{
    int nbd = 0;
    string nbdS = " ";
    Respuesta respuesta(7200);
    struct mensaje *msg;
    int idrequestLast = -1;
    int idrequest = -1;
    
    while(true) {
        msg = respuesta.getRequest();
        idrequest = msg->requestId ;
        if (idrequest <= idrequestLast) {
            printf("RequestID: %d\n",msg -> requestId);
            printf("LAST RequestID: %d\n",idrequestLast);
            printf("Llego Tarde\n");
            continue;
            //respuesta.sendReply((char *)nbdS.c_str(), msg->IP, msg->puerto);
        }
        if(msg->operationId == 1){
            printf("%s\n", "operationId 1");
            nbdS = to_string(nbd);
            printf("Saldo: %d\n",nbd);
            respuesta.sendReply((char *)nbdS.c_str(), msg->IP, msg->puerto);
        }
        else if(msg->operationId == 2){
            printf("%s\n", "operationId 2");
            nbd+=1;
            nbdS = to_string(nbd);
            printf("Saldo: %d\n",nbd);
            respuesta.sendReply((char *)nbdS.c_str(), msg->IP, msg->puerto);
            printf("Enviando: %d\n",nbd);
        }
        idrequestLast = msg->requestId;
        
    }
}
