#include "Coordenada.h"
#include "PoligonoIrreg.h"
#include "PoligonoReg.h"
#include <iostream>

using namespace std;

int main(){
/*
 * Se pretende aproximar el valor de PI.
 * Sabemos que el área de un círculo de radio 1 = PI, entonces crearemos un poligono regular con un número realitamente grande de vertices
 * para calcular su área con el método obtieneArea()
 */
    PoligonoReg poligonoTemporal(4);
    poligonoTemporal.imprimeVertices();
    cout << setprecision(40) << "Valor de PI con acos(-1): " << PI << '\n';
    cout << setprecision(40) << "Valor de PI con aproximación: " << poligonoTemporal.obtieneArea() << '\n';
    
    return 0;
}