main: main.cpp Toroide.o
	g++ main.cpp Toroide.o Cilindro.o Circulo.o -o main
Toroide.o: Toroide.cpp Cilindro.o Toroide.h 
	g++ Toroide.cpp -c
Cilindro.o: Cilindro.cpp Circulo.o Cilindro.h 
	g++ Cilindro.cpp -c
Circulo.o: Circulo.cpp Circulo.h 
	g++ Circulo.cpp -c