#include "Circulo.h"
#include "Cilindro.h"
#include "Toroide.h"
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

Circulo::Circulo(double r) : radio(r){ }

double Circulo::calcval(){ //Calcula el área del círculo 20 {
	return(PI * radio * radio);
}
