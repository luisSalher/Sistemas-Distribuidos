#ifndef TOROIDE_H_
#define TOROIDE_H_
#include <iostream>
#include <cmath>
#include <iomanip>
 
class Toroide : public Cilindro{
	protected:
	double radio;
	public:
	Toroide(double r1 = 1.0, double l = 1.0, double r2 = 2.0) : Cilindro(l), radio(r2) {}
	double calcarea();
};

#endif