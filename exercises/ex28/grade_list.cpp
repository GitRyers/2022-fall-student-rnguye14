#include "grade_list.h"
#include <cassert>
#include <cstddef>

// You will add function definitions to this file.
// See TODOs in grade_list.h.

double GradeList::min() {
  assert(count > 0);   // no values otherwise
  double minval = grades[0];
  for (int i = 1; i < count; i++) {
    if (grades[i] < minval)
      minval = grades[i];
  }
  return minval;
}

//////////// things to be added for part 2  /////////////////

// TODO: write a constructor (in grade_list.cpp) that has a 
// parameter indicating the starting length of the array. 
GradeList::GradeList(int capacity): capacity(capacity), count(0), grades(new double[capacity]) { assert(capacity > 0); } 

GradeList::GradeList(const GradeList & from): capacity(from.capacity), count(from.count), grades(new double[capacity]) { 
  for (int i = 0; i < count; i++) {
    grades[i] = from.grades[i]; 
  }
} 

// TODO: Add the given grade to the grades list. If the array is full,
// resize it by doubling its length. Do not use realloc!
void GradeList::add(double grade) { 
  if (count == capacity) {
    //Adjust capacity of array
    capacity *= 2; 
    
    //Initialize temporary dynamically allocated array to hold values 
    double *temp = new double[capacity]; 
    for (int i = 0; i < count; i++) {
      temp[i] = grades[i]; 
    }

    //Delete and assign grades to temp 
    if (grades != NULL) {
      delete[] grades; 
    }
    grades = temp;
  }
  grades[count++] = grade; 
}

// TODO: Add the specified number of values from an array of 
// grades to this object.
void GradeList::add(int howmany, double * grades) {
  for (int i = 0; i < howmany; ++i) {
    add(grades[i]);
  }
}

// TODO: write a function (in grade_list.cpp) to clear the list
// of all values, making the array as small as possible
void GradeList::clear() {
  if (grades != NULL) {
    delete[] grades; 
  }
  count = 0; 
  capacity = 1; 
  grades = new double[capacity]; 
}