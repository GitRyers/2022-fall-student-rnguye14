#include "complex.h"
#include <iostream>
#include <cmath>

using std::ostream; 
using std::cout; 
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
const Complex& Complex::operator=(const Complex& rhs) {
    rel = rhs.rel; 
    img = rhs.img; 
    return *this; 
}

// TODO: add operator
Complex Complex::operator+(const Complex& rhs) const {
    return Complex(rel + rhs.rel, img + rhs.img); 
}

// TODO: minus operator
Complex Complex::operator-(const Complex& rhs) const {
    return Complex(rel - rhs.rel, img - rhs.img); 
}

// TODO: times operator
Complex Complex::operator*(const Complex& rhs) const {
    float new_rel = rel * rhs.rel + (-1) * (img * rhs.img);
    float new_img = rel * rhs.img + img * rhs.rel;
    Complex result(new_rel, new_img); 
    return result; 
}

// TODO: times operator (float)
Complex Complex::operator*(const float& rhs) const {
    return Complex(rhs * rel, rhs * img);
}

// TODO: divide operator
Complex Complex::operator/(const Complex& rhs) const {
    float norm = rhs.rel * rhs.rel + rhs.img * rhs.img; 
    if (norm == 0) {
        return Complex(); 
    }
    float new_rel = (rel * rhs.rel + (-1) * (img * rhs.img)) / norm; 
    float new_img = (rel * rhs.img + img * rhs.rel) / norm; 
    return Complex(new_rel, new_img); 
}

//// things to be added for part 4 ////
// TODO: times operator for float times complex
Complex operator*(const float& lhs, const Complex& rhs) {
    return Complex(lhs * rhs.rel, lhs * rhs.img); 
}

