
output: main.o globals.o intersections.o draw.o
	g++ main.cpp intersections.cpp draw.cpp -lGL -lGLU -lglut  -o output

main.o: main.cpp
	g++ -c main.cpp -lGL -lGLU -lglut

intersections: intersections.h intersections.cpp globals.h
	g++ -c intersections.cpp

draw: draw.h draw.cpp globals.h
	g++ -c draw.cpp -lGL -lGLU -lglut

clean:
	rm *.o output