#ifndef CILINDRO_H_
#define CILINDRO_H_
#include <iostream>
#include <cmath>
#include <iomanip>
 
class Cilindro : public Circulo{
	protected:
	double longitud;
	public:
	Cilindro(double r = 1.0, double l = 1.0) : Circulo(r), longitud(l) {}
	double calcval();
};

#endif