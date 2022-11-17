CC=g++
CFLAGS=-std=c++11 -pedantic -Wall -Wextra

CTree.o: CTree.cpp CTree.h
	$(CC) $(CFLAGS) -c CTree.cpp

CTreeTest.o: CTreeTest.cpp CTree.h 
	$(CC) $(CFLAGS) -c CTreeTest.cpp

cTreeTest: CTreeTest.o 
	$(CC) $(CFLAGS) -o cTreeTest CTreeTest.o CTree.o

TTreeTest.o: TTreeTest.cpp Tree.h 
	$(CC) $(CFLAGS) -c TTreeTest.cpp

tTreeTest: TTreeTest.o 
	$(CC) $(CFLAGS) -o tTreeTest TTreeTest.o 

clean:
	rm -f *.o vgcore.* cTreeTest tTreeTest