// test_search_functions.c
// <STUDENT: ADD YOUR INFO HERE: name, JHED, etc.>
// Name: Ryan Nguyen
// JHED: rnguye14



#include <stdio.h>
#include <assert.h>
#include "search_functions.h"


/* 
 * Declarations for tester functions whose definitions appear below.
 * (You will need to fill in the function definition details, at the
 * end of this file, and add comments to each one.) 
 * Additionally, for each helper function you elect to add to the 
 * provided search_functions.h, you will need to supply a corresponding
 * tester function in this file.  Add a declaration for it here, its
 * definition below, and a call to it where indicated in main.
 */
void test_file_eq();      // This one is already fully defined below.
void test_populate_grid();
void test_find_right();
void test_find_left();
void test_find_down();
void test_find_up();
void test_find_all();


/*
 * Main method which calls all test functions.
 */
int main() {
  printf("Testing file_eq...\n");
  test_file_eq();
  printf("Passed file_eq test.\n\n");

  printf("Running search_functions tests...\n");
  test_populate_grid();
  test_find_right();
  test_find_left();
  test_find_down();
  test_find_up();
  test_find_all();

  /* You may add calls to additional test functions here. */

  printf("Passed search_functions tests!!!\n");
}



/*
 * Test file_eq on same file, files with same contents, files with
 * different contents and a file that doesn't exist.
 * Relies on files test1.txt, test2.txt, test3.txt being present.
 */
void test_file_eq() {
  FILE* fptr = fopen("test1.txt", "w");
  fprintf(fptr, "this\nis\na test\n");
  fclose(fptr);

  fptr = fopen("test2.txt", "w");
  fprintf(fptr, "this\nis\na different test\n");
  fclose(fptr);

  fptr = fopen("test3.txt", "w");
  fprintf(fptr, "this\nis\na test\n");
  fclose(fptr);

  assert( file_eq("test1.txt", "test1.txt"));
  assert( file_eq("test2.txt", "test2.txt"));
  assert(!file_eq("test2.txt", "test1.txt"));
  assert(!file_eq("test1.txt", "test2.txt"));
  assert( file_eq("test3.txt", "test3.txt"));
  assert( file_eq("test1.txt", "test3.txt"));
  assert( file_eq("test3.txt", "test1.txt"));
  assert(!file_eq("test2.txt", "test3.txt"));
  assert(!file_eq("test3.txt", "test2.txt"));
  assert(!file_eq("", ""));  // can't open file
}



void test_populate_grid(){
  FILE* fptr = fopen("test1.txt", "r");
  printf("this\nis\na test\n");
  char grid[MAX_SIZE][MAX_SIZE];
  int n = populate_grid(grid, "test1.txt");
  char ch; 
  while ((ch = fgetc(fptr)) != EOF) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (ch != grid[i][j]) {
          printf("Grid does not match file.\n"); 
        }
      }
    }
  }
  fclose(fptr);

  fptr = fopen("test2.txt", "r");
  printf("this\nis\na test\n");
  n = populate_grid(grid, "test2.txt");
  while ((ch = fgetc(fptr)) != EOF) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (ch != grid[i][j]) {
          printf("Grid does not match file.\n");
        }
      }
    }
  }
  fclose(fptr);

  fptr = fopen("test3.txt", "r");
  printf("this\nis\na test\n");
  n = populate_grid(grid, "test3.txt");
  while ((ch = fgetc(fptr)) != EOF) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (ch != grid[i][j]) {
          printf("Grid does not match file.\n");
        }
      }
    }
  }
  fclose(fptr);
}


void test_find_right(){
  FILE* fptr = fopen("test1.txt", "r");
  printf("this\nis\na test\n");
  char grid[MAX_SIZE][MAX_SIZE];
  int n = populate_grid(grid, "test1.txt");
  char word[] = "top";  
  find_right(grid, n, word, stdout);
  char output[] = "top - Not Found\n"; 
  if (scanf("%s", output)) {
    printf("Could not find search word.\n"); 
  } 
  fclose(fptr); 

  fptr = fopen("test2.txt", "r");
  printf("this\nis\na test\n");
  n = populate_grid(grid, "test2.txt");
  char word2[] = "effgo";  
  find_right(grid, n, word2, stdout);
  char output2[] = "effgo - Not Found\n"; 
  if (scanf("%s", output2)) {
    printf("Could not find search word.\n"); 
  } 
  fclose(fptr); 

  fptr = fopen("test3.txt", "r");
  printf("this\nis\na test\n");
  n = populate_grid(grid, "test3.txt");
  char word3[] = "poooooooop";  
  find_right(grid, n, word3, stdout);
  char output3[] = "poooooooop - Not Found\n"; 
  if (scanf("%s", output3)) {
    printf("Could not find search word.\n"); 
  } 
  fclose(fptr); 
}


