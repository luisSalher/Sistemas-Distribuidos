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
    
    while(true) {
        msg = respuesta.getRequest();

        if(msg->operationId == 1){
            printf("%s\n", "operationId 1");
            nbdS = to_string(nbd);
            respuesta.sendReply((char *)nbdS.c_str(), msg->IP, msg->puerto);
        } 
        else if(msg->operationId == 2){
            printf("%s\n", "operationId 2");
            msg = respuesta.getRequest();
            nbd+=1;
            nbdS = to_string(nbd);
            respuesta.sendReply((char *)nbdS.c_str(), msg->IP, msg->puerto);
        }
    }
}
