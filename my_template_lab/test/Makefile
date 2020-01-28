CC=g++
INCLUDE=-I./include -I../library
CPPFLAGS=-g -Wall -std=c++11
LDFLAGS=./lib/libgtest.a -lpthread

OBJS=main.o \
	test_FixLenHashTable.o

all: main

main: $(OBJS)
	$(CC) $(CPPFLAGS) -o main $(OBJS) $(LDFLAGS)

%.o: %.cpp
	$(CC) $(INCLUDE) $(CPPFLAGS) -c $< -o $@

clean:
	-rm -f main *.o
