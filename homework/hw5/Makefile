CC=g++
CFLAGS=-std=c++11 -pedantic -Wall -Wextra

digraph_analyzer: digraph_analyzer.o digraph_functions.o
	$(CC) $(CFLAGS) -o digraph_analyzer digraph_analyzer.o digraph_functions.o

digraph_analyzer.o: digraph_analyzer.cpp digraph_analyzer.h 
	$(CC) $(CFLAGS) -c digraph_analyzer.cpp

digraph_functions.o: digraph_functions.cpp digraph_analyzer.h
	$(CC) $(CFLAGS) -c digraph_functions.cpp

clean:
	rm -f *.o digraph_analyzer
