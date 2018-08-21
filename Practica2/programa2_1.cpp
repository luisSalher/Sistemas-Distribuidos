#include <iostream>
using namespace	std;
// Se define la clase fecha
class Fecha
{
	private: // Indica que todos los miembros de las siguientes lineas de código antes de la palabra public solo podrán ser accedidos por funciones que sean miembro de la clase
	int		dia;
	int		mes;
	int		anio;
	public: // Indica que todos los miembros dentro de la clase pueden ser accedidos o mandados a llamar con el operador punto.
	// Prototipos de metodos
	Fecha(int = 3, int = 4, int = 2014); // Constructor
	void inicializaFecha(int, int, int);
	void muestraFecha();
};

Fecha::Fecha(int dd, int mm, int aaaa) // Definición del método; se debe indicar el nombre de la clase. El operador :: indica el sentido de pertenencia del metodo
{
	mes = mm;
	dia = dd;
	anio = aaaa;
}

void Fecha::inicializaFecha(int dd, int mm, int aaaa) // Definición del método
{
	anio = aaaa;
	mes = mm;
	dia = dd;
	return;
}

void Fecha::muestraFecha() // Definición del método
{
	cout << "La fecha es(dia-mes-año): " << dia << "-" << mes << "-" << anio << endl;
	return;
}

int
main()
{
	// Se instancian tres objetos de la clase Fecha; El primero y el segundo automaticamente toman los valores por defecto
	// En el tercer objeto se le dan parámetros
	Fecha a, b, c(21, 9, 1973); 

	b.inicializaFecha(17, 6, 2000);
	a.muestraFecha();
	b.muestraFecha();
	c.muestraFecha();
}
