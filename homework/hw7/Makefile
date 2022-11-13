CC=g++
CFLAGS=-std=c++11 -pedantic -Wall -Wextra

cTreeTest: CTreeTest.o 
	$(CC) $(CFLAGS) -o cTreeTest CTreeTest.o CTree.o 

CTreeTest.o: CTreeTest.cpp CTree.h 
	$(CC) $(CFLAGS) -c CTreeTest.cpp

CTree.o: CTree.cpp CTree.h
	$(CC) $(CFLAGS) -c CTree.cpp

tTreeTest: tTreeTest.o 
	$(CC) $(CFLAGS) -o tTreeTest TTreeTest.o 

TTreeTest.o: TTreeTest.cpp Tree.h 
	$(CC) $(CFLAGS) -c TTreeTest.cpp

clean:
	rm -f *.o cTreeTest tTreeTest