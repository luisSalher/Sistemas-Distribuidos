#include "gfx.h"
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <math.h>

#define NUMERO_ASTEROIDES 8
#define PI 3.14159265358979323846

using namespace std;
class Poligono{
    private:
        int coordX;//coordenadas del centro del poligono
        int coordY;//coordenadas del centro del poligono
        double pendiente;
        int radio;//radio inicial del poligono
        int lado;//lado del que va a salir el poligono
        float yf[60];//arreglo de vertices en Y
        float xf[60];//arreglo de vertices en X
        int nvertices;//total de vertices del poligono
        int vel;
        int tamano;
        int maxRadio;
        vector<int> radios;
        bool haColisionado;
        double angulo;
        int velGiro=1;
        
    public:
        vector<int> trayectoria();
        void encontrarColision(Poligono[]);
        void explosion(int,int);
        void ast(int, int, double, int, int);
        void ast2(int, int);
        int getMaxRadio();
        void rotacion();
};

int Poligono::getMaxRadio(){
    return maxRadio;
}

void Poligono::rotacion(){
   /*angulo += velGiro;
   if ((int)angulo > 359) angulo = 0;
    xf = (dist * cos(angulo*PI/180)) + coordX;
    yf = (dist * sin(angulo*PI/180)) + coordY;*/
}

void Poligono::ast(int xo, int yo, double pen, int ld, int tm){
    int conta=0, nu=0, m=0;
    int i = 0;
    int j = 0;
    int temp = 0;
    float numa=0;
    int n = 18;
    tamano = tm;
    lado=ld;
    coordX=xo;
    coordY=yo;
    pendiente= pen;
    radios.reserve(n);
    if (tamano == 0){
        nu=15;
        m=10;
        vel=8;
    }else if(tamano == 1){
        nu=35;
        m=16;
        vel=6;
    }else if(tamano == 2){
        nu=50;
        m=36;
        vel=4;
    }else if(tamano == 3){
        nu=70;
        m=51;
        vel=3;
    }else if(tamano == 4){
        nu=90;
        m=71;
        vel=2;
    }
//creacion del asteroide
    radio = rand() % (nu-m+1)+m;
    xf[conta]=radio*cos(0.01745329252*numa)+coordX;
    yf[conta]=radio*sin(0.01745329252*numa)+coordY;
    conta++;
    numa=numa+20;
 while(numa<=340){   
     radios[i] = radio;
     radio = m + rand() % ((nu+1) - m);
     //radios[i] = radio; //Se agrega el radio al vector que tendrá todos los radios de cada asteroide
     xf[conta]=radio*cos(0.01745329252*numa)+coordX;
     yf[conta]=radio*sin(0.01745329252*numa)+coordY;
     gfx_line(xf[conta-1],yf[conta-1],xf[conta],yf[conta]);
     conta++;
     numa=numa+20;
     i++;
     //cout << "T radio: " << radio  << ","<<nu<<"," <<m<< endl;
 }gfx_line(xf[0],yf[0],xf[conta-1],yf[conta-1]); //termino de la creación del asteroide
 nvertices=conta-1;

 // Se ordenan los radios almacenados en el vector
 for (i = 0; i < n; ++i) {
    for (j = i + 1; j < n; ++j)
    {
        if (radios[i] > radios[j]) 
        {   
            temp =  radios[i];
            radios[i] = radios[j];
            radios[j] = temp;
        }
    }
 }
 // Se asigna el radio mas grande a la variable maxRadio
 maxRadio = radios[n-1];

}


