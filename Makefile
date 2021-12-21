CC = gcc

all:
	$(CC) -o test test.c cstring.c

clean:
	rm test
