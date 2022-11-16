#include <iostream>

#ifndef _BCLASS_H
#define _BCLASS_H

#include "Aclass.h"

class B : public A {
private:
  int b;

public:
  B(int val = 0): A(), b(val) { };  // automatically sets a & d to 0 w/ A()
  B(int bval, int aval, double dval): A(aval, dval), b(bval) {
     d = 17; 
     seta(27); 
  };
  ~B() { std::cout << "B obj killed" << std::endl; } ;
  void setb(int val) { b = val; };
  void display() { std::cout << "non-virtual display B " << std::endl; show(); };
  void test() { std::cout << "test B" << std::endl; };
  virtual void show() override { A::show(); std::cout << "B is " << b << std::endl; test(); };
  virtual void toString() const override {std::cout << "[Aclass: a = " << a << ", d = " << d << ", size = " << d << std::endl;};
};

#endif