void test_find_left(){

  FILE* fptr = fopen("test1.txt", "r");
  printf("this\nis\na test\n");
  char grid[MAX_SIZE][MAX_SIZE];
  int n = populate_grid(grid, "test1.txt");
  char word[] = "pot";  
  find_left(grid, n, word, stdout);
  char output[] = "pot - Not Found\n"; 
  if (scanf("%s", output)) {
    printf("Could not find search word.\n"); 
  } 
  fclose(fptr); 

  fptr = fopen("test2.txt", "r");
  printf("this\nis\na test\n");
  n = populate_grid(grid, "test2.txt");
  char word2[] = "ogffe";  
  find_left(grid, n, word2, stdout);
  char output2[] = "ogffe - Not Found\n"; 
  if (scanf("%s", output2)) {
    printf("Could not find search word.\n"); 
  } 
  fclose(fptr); 

  fptr = fopen("test3.txt", "r");
  printf("this\nis\na test\n");
  n = populate_grid(grid, "test3.txt");
  char word3[] = "poooooooop";  
  find_left(grid, n, word3, stdout);
  char output3[] = "poooooooop - Not Found\n"; 
  if (scanf("%s", output3)) {
    printf("Could not find search word.\n"); 
  } 
  fclose(fptr); 
}


void test_find_down(){
  FILE* fptr = fopen("test1.txt", "r");
  printf("this\nis\na test\n");
  char grid[MAX_SIZE][MAX_SIZE];
  int n = populate_grid(grid, "test1.txt");
  char word[] = "key";  
  find_down(grid, n, word, stdout);
  char output[] = "key - Not Found\n"; 
  if (scanf("%s", output)) {
    printf("Could not find search word.\n"); 
  } 
  fclose(fptr); 

  fptr = fopen("test2.txt", "r");
  printf("this\nis\na test\n");
  n = populate_grid(grid, "test2.txt");
  char word2[] = "qesso";  
  find_down(grid, n, word2, stdout);
  char output2[] = "qesso - Not Found\n"; 
  if (scanf("%s", output2)) {
    printf("Could not find search word.\n"); 
  } 
  fclose(fptr); 

  fptr = fopen("test3.txt", "r");
  printf("this\nis\na test\n");
  n = populate_grid(grid, "test3.txt");
  char word3[] = "poooooooop";  
  find_down(grid, n, word3, stdout);
  char output3[] = "poooooooop - Not Found\n"; 
  if (scanf("%s", output3)) {
    printf("Could not find search word.\n"); 
  } 
  fclose(fptr); 
}


void test_find_up(){
  FILE* fptr = fopen("test1.txt", "r");
  printf("this\nis\na test\n");
  char grid[MAX_SIZE][MAX_SIZE];
  int n = populate_grid(grid, "test1.txt");
  char word[] = "yek";  
  find_up(grid, n, word, stdout);
  char output[] = "yek - Not Found\n"; 
  if (scanf("%s", output)) {
    printf("Could not find search word.\n"); 
  } 
  fclose(fptr); 

  fptr = fopen("test2.txt", "r");
  printf("this\nis\na test\n");
  n = populate_grid(grid, "test2.txt");
  char word2[] = "osseq";  
  find_down(grid, n, word2, stdout);
  char output2[] = "osseq - Not Found\n"; 
  if (scanf("%s", output2)) {
    printf("Could not find search word.\n"); 
  } 
  fclose(fptr); 

  fptr = fopen("test3.txt", "r");
  printf("this\nis\na test\n");
  n = populate_grid(grid, "test3.txt");
  char word3[] = "poooooooop";  
  find_down(grid, n, word3, stdout);
  char output3[] = "poooooooop - Not Found\n"; 
  if (scanf("%s", output3)) {
    printf("Could not find search word.\n"); 
  } 
  fclose(fptr); 
}


void test_find_all(){
  test_find_right();
  test_find_left();
  test_find_down();
  test_find_up(); 
}

