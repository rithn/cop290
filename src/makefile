path = $(dir $(realpath $(firstword $(MAKEFILE_LIST))))

test: backend.o draw.o Point.o Line.o Solid.o Projection.o
	g++ -o test backend.o Point.o Line.o Solid.o Projection.o draw.o -lcomdlg32 -L$(path)..\lib -lfreeglut -lopengl32
	
backend.o: backend.cpp Projection.cpp Solid.cpp draw.cpp Point.cpp Line.cpp
	g++ -c backend.cpp Projection.cpp Solid.cpp Point.cpp Line.cpp

draw.o: draw.cpp Solid.cpp Projection.cpp Point.cpp Line.cpp
	g++ -c -o draw.o draw.cpp -I$(path)..\include
	
Solid.o: Solid.cpp Projection.cpp Line.cpp Point.cpp
	g++ -c Solid.cpp
	
Projection.o: Projection.cpp Line.cpp Point.cpp
	g++ -c Projection.cpp
	
Point.o: Point.cpp Line.cpp
	g++ -c Point.cpp 
	
Line.o: Line.cpp
	g++ -c Line.cpp
	
clean:
	del backend.o draw.o Solid.o Projection.o Point.o Line.o test