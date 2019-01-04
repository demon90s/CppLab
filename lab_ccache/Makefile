CXX=ccache g++
CC=ccache g++

all: main

main: main.o foo.o bar.o bar0.o bar1.o bar2.o bar3.o bar4.o bar5.o bar6.o bar7.o bar8.o bar9.o

bar0.o: bar0.cpp
bar1.o: bar1.cpp
bar2.o: bar2.cpp
bar3.o: bar3.cpp
bar4.o: bar4.cpp
bar5.o: bar5.cpp
bar6.o: bar6.cpp
bar7.o: bar7.cpp
bar8.o: bar8.cpp
bar9.o: bar9.cpp
bar.o: bar.cpp
foo.o: foo.cpp
main.o: main.cpp

clean:
	@rm -f *.o main
