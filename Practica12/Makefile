run: Servidor Cliente

Servidor: Servidor.o PaqueteDatagrama.o SocketDatagrama.o
	g++ SocketDatagrama.o PaqueteDatagrama.o Servidor.o -o Servidor
Cliente: Cliente.o PaqueteDatagrama.o SocketDatagrama.o 
	g++ SocketDatagrama.o PaqueteDatagrama.o Cliente.o -o Cliente
Servidor.o: Servidor.cpp
	g++ Servidor.cpp -c 
Cliente.o: Cliente.cpp
	g++ Cliente.cpp -c 
PaqueteDatagrama.o: PaqueteDatagrama.cpp
	g++ PaqueteDatagrama.cpp -c 
SocketDatagrama.o:SocketDatagrama.cpp 
	g++ SocketDatagrama.cpp -c 