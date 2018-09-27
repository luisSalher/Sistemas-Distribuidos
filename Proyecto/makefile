ast: Asteroides.o gfx.o
	g++ Asteroides.o gfx.o -o ast -I /opt/X11/include -L /opt/X11/lib -lX11 -lm

Asteroides: Asteroides.cpp 
	g++ Asteroides.cpp -c 

gfx: gfx.c gfx.h
	gcc gfx.c -c -I /opt/X11/include -L /opt/X11/lib -lX11 -lm