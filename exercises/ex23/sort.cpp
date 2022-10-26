#include <iostream>
#include <cassert>
#include <vector>
using std::cin; using std::cout; using std::endl; 
using std::vector; 

void sort(std::vector<int> *values);

void merge(const vector<int> *left, const vector<int> *right, vector<int> *values); 

int main(void) { 
  std::vector< int > vec;
  size_t count;

  std::cout << "Enter the count: ";

  // PART 2 TO DO: read in the count of random numbers from the standard input.
  cin >> count; 

  // PART 3 TO DO: Make the "vec" vector store "count" random values
  //Reserves memory for count number of elements in vector, avoiding repeated memory reallocations
  vec.reserve(count); 
  for (int i = 0; i < (int) count; i++) {
    vec.push_back(rand()); 
  } 

  sort( &vec );

  for( size_t i=1 ; i<vec.size() ; i++ ) assert( vec[i-1]<=vec[i] );

  return 0;
}

void sort( std::vector< int > *values ) {
  // PART 5 TO DO: Define the sort function
  if (values->size() > 1) {
    //Split vector into a left and right half
    size_t mid = values->size() / 2;
    vector<int> left(values->begin(), values->begin() + mid);
    vector<int> right(values->begin() + mid, values->end());

    //Sort each indvidual half and subsequent halves using recursion
    sort(&left);
    sort(&right); 

    //Merge all sorted halves together
    merge(&left, &right, values); 
  }
}

void merge(const vector<int> *left, const vector<int> *right, vector<int> *values) {
  vector<int>::const_iterator it_left = left->cbegin();
  vector<int>::const_iterator it_right = right->cbegin();
  values->clear();

  while(it_left != left->cend() && it_right != right->cend()) {
    if (*it_left <= *it_right) {
      values->push_back(*it_left);
      it_left++;
    }
    else {
      values->push_back(*it_right);
      it_right++;
    }
  }
}