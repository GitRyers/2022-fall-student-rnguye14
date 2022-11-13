CC=g++
CFLAGS=-std=c++11 -pedantic -Wall -Wextra

cTreeTest: cTreeTest.o 
	$(CC) $(CFLAGS) -o CTreeTest CTreeTest.o 

tTreeTest: tTreeTest.o 
	$(CC) $(CFLAGS) -o TTreeTest TTreeTest.o 

cTreeTest.o: CTreeTest.cpp CTree.h CTree.cpp
	$(CC) $(CFLAGS) -c CTreeTest.cpp CTree.h

tTreeTest.o: TTreeTest.cpp Tree.h Tree.inc
	$(CC) $(CFLAGS) -c TTreeTest.cpp

clean:
	rm -f *.o cTreeTest tTreeTest