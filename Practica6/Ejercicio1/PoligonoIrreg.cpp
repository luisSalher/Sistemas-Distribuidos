#include "Coordenada.h"
#include "PoligonoIrreg.h"
#include <iostream>
using namespace std;

PoligonoIrreg::PoligonoIrreg(){}

bool PoligonoIrreg::comparacion(Coordenada a, Coordenada b) {
    if (a.obtenerMagnitud() < b.obtenerMagnitud())
        return true;
    return false;
}

void PoligonoIrreg::anadeVertice(Coordenada c) {
    vertices.push_back(c);
}

void PoligonoIrreg::imprimeVertices() {
    vector<Coordenada>::iterator it;

    cout << "Vértices: \n";

    for(it=vertices.begin(); it!=vertices.end(); ++it) {
	    cout << "(" << it->obtenerX() <<", " << it->obtenerY() << ") = " << it->obtenerMagnitud() << endl;
	}
}

void PoligonoIrreg::ordenarVertices() {
    sort(vertices.begin(), vertices.end(), comparacion);
}


