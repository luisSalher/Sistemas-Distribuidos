#include "Circulo.h"
#include "Cilindro.h"
#include "Toroide.h"
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
	Circulo Circulo_1(2);
	Cilindro Cilindro_1(2,4);
	Toroide Toroide_1(4, 10);
	
	cout << "El area de Circulo_1 es " << Circulo_1.calcval() << endl;
	cout << "El volumen de Cilindro_1 es " << Cilindro_1.calcval() << endl;
	cout << "El area de Toroide_1 es  " << Toroide_1.calcarea() << endl;

	cout << "El valor de Pi es " <<setprecision(40) << PI << endl;
	return 0;
}