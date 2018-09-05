#include "Circulo.h"
#include "Cilindro.h"
#include "Toroide.h"
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double Cilindro::calcval(){ //Calcula el volumen del cilindro 34 {
	return (longitud * Circulo::calcval());
}