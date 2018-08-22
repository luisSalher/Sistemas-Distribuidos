#include <iostream>
using namespace std;

int main( ){

	double c = 20;
	double f;
	int i1 = 9;
	int i2 = 5;
	double con = (double)i1/i2;
	f =  con * c + 32.0;

	cout << c << " Grados centigrados equivale a " << f << " grados Fahrenheit\n";
	
	return 0;
}