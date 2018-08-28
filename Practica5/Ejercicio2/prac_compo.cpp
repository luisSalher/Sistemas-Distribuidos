#include "Coordenada.h"
#include "PoligonoIrreg.h"
#include <iostream>

using namespace std;

int main(){
    PoligonoIrreg poligono;
    
    poligono.anadeVertice(Coordenada(1,2));
    poligono.imprimeVertices();
    
    poligono.anadeVertice(Coordenada(5,6));
    poligono.imprimeVertices();

    poligono.anadeVertice(Coordenada(8,12));
    poligono.imprimeVertices();
    
    return 0;
}