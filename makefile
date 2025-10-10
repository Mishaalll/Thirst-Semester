CC = gcc

struct:
	$(CC) struct.c mylib.c -o struct.o

clean:
	rm *.o
