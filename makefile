CXX = g++
CXXFLAGS = -m32

main.o: main.cpp Line.cpp Point.cpp Solid.cpp draw.cpp
	$(CXX) $(CXXFLAGS) -o main.o -c main.cpp  

draw.o: draw.cpp Point.cpp Solid.cpp
	$(CXX) $(CXXFLAGS) -c -o draw.o draw.cpp 
	
Solid.o: Solid.cpp Line.cpp Point.cpp
	$(CXX) $(CXXFLAGS) -c -o Solid.o Solid.cpp 
	
Point.o: Point.cpp Line.cpp
	$(CXX) $(CXXFLAGS) -c -o Point.o Point.cpp

Line.o: Line.cpp
	$(CXX) $(CXXFLAGS) -c -o Line.o Line.cpp
	
	
