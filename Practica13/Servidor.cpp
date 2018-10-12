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

        string cadenarecibida = msg->arguments;
        string cadenaInvertida = "";
        printf("%s\n", cadenaInvertida.c_str());

        // Se invierten las palabras de la cadena
        for(i = ; i<strlen(cadenarecibida); i++){
            if(cadenarecibida[i] != ' '){
                cadenaInvertida[i] = cadenarecibida[i];
            }
        }



        respuesta.sendReply((char *)cadenaInvertida.c_str(), msg->IP, msg->puerto);
    }
}