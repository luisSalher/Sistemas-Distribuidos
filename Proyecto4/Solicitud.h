#ifndef __SOLICITUD__
#define __SOLICITUD__

#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
#include "Mensaje.h"
#include <cstdio>
#include <cstdlib>
#define MAXSOLICITUDES 7

class Solicitud {
public:
    Solicitud();
    char *doOperation(char *IP, int puerto, int operationId, char *arguments);
private:
    SocketDatagrama *socketlocal;
    int peticion;
};
#endif