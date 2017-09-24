
output: main.o AVL.o Node.o
	g++ main.cpp AVL.cpp Node.cpp -lGL -lGLU -lglut  -o output

main.o: main.cpp
	g++ -c main.cpp -lGL -lGLU -lglut

AVL.o: AVL.cpp AVL.h
	g++ -c AVL.cpp

Node.o: Node.cpp Node.h
	g++ -c Node.cpp

clean:
	rm *.o output