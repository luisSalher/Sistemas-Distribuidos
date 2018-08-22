#include "Fecha.h"
#include <iostream>
using namespace std;

int
main()
{

	int res = 0;
	Fecha a(21, 9, 2010);
	Fecha b(21, 9, 2011);
	a.muestraFecha();
	b.muestraFecha();

	res = masViejaP(a, b);
	cout << "Resultado de metodo: " << res << "\n";
}