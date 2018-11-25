#include "Solicitud.h"
#include <thread>

#define pintar 1
#define borrar 2
using namespace std;

Solicitud cliente;
char *IP;

void pintarCoordenadas(){
    char coordenadas[] = "1,2";
    cliente.doOperation(IP, 7200, pintar, coordenadas);
}

void borrarCoordenadas(){
    char coordenadas[] = "1,2";
    cliente.doOperation(IP, 7200, borrar, coordenadas);
}

int main(int argc, char *argv[]){
    //Solicitud cliente;
    if(argc<3){
        printf("Uso: IP #Términos de la serie\n");
    }

    IP = argv[1];
    

    for(int i = 0; i < atoi(argv[2]); i++){
        thread th1(pintarCoordenadas);
        thread th2(borrarCoordenadas);
        th1.join();
        th2.join();
    }


    return 0;
}