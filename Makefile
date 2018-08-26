CC=gcc
CFLAGS=-std=c11 -I.
DEPS=malloc_s.h
OBJ=malloc_s.o cat.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

cat: $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o bin/cat

clean:
	rm *.o
