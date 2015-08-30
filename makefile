#specify compiler
CC=g++

#flags
CFLAGS=-c -Wall

all: mechturk

mechturk: main.o game.o stockfishio.o
	$(CC) main.o game.o stockfishio.o -o mechturk

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

game.o: game.cpp
	$(CC) $(CFLAGS) game.cpp

stockfishio.o: stockfishio.cpp
	$(CC) $(CFLAGS) stockfishio.cpp

clean:
	rm *o mechturk
