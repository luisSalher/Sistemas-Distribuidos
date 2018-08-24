#include <iostream>
#include <stdlib.h>
#include <vector>
#include <ctime>
using namespace std;
class Coordenada
  {
  private:
    double x;
    double y;
 public:
   Coordenada(double = 0, double = 0);
   double obtenerX();
   double obtenerY();
 };

  class PoligonoIrregular
    {
      private:
        vector<Coordenada> vectCoords;
        static int verticesTotales;
      public:
        PoligonoIrregular();
        static int getVerticesTotales();
        void anadeVertice(Coordenada);
        void imprimirVertice();
        void forr(int);
    };

 int main( )
  {
    vector<PoligonoIrregular> vectPoli;
    int vert;
    cout <<"N Poligono: \n";
    cin >> vert;
    vectPoli.reserve(vert);
    srand(time(NULL));
    for(int i = 0; i < vert; i++)  //500 elementos de 100 vertices cada uno
      {
          int nvert=(rand())/1000000;
        vectPoli[i].forr(nvert);
      }
      cout << "\n Se usaron en total: " << vectPoli[0].getVerticesTotales() << "\n";
    return 0;
  }

void PoligonoIrregular::forr(int nvert)
{
    
    
    cout << nvert << "\n";
  for(int i = 0; i < nvert; i++)
    {
      Coordenada c(i+i+i, i*i);
      PoligonoIrregular p;
      p.anadeVertice(c);
    }
}

int PoligonoIrregular:: verticesTotales = 0;
PoligonoIrregular::PoligonoIrregular()
    {}

void PoligonoIrregular::anadeVertice(Coordenada coord)
    {
      vectCoords.push_back(coord);
      verticesTotales++;
    }

void PoligonoIrregular::imprimirVertice()
    {
      for(int i = 0; i < vectCoords.size(); i++)
        {
          cout << "\n C[" << i << "] = (" << vectCoords[i].obtenerX() << "," << vectCoords[i].obtenerY() << ")" ;
        }
    }

int PoligonoIrregular::getVerticesTotales()
    {
      return verticesTotales;
    }

Coordenada::Coordenada(double xx, double yy) : x(xx), y(yy)
    {}

 double Coordenada::obtenerX()
 {
   return x;
 }

 double Coordenada::obtenerY()
 {
   return y;
 }
