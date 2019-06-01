all: rapidxml_example

rapidxml_example: rapidxml_example.o
	g++ -g -Wall -o rapidxml_example rapidxml_example.o

rapidxml_example.o: rapidxml_example.cpp
	g++ -g -Wall -Ilib -c rapidxml_example.cpp

clean:
	rm -f rapidxml_example rapidxml_example.o