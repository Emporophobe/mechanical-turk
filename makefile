#specify compiler
CC=g++

#flags
CFLAGS=-c -Wall -std=c++11

all: mechturk

mechturk: main.o game.o sfio.o board.o
	$(CC) main.o game.o sfio.o board.o -o mechturk

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

game.o: game.cpp
	$(CC) $(CFLAGS) game.cpp

sfio.o: sfio.cpp
	$(CC) $(CFLAGS) sfio.cpp

board.o: board.cpp
	$(CC) $(CFLAGS) board.cpp

clean:
	rm *o mechturk sfcmds.txt

