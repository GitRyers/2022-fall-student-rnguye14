#include <stdio.h>
#include <stddef.h> // for ptrdiff_t
#include <assert.h>

// TODO: add declaration of search function
int *search(int *start, int *end, int search_val);

int main(void) {
  // this variable will point to the matching element
  // if the search is successful, otherwise it will
  // be a NULL value
  int *pos;

  // variable in which the computed index of an element
  // found by a successful search can be stored
  ptrdiff_t index;

  // sorted array of int values for testing
  int arr1[] = { 11, 119, 318, 518, 573, 750, 757, 809, 813, 994 };

  // example of a successful search
  pos = search(arr1, arr1 + 10, 809);
  assert(pos != NULL);
  assert(*pos == 809);
  index = &arr1[7] - &arr1[0];  
  assert(7 == index); 

  // example of an unsuccessful search
  pos = search(arr1, arr1 + 10, 385);
  assert(pos == NULL); 

  // TODO: compute the index of the matching element  
  pos = search(arr1, arr1 + 10, 11);
  assert(pos != NULL);
  assert(*pos == 11);
  index = &arr1[0] - &arr1[0];  
  assert(0 == index); 

  // TODO: compute the index of the matching element
  pos = search(arr1, arr1 + 10, 318);
  assert(pos != NULL);
  assert(*pos == 318);
  index = &arr1[2] - &arr1[0];
  assert(2 == index); 

  // TODO: compute the index of the matching element
  pos = search(arr1, arr1 + 10, 573);
  assert(pos != NULL);
  assert(*pos == 573);
  index = &arr1[4] - &arr1[0];
  assert(4 == index);

  pos = search(arr1, arr1 + 10, 222);
  assert(pos == NULL);

  pos = search(arr1, arr1 + 10, 103);
  assert(pos == NULL);

  pos = search(arr1, arr1 + 10, 300);
  assert(pos == NULL);

  printf("All tests pass!\n");
  return 0;
}

// TODO: add definition of search function
int *search(int *start, int *end, int search_val) {
  while (start < end) {
      int index = ((int) (end - start)) / 2; 
      int *mid = start + index; 
      if (*mid == search_val)
         return mid;
      if (*mid < search_val)
         start++;
      else
         end--;
   }
   return NULL;
}