all:
	gcc -o test test.c cstring.c

clean:
	rm test
