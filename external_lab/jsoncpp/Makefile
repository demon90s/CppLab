all: main

main: main.o
	g++ -g -Wall -o $@ $< ./lib/libjsoncpp.a

main.o: main.cpp
	g++ -g -Wall -I./include -o main.o -c main.cpp

clean:
	-rm -f *.o main
