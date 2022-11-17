CC=g++
CFLAGS=-std=c++11 -pedantic -Wall -Wextra

cTreeTest: CTreeTest.cpp CTree.cpp CTree.h 
	$(CC) $(CFLAGS) -c CTree.cpp
	$(CC) $(CFLAGS) -c CTreeTest.cpp
	$(CC) $(CFLAGS) -o cTreeTest CTreeTest.o CTree.o

tTreeTest: TTreeTest.cpp Tree.h
	$(CC) $(CFLAGS) -c TTreeTest.cpp
	$(CC) $(CFLAGS) -o tTreeTest TTreeTest.o 

clean:
	rm -f *.o vgcore.* cTreeTest tTreeTest