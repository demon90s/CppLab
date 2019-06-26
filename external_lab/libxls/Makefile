CC = gcc
CFLAGS = -g -Wall

main: main.c
	$(CC) $(CFLAGS) -o $@ $< -L./lib -lxlsreader

clean:
	-rm -f main