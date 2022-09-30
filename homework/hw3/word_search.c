// word_search.c
// <STUDENT: ADD YOUR INFO HERE: name, JHED, etc.>
// Name: Ryan Nguyen
// JHED: rnguye14


#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <ctype.h>
#include <assert.h> 
#include "search_functions.h"


/*
 * This is the HW3 main function that performs a word search.
 */
int main(int argc, char *argv[]) {
  //Determining if inputted file is valid
  if (argc != 2) {
    printf("Please enter a command line argument.\n"); 
    return 1;
  }
  FILE* file = fopen(argv[1], "r");
  if (file == NULL) {
    printf("Please enter a command line argument.");
    return 1; 
  }
  
  //Counting up grid size
  char ch1;
  int row_len = 0;
  int num_row = 0;
  int size_array[MAX_SIZE] = {0}; 
  while ((ch1 = fgetc(file))) {
    if (ch1 == '\n') {
      size_array[num_row] = row_len;
      num_row++; 
      row_len = 0;
      continue;
    }
    else if (ch1 == EOF){
      num_row++;
      break;
    }
    else {
      row_len++;
    }
  } 

  //Determining if the grid size is valid
  if ((num_row == 0) || (num_row > MAX_SIZE)) {
    printf("Invalid grid.\n");
    return -2;
  }
  for (int i = 0; i < (num_row - 1); i++) {  
    if (num_row != size_array[i]) {
      printf("Invalid grid.\n");
      return -2;
    }
  }

  //Asks for input
  char grid[MAX_SIZE][MAX_SIZE];
  int n = populate_grid(grid, argv[1]);
  char word[MAX_SIZE]; 
  int input;    
  while((input = scanf(" %s", word)) == 1) {
    find_all(grid, n, word, stdout);
  }
  if (input == EOF) {
    printf("Bye!\n");
  }
  fclose(file);
  return 0; 
}

