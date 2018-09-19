#include <unistd.h>
#include <iostream>
#include <iostream>
#include <time.h> 
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <string>
#include <string.h>

using namespace std;

int main(int argc, char* argv[]){
	char *big_string = NULL;
	int bytes_copied = 0, m = 0, times = 0;
	char c;
	//srand (time(NULL));

	for (int x = 1; x <= atoi(argv[1]); x++)
	{
		char tls[4];
		for (int z = 0; z <= 3; z++)
		{
			if(z==3){
				tls[z] = ' ';
			} else {
				int i = rand() % 25 + 65;
				char c = i;
				tls[z] = c;
			}
		}
		//tls[4] = '\0';

		m = (sizeof(tls))*x;
		big_string = (char*)realloc(big_string, m);
		memcpy(big_string+bytes_copied, tls, sizeof(tls));
		bytes_copied += sizeof(tls);
	}

	/*while ((big_string = strstr(big_string, "IPN")) != NULL){
        times++;
        big_string += 4;
    }*/
        /*
    int i = 0;

    while(big_string[i] != '\0'){
    	if(big_string[i] == 'I'){
    		if(big_string[i+1] == 'P'){
    			if(big_string[i+2] == 'N'){
    				times++;
    			}
    		}
    	}
    	else{
    		i += 4;
    	}
    }*/
    
    cout <<" IPN encontrados= " << times << endl;
}