void Poligono::ast2(int xo, int yo){
    int conta=0;
    float numa=0;
    int radio2=10;
    int var = rand() % 20;
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


/*
 Regresa las coordenadas de un asteroide cada que cambia de posicion
*/
vector<int> Poligono::trayectoria(){
    vector <int> parCoordenadas(3); //Vector que almacena las coordenadas y el radio mayor de un asteroide
    int aux1=0, aux2=0,num1=0, num2=0,num=0, h=0;
    if (lado==0){
        num=pendiente * ((coordX+vel)-coordX)+coordY;
        num = num-coordY;
        coordX=coordX+vel;
            coordY=coordY+num;
        for(h=0; h<=nvertices; h++){
            xf[h]= xf[h] + vel;
            yf[h]= yf[h] + num;
            
        }
        for(h=1;h<=nvertices;h++)
            gfx_line(xf[h-1],yf[h-1],xf[h],yf[h]);
        gfx_line(xf[0],yf[0],xf[h-1],yf[h-1]);
        usleep(4166);
    }else if(lado==1){
        num = (coordY-(coordY+vel)+(pendiente*coordX))/pendiente;
        num = num - coordX;
        coordX=coordX+num;
            coordY=coordY+vel; 
        for(h=0; h<=nvertices; h++){
            xf[h]= xf[h] + num;
            yf[h]= yf[h] + vel;
                       
        }
        for(h=1;h<=nvertices;h++)
            gfx_line(xf[h-1],yf[h-1],xf[h],yf[h]);
        gfx_line(xf[0],yf[0],xf[h-1],yf[h-1]);
        usleep(4166);
    }else if(lado==2){
            num=pendiente * ((coordX+vel)-coordX)+coordY;
            num = num-coordY;
            coordX=coordX-vel;
            coordY=coordY-num;
        for(h=0; h<=nvertices; h++){
            xf[h]= xf[h] - vel;
            yf[h]= yf[h] - num;
            
        }
        for(h=1;h<=nvertices;h++)
            gfx_line(xf[h-1],yf[h-1],xf[h],yf[h]);
        gfx_line(xf[0],yf[0],xf[h-1],yf[h-1]);
        usleep(4166);
    }else if(lado==3){
        num = (coordY-(coordY+vel)+(pendiente*coordX))/pendiente;
        num = num - coordX;
        coordX=coordX+num;
        coordY=coordY-vel;
        for(h=0; h<=nvertices; h++){
            xf[h]= xf[h] + num;
            yf[h]= yf[h] - vel;
        }
        for(h=1;h<=nvertices;h++)
            gfx_line(xf[h-1],yf[h-1],xf[h],yf[h]);
        gfx_line(xf[0],yf[0],xf[h-1],yf[h-1]);
        usleep(4166);
    }

    parCoordenadas[0] = coordX;
    parCoordenadas[1] = coordY;
    parCoordenadas[2] = maxRadio;

    return parCoordenadas;
}

void Poligono::encontrarColision(Poligono a[]){
    int i = 0;
    int j = 0;
    int cont = 0;
    double distancia = 0.0;
    int sumaRadios = 0;
    vector<int> coordenadasAsteroide(3);
    vector<vector<int> > vectorCoordenadas(NUMERO_ASTEROIDES); // Vector de vectores de coordenadas

    vectorCoordenadas.reserve(NUMERO_ASTEROIDES);

    for(cont=0; cont<NUMERO_ASTEROIDES; cont++){
        a[cont].haColisionado = false;
        coordenadasAsteroide = a[cont].trayectoria();
        vectorCoordenadas[cont] = coordenadasAsteroide;
    }

// Se comparan las coordenadas de los centros
    for(i=0; i<NUMERO_ASTEROIDES; i++){
        for(j=0; j<NUMERO_ASTEROIDES; j++){
            distancia = sqrt(pow((vectorCoordenadas[j][0] - vectorCoordenadas[i][0]), 2) + pow((vectorCoordenadas[j][1] - vectorCoordenadas[i][1]), 2));
            if(i < j){    
                sumaRadios = vectorCoordenadas[i][2] + vectorCoordenadas[j][2];
                if(distancia < sumaRadios && (a[i].haColisionado == false  || a[j].haColisionado == false)){
                    //cout<<"\nColision en los asteroides "<< i << " y " << j<< endl;
                    //cout<< "Coordenadas ( " << vectorCoordenadas[i][0] << ", " << vectorCoordenadas[i][1] << ") " <<endl;
                    // Llamada al metodo explosion
                    a[0].explosion((vectorCoordenadas[i][0]), (vectorCoordenadas[i][1]));

                    a[i].haColisionado = true;
                    a[j].haColisionado = true;
                    // Falta eliminar los asteroides que colisionan
                }
            }
        }
    }
}

void Poligono::explosion(int eX, int eY){
    int i=1;
    int eX1=eX,eX2=eX,eX3=eX,eX4=eX,eX5=eX,eX6=eX;
    int eY1=eY,eY2=eY,eY3=eY,eY4=eY,eY5=eY,eY6=eY;
    gfx_color(0,200,100);
    for(i=1;i<8;i++){
        ast2(eX1+=(i*4),eY1);
        ast2(eX2-=(i*4.5),eY2);
        ast2(eX3,eY3-=(i*3));
        ast2(eX4,eY4+=(i*2));
        ast2(eX5-=(i*2.5),eY5-=(i*2.5));
        ast2(eX6+=(i*3.5),eY6+=(i*3.5));
        //usleep(100000);
    }
    return;
}

int main(){
    int num, tam, coorX, coorY, coorAx1, coorAx2;
    double m;
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
            coorAx1=800;
            coorAx2=rand()%601;
        }else if(num==1){
            coorX=rand()%801;
            coorY=0;
            coorAx1=rand()%801;
            coorAx2=600;
        }else if(num==2){
            coorX=800;
            coorY=rand()%601;
            coorAx1=0;
            coorAx2=rand()%601;
        }else if(num==3){
            coorX=rand()%801;
            coorY=600;
            coorAx1=rand()%801;
            coorAx2=0;
        }
        tam = rand() % 5;
        m =(coorAx2 - coorY) / static_cast<double>(coorAx1 - coorX); 
        cout << "Asteroide: " << cont << "," << m << endl;
        cout << "Coor1: "<< coorX << "," << coorY << endl;
        cout << "Coor2: "<< coorAx1 << "," << coorAx2 << endl;
        a[cont].ast(coorX,coorY,m,num,tam);
        cont++;
    }

    while(1){
        
        a[cont].encontrarColision(a);

        gfx_flush();
        gfx_clear();
    }
    return 0;
}
