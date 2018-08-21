#include "Fecha.h"
#include <iostream>
using namespace std;

Fecha::Fecha(int dd, int mm, int aaaa) : dia(dd), mes(mm), anio(aaaa) {
	if((dia < 1) || (dia > 31)){
      cout << "Valor ilegal para el dia!\n";
      exit(1);
	}
	if((anio < 0) || (anio > 2018)){
      cout << "Valor ilegal para el año!\n";
      exit(1);
	}
}

void Fecha::inicializaFecha(int dd, int mm, int aaaa) {
   anio = aaaa;
   mes = mm;
   dia = dd;
   return;
}

void Fecha::muestraFecha()
{
	cout << "La fecha es(dia-mes-año): " << dia << "-" << mes << "-" << anio << endl;
	return; 
}

int Fecha::convierte()
{
	int res = 0;
	res = anio*10000+mes*100+dia;
	return res;
}

bool Fecha::leapyr()
{
	if((anio % 400 == 0) || (((anio % 4 == 0)) && (anio % 100 != 0))){
		return true;
	}
	else{
		return false;
	}

}