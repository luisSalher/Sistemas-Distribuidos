#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 200
char cadena2[TAM];
void invertir(char cadena[]){
    int cont=0;
    memset(cadena2,'\0',TAM);
    int tam=strlen(cadena);
    int aux;
    for(tam; tam>=0; tam--){
        if(cadena[tam]==' '){
            aux = tam+1;
            while(cadena[aux] !=' '  ){
                if(aux==strlen(cadena))
                    break;
                cadena2[cont++]=cadena[aux];
                aux++;
            }
            cadena2[cont++]=' ';
        }
        if(tam==0){ 
            aux = tam;
            while(cadena[aux] !=' '){  
                cadena2[cont++]=cadena[aux];
                aux++;
            }

        }
    }
}
int main()
{
    char cadena[TAM];
    strcpy(cadena,"el cielo es azul");
    //printf("cadena original:%s\n",cadena);
    invertir(cadena);
    //strcpy(cadena,invertir(cadena));
    printf("cadena invertida:%s\n",cadena2);
    return 0;
}