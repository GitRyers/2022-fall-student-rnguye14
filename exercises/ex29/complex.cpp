#include "complex.h"
#include <iostream>

using std::ostream; 
using std::endl; 

// You will add function definitons to this file
// See TODOs in complex.h

//// things to be added for part 2 ////
// TODO: operator<<
ostream& operator<<(ostream& os, const Complex& c) {
    os << c.rel << " + " << c.img << 'i'; 
    return os; 
}

//// things to be added for part 3 ////
// TODO: copy constructor
Complex::Complex(const Complex& rhs): rel(rhs.rel), img(rhs.img) {}

// TODO: assignment operator
Complex& Complex::operator=(const Complex& rhs) {
    
}

// TODO: add operator


// TODO: minus operator


// TODO: times operator


// TODO: times operator (float)


// TODO: divide operator


//// things to be added for part 4 ////
// TODO: times operator for float times complex


