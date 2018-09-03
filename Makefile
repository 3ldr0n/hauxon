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
<<<<<<< HEAD
	rm *.o
	rm bin/*
=======
	rm -rf bin
>>>>>>> 642483719d75a45b747abdc880ec38f87de06d43
