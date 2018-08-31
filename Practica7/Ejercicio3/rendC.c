#include <stdio.h>
#include <math.h>


#define Max 20000000


int main(){
    double i=0;
    double seno=0,coseno=0,tangente=0,logaritmo=0,raizCuad=0;
    while(i<Max){
        seno += sin(i);
        coseno += cos(i);
        tangente += tan(i);
        logaritmo += log10(i);
        raizCuad += sqrt(i);
        i++;
    }
    //printf("Fin %f\n",seno);
}
