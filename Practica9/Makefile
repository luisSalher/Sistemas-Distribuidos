run: main
	./main origen.txt destino.txt
main: Archivo.o main.o
	g++ Archivo.o main.o -o main
Archivo.o: Archivo.cpp
	g++ -Wall -c Archivo.cpp
main.o: main.cpp
	g++ -Wall -c main.cpp

clean:
	rm *.o ./main