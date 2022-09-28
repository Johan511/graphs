main.out : tree.o ./src/main.cpp
	g++ -o main.out tree.o ./src/main.cpp

tree.o : ./src/tree.cpp ./headers/tree.h
	g++ -g -c ./src/tree.cpp

clean:
	rm -rf *.o *.i *.exe *.out

