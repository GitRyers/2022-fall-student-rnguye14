#include "grade_list.h"
#include <cassert>

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
GradeList::GradeList(int capacity = 1): capacity(capacity) { 
    assert(capacity > 0);
    count = 0; 
    grades = new double[capacity];
  } 

// TODO: Add the given grade to the grades list. If the array is full,
// resize it by doubling its length. Do not use realloc!
void GradeList::add(double grade) { 
  if ((count + 1) > capacity) {
    //Initialize temporary vector to hold grades list values 
    std::vector<double> temp; 
    for (int i = 0; i < count; i++) {
      temp.push_back(grades[i]); 
    }

    //Delete and reallocate memory
    delete[] grades; 
    capacity *= 2; 
    grades = new double[capacity];

    //Add existing values back to newly dynamically allocated array 
    for (int i = 0; i < count; i++) {
      grades[i] = temp.at(i); 
    }
  }
  count++; 
  grades[count - 1] = grade; 
}

// TODO: Add the specified number of values from an array of 
// grades to this object.
void GradeList::add(int howmany, double * grades) {
  for (int i = 0; i < howmany; i++) {
    add(grades[i]);
  }
}

// TODO: write a function (in grade_list.cpp) to clear the list
// of all values, making the array as small as possible
void GradeList::clear() {
  delete[] grades; 
  count = 0; 
  capacity = 1; 
  grades = new double[capacity]; 
}

std::vector<double>::const_iterator begin() {

}

std::vector<double>::const_iterator end() {

}

