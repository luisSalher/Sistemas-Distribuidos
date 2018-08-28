#include "Coordenada.h"
#include "PoligonoIrreg.h"
#include <iostream>
#include <math.h>

using namespace std;

int main(){
	int j = 0;
	int nVertices = 10;
	double coordenadaX = 0;
	double coordenadaY = 0;
    PoligonoIrreg poligono;
    
    for(j=0; j<nVertices; j++){
		coordenadaX = (rand() % MAXCOORD+1) - (MAXCOORD / 2);
		coordenadaY = (rand() % MAXCOORD+1) - (MAXCOORD / 2);
		coordenadaX = coordenadaX / (MAXCOORD + 1.1);
		coordenadaY = coordenadaY / (MAXCOORD + 1.1);
		coordenadaX = floor(coordenadaX * 100000) / 1000;
		coordenadaY = floor(coordenadaY * 100000) / 1000;
		poligono.anadeVertice(Coordenada(coordenadaX, coordenadaY));
    }

    poligono.imprimeVertices();

    poligono.ordenarVertices();
    cout << "Despues de ordenar" << endl;
    poligono.imprimeVertices();
    
    return 0;
}