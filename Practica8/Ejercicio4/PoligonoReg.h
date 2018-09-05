#ifndef POLIGONOREG_H_
#define POLIGONOREG_H_
#include <iostream>
#include <cmath>
#include <iomanip>

const double PI = acos(-1.0); // Aproximación a PI mediante la función arccos()
 
class PoligonoReg : public PoligonoIrreg{
	protected:
		int numeroVertices;
		double angulo;
	public:
		PoligonoReg(int nVertices = 4);
		double obtieneArea();
};

#endif