#ifndef CIRCULO_H_
#define CIRCULO_H_
#include <iostream>
#include <cmath>
#include <iomanip>

const double PI = acos(-1.0);

class Circulo{
	protected:
	double radio;
	public:
	Circulo(double = 1.0);
	double calcval();
};

#endif