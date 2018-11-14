aste: ast.o gfx.o
	g++ ast.o gfx.o -o aste -I /opt/X11/include -L /opt/X11/lib -lX11 -lm

gfx: gfx.c gfx.h
	gcc gfx.c -c -I /opt/X11/include -L /opt/X11/lib -lX11 -lm

ast: Edy.cpp 
	g++ Edy.cpp -c 