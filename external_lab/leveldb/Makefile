CC = g++
INCLUDE = ./include
CPPFLAGS = -g -Wall -std=c++11 -I$(INCLUDE)
LDFLAGS = lib/libleveldb.a -lpthread

TARGETS = base_use advanced_use

all: $(TARGETS)

############################################
base_use: base_use.o
	$(CC) -o $@ $< $(CPPFLAGS) $(LDFLAGS)

base_use.o: base_use.cpp
	$(CC) -o $@ -c $< $(CPPFLAGS)
############################################

advanced_use: advanced_use.o
	$(CC) -o $@ $< $(CPPFLAGS) $(LDFLAGS)

advanced_use.o: advanced_use.cpp
	$(CC) -o $@ -c $< $(CPPFLAGS)

############################################

clean:
	-rm -rf $(TARGETS) *.o testdb
