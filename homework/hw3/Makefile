CC=gcc
CFLAGS= -std=c99 -pedantic -Wall -Wextra

#Linking word_search and search_functions
word_search: word_search.o search_functions.o  
	$(CC) -o word_search word_search.o search_functions.o -g

#Linking test_search_functions and search_functions
test: test_search_functions.o search_functions.o
	$(CC) -o test test_search_functions.o search_functions.o -g

#Assembles word_search.c to word_search.o
word_search.o: word_search.c search_functions.h
	$(CC) $(CFLAGS) -c word_search.c

#Assembles search_functions.c to search_functions.o 
search_functions.o: search_functions.c search_functions.h
	$(CC) $(CFLAGS) -c search_functions.c

#Assembles test_search_functions.c to test_search_functions.c with header file search_functions.h
test_search_functions.o: test_search_functions.c search_functions.h 
	$(CC) $(CFLAGS) -c test_search_functions.c

#Removes all object files and executable named word_search
clean:
	rm -f *.o word_search test 