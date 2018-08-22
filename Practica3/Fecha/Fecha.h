#ifndef FECHA_H_
#define FECHA_H_

class Fecha
{
private:
   int dia;
   int mes;
   int anio;
public:
	Fecha(int = 3, int = 4, int = 2014); 
	void inicializaFecha(int, int, int); 
	void muestraFecha();
	int convierte();
	bool leapyr();
	int masViejaP(Fecha fecha1, Fecha fecha2); 
	int masViejaR(Fecha &fecha1, Fecha& fecha2);
}; 

#endif