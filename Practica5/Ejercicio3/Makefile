all: programa5_3 programa5_4

programa5_4: programa5_4.cpp PoligonoIrreg.o
	g++ programa5_4.cpp PoligonoIrreg.o Coordenada.o -o programa5_4

programa5_3: programa5_3.cpp PoligonoIrreg.o
	g++ programa5_3.cpp PoligonoIrreg.o Coordenada.o -o programa5_3

PoligonoIrreg.o: PoligonoIrreg.cpp Coordenada.o PoligonoIrreg.h 
	g++ PoligonoIrreg.cpp -c

Coordenada.o: Coordenada.cpp Coordenada.h 
	g++ Coordenada.cpp -c