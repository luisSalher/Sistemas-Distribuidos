#include "Coordenada.h"
#include "PoligonoIrreg.h"
#include <iostream>

#define MAXVERT 30
#define MAXCOORD 10
#define NPOLIGONOS 5

using namespace std;

int main(){
    
    int i = 0;
    int j = 0;
    int vertices = 0;
    int coordenadaX = 0;
    int coordenadaY = 0;

    vector<PoligonoIrreg> poligonos(NPOLIGONOS);
    //PoligonoIrreg poligonos;
    
    vertices = rand() % MAXVERT;
    cout << "\n Numero de vertices: " << vertices <<"\n";

    for(i=0; i<poligonos.size(); i++){
    	PoligonoIrreg poligonoTemp;
    	.push_back(poligonoTemp);
    	for(j=0; j<vertices; j++){
    		coordenadaX = rand() % MAXCOORD;
    		coordenadaY = rand() % MAXCOORD;
    		poligonos[i].anadeVertice(Coordenada(coordenadaX, coordenadaY));
    	}
    }

    //poligonos.imprimeVertices();
    
    return 0;
}