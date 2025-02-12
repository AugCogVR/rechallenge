CC=gcc 
CFLAGS=-O0

all: v1 v2 v3 v4

v1: src/v1.c 
	gcc -o bin/v1 src/v1.c 

v2: src/v2.c 
	gcc -o bin/v2 src/v2.c 

v3: src/v3.c 
	gcc -o bin/v3 src/v3.c 

v4: src/v4.c 
	gcc -o bin/v4 src/v4.c 

clean:
	rm -f bin/v1 bin/v2 bin/v3 bin/v4
