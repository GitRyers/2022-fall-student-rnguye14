// word_search.c
// <STUDENT: ADD YOUR INFO HERE: name, JHED, etc.>
// Name: Ryan Nguyen
// JHED: rnguye14


#include <stdio.h>
#include <assert.h> 
#include "search_functions.h"


/*
 * This is the HW3 main function that performs a word search.
 */
int main(int argc, char* argv[]) {

  if (argv == NULL) {
    printf("Please enter a command line argument.\n"); 
    return 1;
  }

  FILE* grid = fopen(*argv, "r"); 

  if (grid == NULL) {
    printf("Grid file failed to open.\n");
    return -1;
  }

  

  fclose(grid); 
  return 0;

}

