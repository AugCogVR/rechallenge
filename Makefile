CC=gcc 
CFLAGS=-O0

all: v1 v2 v3

v1: v1.c 
	gcc -o v1 v1.c 

v2: v2.c 
	gcc -o v2 v2.c 

v3: v3.c 
	gcc -o v3 v3.c 

clean:
	rm -f v1 v2 v3
