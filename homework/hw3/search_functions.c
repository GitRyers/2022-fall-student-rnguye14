// search_functions.c
// <STUDENT: ADD YOUR INFO HERE: name, JHED, etc.>
//Name: Ryan Nguyen
//JHED: rnguye14


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "search_functions.h"



/* 
 * Given a filename and a MAX_SIZExMAX_SIZE grid to fill, this function 
 * populates the grid and returns n, the actual grid dimension. 
 * If filename_to_read_from can't be opened, this function returns -1.
 * If the file contains an invalid grid, this function returns -2.
 */
int populate_grid(char grid[][MAX_SIZE], char filename_to_read_from[]){
  FILE* file = fopen(filename_to_read_from, "r");
  int n = 0;
  char ch1; 
  while ((ch1 = fgetc(file)) != '\n') {
    if (isalpha(ch1) != 0) {
      n++;
    }
  }
  
  //Creates grid
  int i = 0;
  int j = 0; 
  char ch2;
  rewind(file); 
  while ((ch2 = fgetc(file)) != EOF) {
    if (i == n) {
      break;
    }
    if (ch2 == '\n') {
      i++;
      j = 0; 
      continue; 
    }
    else { 
      grid[i][j] = tolower(ch2);
      j++; 
    }
  }
  fclose(file); 
  return n;  
}

void strlower(char *str) {
  int len = strlen(str);   
  for(int i = 0; i < len; i++){
    str[i] = tolower(str[i]);
  }  
}

void strrev(char *str){
  char *p1, *p2;
  for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2){
    *p1 ^= *p2;
    *p2 ^= *p1;
    *p1 ^= *p2;
  }
}

int find_right(char grid[][MAX_SIZE], int n, char word[], FILE *write_to){ 
  //Initializing search word  
  int num_found = 0;
  int len = strlen(word);
  strlower(word); 
  

  //Finding words  
  for (int i = 0; i < n; i++) {
    int pos = 0;      
    while ((pos <= (n-len))) {
      char *cmp_word = malloc(sizeof(char) * (len + 1));   
      for (int j = 0; j < len; j++) {
	      *(cmp_word + j) = grid[i][j + pos];
      } 
      cmp_word[len] = '\0'; 
      if (strcmp(word, cmp_word) == 0) { 
	      fprintf(write_to, "%s %d %d R\n", word, i, pos);
        num_found++;  
      }
      free(cmp_word); 
      pos++; 
     }
    }
  if (num_found == 0) {
    printf("%s - Not found\n", word); 
  }
  return 0; 
}


int find_left (char grid[][MAX_SIZE], int n, char word[], FILE *write_to){
  //Initializing search word
  int num_found = 0;
  int len = strlen(word);
  strlower(word);
  strrev(word);  
  
  //Finding words          
  for (int i = 0; i < n; i++) {
    int pos = 0;     
    while ((pos <= (n-len))) {
      char *cmp_word = malloc(sizeof(char) * (len + 1));   
      for (int j = 0; j < len; j++) {
	      *(cmp_word + j) = grid[i][j + pos];
      } 
      cmp_word[len] = '\0'; 
      if (strcmp(word, cmp_word) == 0) {
        strrev(word);
	      fprintf(write_to, "%s %d %d L\n", word, i, pos);
        num_found++;  
        strrev(word); 
      }
      free(cmp_word); 
      pos++; 
     }
    } 
  strrev(word);  
  if (num_found == 0) {
    printf("%s - Not found\n", word); 
  }
  return 0; 
}


int find_down (char grid[][MAX_SIZE], int n, char word[], FILE *write_to){
  //Initializing search word  
  int num_found = 0;
  int len = strlen(word);
  strlower(word); 

  //Finding words 
  for (int i = 0; i < n; i++) {
    int pos = 0;     
    while ((pos <= (n-len))) {
      char *cmp_word = malloc(sizeof(char) * (len + 1));   
      for (int j = 0; j < len; j++) {
	      *(cmp_word + j) = grid[j + pos][i];
      } 
      cmp_word[len] = '\0'; 
      if (strcmp(word, cmp_word) == 0) { 
	      fprintf(write_to, "%s %d %d D\n", word, pos, i);
        num_found++;  
      }
      free(cmp_word); 
      pos++; 
     }
    }
  if (num_found == 0) {
    printf("%s - Not found\n", word); 
  }
  return 0; 
}


int find_up   (char grid[][MAX_SIZE], int n, char word[], FILE *write_to){
  //Initializing search word  
  int num_found = 0;
  int len = strlen(word);
  strlower(word);
  strrev(word);  

  //Finding words 
  for (int i = 0; i < n; i++) {
    int pos = 0;     
    while ((pos <= (n-len))) {
      char *cmp_word = malloc(sizeof(char) * (len + 1));   
      for (int j = 0; j < len; j++) {
	      *(cmp_word + j) = grid[j + pos][i];
      } 
      cmp_word[len] = '\0'; 
      if (strcmp(word, cmp_word) == 0) { 
        strrev(word); 
	      fprintf(write_to, "%s %d %d U\n", word, (pos + len - 1), i);
        num_found++;
        strrev(word);  
      }
      free(cmp_word); 
      pos++; 
     }
    }
  strrev(word);  
  if (num_found == 0) {
    printf("%s - Not found\n", word); 
  }
  return 0; 
}

int find_all  (char grid[][MAX_SIZE], int n, char word[], FILE *write_to) {
  find_right(grid, n, word, write_to);
  find_left(grid, n, word, write_to); 
  find_down(grid, n, word, write_to); 
  find_up(grid, n, word, write_to); 
  return 0; 
} 


/*
 * Reads lhs and rhs character by character until either reaches eof.
 * Returns true if the files can be read and the two files match
 * character by character. Returns false if two files either can't be
 * opened or don't match. The definition of this function is provided 
 * for you.
 */
int file_eq(char lhs_name[], char rhs_name[]) {
  FILE* lhs = fopen(lhs_name, "r");
  FILE* rhs = fopen(rhs_name, "r");

  // don't compare if we can't open the files
  if (lhs == NULL || rhs == NULL) return 0;

  int match = 1;
  // read until both of the files are done or there is a mismatch
  while (!feof(lhs) || !feof(rhs)) {
	if (feof(lhs) ||                      // lhs done first
		feof(rhs) ||                  // rhs done first
		(fgetc(lhs) != fgetc(rhs))) { // chars don't match
	  match = 0;
	  break;
	}
  }
  fclose(lhs);
  fclose(rhs);
  return match;
}