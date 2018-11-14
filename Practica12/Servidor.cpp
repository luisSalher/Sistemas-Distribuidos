#include "SocketDatagrama.h"
#include <iostream>
#define PUERTO 7201

int main(int argc, char const *argv[]) {
    printf("%s\n", "SERVIDOR");
    unsigned int *num;
    int primo;

    SocketDatagrama socketCliente(PUERTO);
    PaqueteDatagrama paquete(2*sizeof(double));

    while(1) {
        printf("%s\n", "ESPERANDO...");
        printf("Recibidos = %d\n", socketCliente.recibe(paquete));
        num=(unsigned  int *)paquete.obtieneDatos();
        cout << "Numero a analizar: " << num[0] << endl;
        cout << "Limite inferior: " << num[1] << endl;
        cout << "Limite superior: " << num[2] << endl;
        
        printf("Mensaje de: %s:%d\n", paquete.obtieneDireccion(), paquete.obtienePuerto());
        
        primo = 0;
        for(int i = num[1]; i < num[2]; i++){
            if(num[0] % i ==0){
                primo = 1;
                i = num[2];
            }
        }
        cout << primo << endl;
        PaqueteDatagrama p((char *)&primo, sizeof(primo) * sizeof(int), paquete.obtieneDireccion(), paquete.obtienePuerto());
        socketCliente.envia(p);
    }

    return 0;
}
