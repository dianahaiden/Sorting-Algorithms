main: Sort.o Main.cpp
	g++ -std=c++14 -Wall -pedantic-errors -o main Sort.o Main.cpp

Sort.o: Sort.h Sort.cpp
	g++ -g -O0 -std=c++14 -Wall -pedantic-errors -c Sort.cpp

run: main
	./main

clean: rm -f *.o Sort
