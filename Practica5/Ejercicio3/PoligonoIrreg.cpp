#include "Coordenada.h"
#include "PoligonoIrreg.h"
#include <iostream>

using namespace std;

int PoligonoIrreg:: verticesTotales = 0;

PoligonoIrreg::PoligonoIrreg(){}

void PoligonoIrreg::anadeVertice(Coordenada c) {
    vertices.push_back(c);
    verticesTotales++;
}

void PoligonoIrreg::imprimeVertices() {
	cout << "Vértices: \n";
	for(int i=0; i<vertices.size(); i++){
		cout << "(" << vertices[i].obtenerX() <<", " << vertices[i].obtenerY() << ")\n";
	}
}

int PoligonoIrreg::getVerticesTotales(){
	return verticesTotales;
}


