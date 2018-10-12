#include "SocketDatagrama.h"
#include "Mensaje.h"
#include "Respuesta.h"
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char*argv[]) {
    Respuesta respuesta(7200);

    while(true) {
        printf("%s\n", "ESPERANDO...");
        struct mensaje *msg = respuesta.getRequest();
        string cadenaInvertida = "Respuesta del servidor";

        respuesta.sendReply((char *)cadenaInvertida.c_str(), msg->IP, msg->puerto);
    }
}