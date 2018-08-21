#include "Fecha.h"
#include <iostream>
using namespace std;

int
main()
{
	// Se instancian tres objetos de la clase Fecha; El primero y el segundo automaticamente toman los valores por defecto
	// En el tercer objeto se le dan parámetros
	int res = 0;
	int bisiestos = 0;
	Fecha prueba, a, b, c(21, 9, 1973); 

	b.inicializaFecha(17, 6, 2000);
	a.muestraFecha();
	b.muestraFecha();
	c.muestraFecha();
	res = a.convierte();

	cout << "Resultado del metodo convierte sobre a: " << res << "\n";

	
	/*cout << "Resultado del metodo leapyr sobre a: " << a.leapyr() << "\n";
	cout << "Resultado del metodo leapyr sobre b: " << b.leapyr() << "\n";
	cout << "Resultado del metodo leapyr sobre c: " << c.leapyr() << "\n";*/

	for(int i=1; i<=2018; i++){
		prueba.inicializaFecha(1,1, i);
		if(prueba.leapyr()){
			bisiestos++;
		}
	}
	cout << "Años bisiestos desde el año 1 hasta 2018: " << bisiestos << "\n";
}