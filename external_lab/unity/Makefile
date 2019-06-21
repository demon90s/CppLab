OPTIONS = -DUNITY_OUTPUT_COLOR
CC = gcc
CFLAGS = -g -Wall $(OPTIONS)

main: main.o unity.o

main.o: main.c
unity.o: unity/unity.c unity/unity.h unity/unity_internals.h
	$(CC) $(CFLAGS) -o $@ -c unity/unity.c

clean:
	-rm -f *.o main