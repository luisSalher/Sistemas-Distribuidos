#include "Coordenada.h"
#include "PoligonoIrreg.h"
#include <iostream>

using namespace std;

/*
 * Uso del método reserve para agregar elementos al vector de Poligonos irregulares
 * Prueba con 30 poligonos con un número aleatorio entre 0 y 10 de vértices con coordenadas aleatorias entre 0 y 10
 */

int main(){
    
    int i = 0;
    int j = 0;
    int vertices = 0;
    int coordenadaX = 0;
    int coordenadaY = 0;

    vector<PoligonoIrreg> poligonos(NPOLIGONOS);

    for(i=0; i<NPOLIGONOS; i++){
        //cout << "\n Primer for: i=" << i <<"\n";
        vertices = rand() % MAXVERT;
        //cout << "\n Numero de vertices: " << vertices <<"\n";
        poligonos.reserve(NPOLIGONOS);
    	for(j=0; j<vertices; j++){
            //cout << "\n\t Segundo for: j=" << j <<"\n";
    		coordenadaX = rand() % MAXCOORD;
    		coordenadaY = rand() % MAXCOORD;
    		poligonos[i].anadeVertice(Coordenada(coordenadaX, coordenadaY));
    	}
        //poligonos[i].imprimeVertices();
    }
    
    return 0;
}