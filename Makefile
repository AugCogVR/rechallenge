CC=gcc 
CFLAGS=-O0

SOURCES = $(wildcard src/v*.c)

TARGETS = $(SOURCES:src/%.c=bin/%)

bin/%: src/%.c
	$(CC) $(CFLAGS) -o $@ $^

all: $(TARGETS)

clean:
	rm -f $(TARGETS)

