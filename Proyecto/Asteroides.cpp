#include "gfx.h"
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

using namespace std;
class Poligono{
    private:
        int coordX;
        int coordY;
        int radio;
        int lado;
        
    public:
        void crear_poligono(int, int,int);
        void trayectoria();
        void explosion();
        void ast(int, int);
    };

void Poligono::ast(int xf, int yf){
    /*xf[conta]=radio*cos(0.01745329252*numa)+xo;
    yf[conta]=radio*sin(0.01745329252*numa)+yo;
    conta++;
 while(numa<=180){    
     radio = rand() % 20 + 18;
     cout << radio << endl;
    xf[conta]=radio*cos(0.01745329252*numa)+xo;
    yf[conta]=radio*sin(0.01745329252*numa)+yo;
     gfx_line(xf[conta-1],yf[conta-1],xf[conta],yf[conta]);
     conta++;
     numa=numa+20;
     gfx_flush();
 }*/
}
    
void Poligono::crear_poligono(int cX, int cY, int ld){
    coordX=cX;
    coordY=cY;
    lado=ld;
    radio = rand() % 11; //elegir el tamaño del poligono
    gfx_point(coordX, coordY);
	gfx_flush();
    usleep(416);
    return;
}

void Poligono::trayectoria(){
    int aux1=0, aux2=0,num1=0,num2=0;
    if (lado==0){
        num1 = rand() % 2;
        num2 = rand() % 3-1;
        aux1=aux1+num1;
        aux2=aux2+num2;
        coordX=coordX+aux1;
        coordY=coordY+aux2;
         gfx_point(coordX, coordY);
         //cout << coordX << " , " << coordY <<endl;
         gfx_flush();
         usleep(416);
    }else if(lado==1){
        num1 = rand() % 3-1;
        num2 = rand() % 2;
        aux1=aux1+num1;
        aux2=aux2+num2;
        coordX=coordX+aux1;
        coordY=coordY+aux2;
         gfx_point(coordX, coordY);
         //cout << coordX << " , " << coordY <<endl;
         gfx_flush();
         usleep(416);
    }else if(lado==2){
        num1 = rand() % 3-2;
        num2 = rand() % 3-1;
        aux1=aux1+num1;
        aux2=aux2+num2;
        coordX=coordX+aux1;
        coordY=coordY+aux2;
        gfx_point(coordX, coordY);
        gfx_flush();
        usleep(416);
    }else if(lado==3){
        num1 = rand() % 3-1;
        num2 = rand() % 3-2;
        aux1=aux1+num1;
        aux2=aux2+num2;
        coordX=coordX+aux1;
        coordY=coordY+aux2;
        gfx_point(coordX, coordY);
        gfx_flush();
        usleep(416);
    }
    
    return;
}

void Poligono::explosion(){
    return;
}

int main()
{
    int num, coorX, coorY;
    Poligono a[5];
    int conta=0;
    int cont=0, radio=30;
    float numa=0;
    float yf[60],xf[60],yo=300,xo=400;
    char c;
    srand(time(NULL));
    gfx_open(800, 600, "Proyecto 2 Equipo 4");
    gfx_color(0,200,100);
    coorY=rand()%601;
 while(cont<5){
     num = rand() % 4;//elegir de que lado saldra el poligono
     //Determinar de que lado va a salir y en que punto saldra el poligono
     if(num==0){
         coorX=0;
         coorY=rand()%601;
    }else if(num==1){
        coorX=rand()%801;
        coorY=0;
    }else if(num==2){
        coorX=800;
        coorY=rand()%601;
    }else if(num==3){
        coorX=rand()%801;
        coorY=600;
    }
      a[cont].crear_poligono(coorX,coorY,num);//24 por segundo
      cont++;
 }
 cont=0;
    xf[conta]=radio*cos(0.01745329252*numa)+xo;
    yf[conta]=radio*sin(0.01745329252*numa)+yo;
    conta++;
 while(numa<=360){    
     radio = rand() % 20 + 18;
     cout << radio << endl;
    xf[conta]=radio*cos(0.01745329252*numa)+xo;
    yf[conta]=radio*sin(0.01745329252*numa)+yo;
     gfx_line(xf[conta-1],yf[conta-1],xf[conta],yf[conta]);
     conta++;
     numa=numa+20;
     gfx_flush();
 }gfx_line(xf[0],yf[0],xf[conta-1],yf[conta-1]);
 
 while(1){
     if(cont==5)cont=0;
     a[cont].trayectoria();
     cont++;
}
 return 0;
}
