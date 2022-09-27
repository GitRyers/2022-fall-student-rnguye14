#include <stdio.h>
#include <string.h>
#include "string_functions.h"

int concat(const char word1[], const char word2[], char result[], int result_capacity){

   //TODO: replace the following stub with a correct function body so that
   //      this function behaves as indicated in the comment above
  int length = strlen(word1) + strlen(word2) + 1;  
  
  if (length > result_capacity) {
    return 1;
  }
  else {
    int i, j;

    for (i = 0; word1[i] != '\0'; ++i) {
      result[i] = (char) word1[i];
    }

    for (j = 0; word2[j] != '\0'; ++i, ++j) {
      result[i] = (char) word2[j];
    }
    result[i] = '\0';

    return 0;
  }
}
