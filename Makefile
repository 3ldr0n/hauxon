CC=gcc
CFLAGS=-std=c11 -Wall -I../include
DEPS=malloc_s.h
OBJ=malloc_s.o cat.o
SRCS=malloc_s.c cat.c

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

cat:
	mkdir -p bin
	cd src/ && $(CC) $(SRCS) $(CFLAGS) -o ../bin/cat

clean:
	rm *.o
