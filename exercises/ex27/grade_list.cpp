#include "grade_list.h"
#include <algorithm>
#include <cassert>
#include <cstddef>

using std::sort;

// You will add function definitions to this file.
// See TODOs in grade_list.h.

// The "percentile" member function was declared
// (prototyped) in the GradeList class definition.
// But the implementation wasn't given there.  Here
// we give the definition.

// When we define a member function outside the class
// definition, we write the function name as
// <class name>::<member function name>.  E.g. here
// we write "GradeList::percentile"

/////////////////////////////////////////////////////////

// Retrieve grade at the given percentile.  
// This function is complete.
double GradeList::percentile(double percentile) {
  assert(percentile >= 0 && percentile <= 100.0);
  if (!is_sorted) {
    sort(grades.begin(), grades.end());
    is_sorted = true;
  }
  size_t select = percentile / 100.0 * grades.size();
  // Handle case where percentile == 100.0
  if (select == grades.size()) {
    select = grades.size()-1;
  }
  return grades[select];
}

double GradeList::mean(void) {
  double sum = 0.0;
  int count = 0;
  for (std::vector<double>::iterator vit = grades.begin(); vit != grades.end(); ++vit) {
    sum += *vit;
    count++;
  } 
  return sum / count; 
}

double GradeList::median(void) {
  return percentile(50.0); 
}

size_t GradeList::getSize(void) {
  return grades.size(); 
}

double GradeList::getGrade(int num) {
  return grades[num]; 
}
