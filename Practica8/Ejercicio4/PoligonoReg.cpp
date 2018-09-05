#include "Coordenada.h"
#include "PoligonoIrreg.h"
#include "PoligonoReg.h"
#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

/*
 * Contructor para un Poligono Regular de n lados inscrito en una circunferencia de radio 1
 * Tomamos acos(-1) como una aproximación a PI
 * Las coordenadas de los puntos sobre la circunferencia se encuentrar mediante las funciones seno y coseno
 */
PoligonoReg::PoligonoReg(int nVertices) : numeroVertices(nVertices){
	int i = 0;
	double aux = 0.0;
	angulo = 360.0/(double)numeroVertices;

	for(i=0; i<numeroVertices; i++){
		aux = ((angulo)*PI*(double)(i)+1.0) / 180.0;
		double x = (double)(1.0 + sin(aux));
		double y = (double)(1.0 + cos(aux));
		Coordenada c(x,y);
		PoligonoIrreg::anadeVertice(c);
	}
}

/*
 * Para encontrar el área del polígono regular, usamos la fórmula: area = perimetro * apotema / 2
 * Para encontrar la longitud de un lado del polígono usamos la formula para la distancia entre dos puntos 
 * Para encontrar el valor del apotema usamos la fórmula: apotema = radio * cos(180 / n); En este caso radio = 1
 */
double PoligonoReg::obtieneArea(){
	double x1 = vertices[0].obtenerX();
	double y1 = vertices[0].obtenerY();
	double x2 = vertices[1].obtenerX();
	double y2 = vertices[1].obtenerY();
	double lado = sqrt((pow((x2 - x1), 2) + pow((y2 - y1), 2)));
	double perimetro = lado * numeroVertices;
	//double apotema = (lado / (2*(tan(180.0 / numeroVertices))));
	double apotema = cos((PI / numeroVertices));
	double area = (perimetro * apotema) / 2;
 
	return area;
}
