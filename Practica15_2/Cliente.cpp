#include "Solicitud.h"
using namespace std;

int main(int argc, char *argv[]){
    Solicitud cliente;
    if(argc<3){
        printf("Uso: IP #iteraciones\n");
    }

    int lectura=1;
    int escritura=2;
    int saldo=0;
    int nuevoSaldo=0;
    char cadena[] = " ";

    for(int i = 0; i < atoi(argv[2]); i++){
        saldo=atoi(cliente.doOperation(argv[1], 7200, lectura, cadena));
        printf("Operación: Consulta. Saldo: %d\n", saldo);
        nuevoSaldo=atoi(cliente.doOperation(argv[1], 7200, escritura, cadena));
        printf("Operación: Depósito. Nuevo Saldo: %d\n", nuevoSaldo);
        if(nuevoSaldo != saldo+1){
            printf("Error en los saldos\n");
            exit(0);
        }
    }

    return 0;
}