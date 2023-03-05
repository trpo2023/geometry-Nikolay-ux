all: main

main: main.o
	gcc -Wall -o main main.o

main.o: 
	gcc -Wall -c main.c

clean:
	rm main *.o

.PHONY: all clean