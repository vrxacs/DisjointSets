CC = g++
CFLAGS = -Wall -pedantic -std=c++0x -O3

all: DisjointSet.out

DisjointSet.out: DisjointSet.h test.cpp
	$(CC) $(CFLAGS) DisjointSet.h test.cpp