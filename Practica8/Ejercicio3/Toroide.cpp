#include "Circulo.h"
#include "Cilindro.h"
#include "Toroide.h"
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double Toroide::calcarea(){ //Calcula el area del toroide {
	return (radio * (Cilindro::calcval() / (Circulo::calcval() / PI)));
}