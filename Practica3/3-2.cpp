#include "Fecha.h"
#include <iostream>
using namespace std;

int main()
  {
      int d,dd,m,mm,a,aa;
      for(int i = 0; i < 1000000000; i++)
        {
          d = rand() % 31;
          dd = rand() % 31;
          m = (rand() % 12) + 1;
          mm = (rand() % 12) + 1;
          a = rand() % 2100;
          aa = rand() % 31;
          Fecha valor(d, m, a);
          Fecha valor2(dd, mm, aa);
          valor.masVieja(valor, valor2);
        }
  }
