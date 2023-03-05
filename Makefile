all: main

main: main.o
	gcc -Wall -Werror -o main main.o

main.o: 
	gcc -Wall -c main.c

clean:
	rm main *.o

run:
	./main

.PHONY: all clean