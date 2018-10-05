#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	unsigned int numero = 4294967291; //longest 32 bit integer
	unsigned int i = 2;
	
	for(i = 2; i<numero; i++){
		if((numero%i) == 0){
			cout << "no primo\n";
			exit(0);
			break;
		}			
	}
	
	cout << "primo\n";
}