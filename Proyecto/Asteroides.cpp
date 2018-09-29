#include "gfx.h"
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

#define NUMERO_ASTEROIDES 15
#define TAMANO_POLIGONO 11

using namespace std;
class Poligono{
    private:
        int coordX;//coordenadas del centro del poligono
        int coordY;//coordenadas del centro del poligono
        int radio=30;//radio inicial del poligono
        int lado;//lado del que va a salir el poligono
        float yf[60];//arreglo de vertices en Y
        float xf[60];//arreglo de vertices en X
        int nvertices;//total de vertices del poligono
        
    public:
        void trayectoria();
        void explosion(int,int);
        void ast(int, int, int, int);
        void ast2(int, int);
};

void Poligono::ast(int xo, int yo, int ld, int tm){
    int conta=0;
    float numa=0;
    lado=ld;
    coordX=xo;
    coordY=yo;
//creacion del asteroide
    xf[conta]=radio*cos(0.01745329252*numa)+coordX;
    yf[conta]=radio*sin(0.01745329252*numa)+coordY;
    conta++;
 while(numa<=340){    
     radio = rand() % 20 + 18;
    xf[conta]=radio*cos(0.01745329252*numa)+coordX;
    yf[conta]=radio*sin(0.01745329252*numa)+coordY;
     gfx_line(xf[conta-1],yf[conta-1],xf[conta],yf[conta]);
     conta++;
     numa=numa+20;
     
 }
 gfx_line(xf[0],yf[0],xf[conta-1],yf[conta-1]); //termino de la creación del asteroide
 nvertices=conta-1;
}



void Poligono::ast2(int xo, int yo){
    int conta=0;
    float numa=0;
    int radio2=10;
    //lado=ld;
    coordX=xo;
    coordY=yo;
//creacion del asteroide
    xf[conta]=radio2*cos(0.01745329252*numa)+coordX;
    yf[conta]=radio2*sin(0.01745329252*numa)+coordY;
    conta++;
 while(numa<=340){    
     radio2 = rand() % 5 + 10;
    xf[conta]=radio2*cos(0.01745329252*numa)+coordX;
    yf[conta]=radio2*sin(0.01745329252*numa)+coordY;
     gfx_line(xf[conta-1],yf[conta-1],xf[conta],yf[conta]);
     conta++;
     numa=numa+10;
     gfx_flush();
 }
 gfx_line(xf[0],yf[0],xf[conta-1],yf[conta-1]); //termino de la creación del asteroide
 nvertices=conta-1;
}

void Poligono::trayectoria(){
    int aux1=0, aux2=0, num1=0,num2=0, h=0;
    if (lado==0){
        num1 = rand() % 2;
        num2 = rand() % 3-1;
        for(h=0; h<=nvertices; h++){
            xf[h]= xf[h] + num1;
            yf[h]= yf[h] + num2;
            coordX=coordX+num1;
            coordY=coordY+num2;
        }
        for(h=1;h<=nvertices;h++)
            gfx_line(xf[h-1],yf[h-1],xf[h],yf[h]);
        gfx_line(xf[0],yf[0],xf[h-1],yf[h-1]);
        usleep(4166);
    }else if(lado==1){
        num1 = rand() % 3-1;
        num2 = rand() % 2;
        xf[h]= xf[h] + num1;
        yf[h]= yf[h] + num2;
        for(h=1; h<=nvertices; h++){
            xf[h]= xf[h] + num1;
            yf[h]= yf[h] + num2;
            coordX=coordX+num1;
            coordY=coordY+num2;            
        }
        for(h=1;h<=nvertices;h++)
            gfx_line(xf[h-1],yf[h-1],xf[h],yf[h]);
        gfx_line(xf[0],yf[0],xf[h-1],yf[h-1]);
        usleep(4166);
    }else if(lado==2){
        num1 = rand() % 3-2;
        num2 = rand() % 3-1;
        xf[h]= xf[h] + num1;
        yf[h]= yf[h] + num2;
        for(h=1; h<=nvertices; h++){
            xf[h]= xf[h] + num1;
            yf[h]= yf[h] + num2;
            coordX=coordX+num1;
            coordY=coordY+num2;
        }
        for(h=1;h<=nvertices;h++)
            gfx_line(xf[h-1],yf[h-1],xf[h],yf[h]);
        gfx_line(xf[0],yf[0],xf[h-1],yf[h-1]);
        usleep(4166);
    }else if(lado==3){
        num1 = rand() % 3-1;
        num2 = rand() % 3-2;
        xf[h]= xf[h] + num1;
        yf[h]= yf[h] + num2;
        for(h=1; h<=nvertices; h++){
            xf[h]= xf[h] + num1;
            yf[h]= yf[h] + num2;
            coordX=coordX+num1;
            coordY=coordY+num2;
        }
        for(h=1;h<=nvertices;h++)
            gfx_line(xf[h-1],yf[h-1],xf[h],yf[h]);
        gfx_line(xf[0],yf[0],xf[h-1],yf[h-1]);
        usleep(4166);
    }
    return;
}


void Poligono::explosion(int eX, int eY){
    int i=1;
    int eX1=eX,eX2=eX,eX3=eX,eX4=eX,eX5=eX,eX6=eX;
    int eY1=eY,eY2=eY,eY3=eY,eY4=eY,eY5=eY,eY6=eY;
    for(i=1;i<8;i++){
        gfx_color(0,200,100);
        ast2(eX1+=(i*4),eY1);
        ast2(eX2-=(i*4.5),eY2);
        ast2(eX3,eY3-=(i*3));
        ast2(eX4,eY4+=(i*2));
        ast2(eX5-=(i*2.5),eY5-=(i*2.5));
        ast2(eX6+=(i*3.5),eY6+=(i*3.5));
        usleep(100000);
        gfx_clear();
    }
    
}

int main(){
    int num, tam, coorX, coorY;
    Poligono a[NUMERO_ASTEROIDES];
    int cont=0;
    char c;
    srand(time(NULL));
    gfx_open(800, 600, "Proyecto 2 Equipo 4");
    gfx_color(0,200,100);
    coorY=rand()%601;

    while(cont<NUMERO_ASTEROIDES){
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
        tam = 1 + rand() % (6 - 1);
        a[cont].ast(coorX,coorY,num,tam);
        cont++;
    }
    int aux=0;
    while(1){
        aux++;
        for(cont=0;cont<NUMERO_ASTEROIDES;cont++)
        {
            aux++;
            a[cont].trayectoria();
            if(aux==1000){// Prueba de condicion de explosion
                a[0].explosion(200,200);
             }
        }
        gfx_flush();
        gfx_clear();
       
    }
    return 0;
}

