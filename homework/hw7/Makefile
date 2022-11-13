CC=g++
CFLAGS=-std=c++11 -pedantic -Wall -Wextra

CTreeTest: CTreeTest.o 
	$(CC) $(CFLAGS) -o CTreeTest CTreeTest.o 

TTreeTest: TTreeTest.o 
	$(CC) $(CFLAGS) -o TTreeTest TTreeTest.o 

CTreeTest.o: CTreeTest.cpp CTree.h
    $(CC) $(CFLAGS) -c CTreeTest.cpp

TTreeTest.o: TTreeTest.cpp CTree.h
	$(CC) $(CFLAGS) -c TTreeTest.cpp

clean:
	rm -f *.o CTreeTest TTreeTest