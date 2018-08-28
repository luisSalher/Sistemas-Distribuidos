#include "Coordenada.h"
#include "PoligonoIrreg.h"
#include <iostream>

using namespace std;

int main(){
	int j = 0;
	int coordenadaX = 0;
	int coordenadaY = 0;
	int nVertices = 10;
    PoligonoIrreg poligono;
    
    for(j=0; j<nVertices; j++){
		coordenadaX = (rand() % MAXCOORD+1) - (MAXCOORD / 2);
		coordenadaY = (rand() % MAXCOORD+1) - (MAXCOORD / 2);
		poligono.anadeVertice(Coordenada(coordenadaX, coordenadaY));
    }
    poligono.imprimeVertices();
    /*poligono.anadeVertice(Coordenada(1,2));
    poligono.imprimeVertices();
    
    poligono.anadeVertice(Coordenada(5,6));
    poligono.imprimeVertices();

    poligono.anadeVertice(Coordenada(8,12));
    poligono.imprimeVertices();*/
    
    return 0;
}