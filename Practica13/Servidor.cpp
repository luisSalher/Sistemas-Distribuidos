#include "SocketDatagrama.h"
#include "Mensaje.h"
#include "Respuesta.h"
using namespace std;

int main(int argc, char*argv[]) {
    int longitudCadena = 0;
    int contador = 0;
    int i = 0;
    int j = 0;
    Respuesta respuesta(7200);

    while(true) {
        printf("%s\n", "ESPERANDO...");
        struct mensaje *msg = respuesta.getRequest();

        string cadenaRecibida = msg->arguments;
        string cadenaInvertida = "";
        longitudCadena = cadenaRecibida.length();

        // Se invierten las palabras de la cadena
        
        respuesta.sendReply((char *)cadenaInvertida.c_str(), msg->IP, msg->puerto);
    }

}