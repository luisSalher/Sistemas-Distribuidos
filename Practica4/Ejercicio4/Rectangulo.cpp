#include "Coordenada.h"
#include "Rectangulo.h"
#include <iostream>
using namespace std;

/*Rectangulo::Rectangulo() : superiorIzq(0,0), inferiorDer(0,0)
{ }*/

/*
Rectangulo::Rectangulo(double xSupIzq, double ySupIzq, double xInfDer, double yInfDer):superiorIzq(xSupIzq, ySupIzq), inferiorDer(xInfDer, yInfDer)
{ }*/

Rectangulo::Rectangulo() : superiorIzq(0, 0), inferiorDer(0, 0) {}

Rectangulo::Rectangulo(Coordenada superior, Coordenada inferior):superiorIzq(superior), inferiorDer(inferior) {}

void Rectangulo::imprimeEsq()
{
	cout << "Para la esquina superior izquierda.\n";
	cout << "x = " << superiorIzq.obtenerX() << " y = " << superiorIzq.obtenerY() << endl;
	cout << "Para la esquina inferior derecha.\n";
	cout << "x = " << inferiorDer.obtenerX() << " y = " << inferiorDer.obtenerY() << endl;
}

double Rectangulo::obtenerArea(void) {
    double alto = obtieneSupIzq().obtenerY() - obtieneInfDer().obtenerY();
    double ancho = obtieneInfDer().obtenerX() - obtieneSupIzq().obtenerX();
    return alto * ancho;
}