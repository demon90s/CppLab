CC = g++
INCLUDE=./include
CPPFLAGS = -g -Wall -std=c++11
LDFLAGS = ./lib/libgtest.a -lpthread

all: main

main: main.o
	$(CC) $(CPPFLAGS) -o $@ $< $(LDFLAGS)

main.o: main.cpp
	$(CC) -I$(INCLUDE) $(CPPFLAGS) -c $< -o $@

clean:
	-rm -f main *.o