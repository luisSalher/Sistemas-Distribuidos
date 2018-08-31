#include <unistd.h>
#include <iostream>
#include <iostream>
#include <time.h> 
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <string>

using namespace std;

int main(int argc, char* argv[]){
	int times = 0;
	string big_string;
	size_t pos = 0;
	//srand (time(NULL));

	for (int x = 0; x < atoi(argv[1]); x++)
	{
		string tls;
		for (int z = 0; z <= 3; z++)
		{
			if(z==3){
				tls.append(" ");
			} else {
				int i = rand() % 25 + 65;
				char c = i;
				string l(1,c);
				tls.append(l);
			}
		}
		big_string.append(tls);
	}

    while ((pos = big_string.find("IPN", pos)) != string::npos){
        times++;
        pos += 4;
    }

	cout <<" IPN encontrados= " << times << endl;
}


