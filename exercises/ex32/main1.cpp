// 601.220 - example of inheritance, virtual functions, dynamic binding

#include "Aclass.h"
#include "Bclass.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main (void) {
  A aobj(1);
  A* aptr;
  B bobj(2);
  B* bptr;

  aptr = &aobj;
  aptr->show();
  aptr->display(); 
  cout << endl;
  //aobj.d = 17.5;  Variable d is declared as protected in Class A so cannot be directly accessed   

  bptr = &bobj;
  aptr = bptr;   
  //aptr->setb(15);  Neither variable b nor member function setb is not available in Class A   
  aptr->seta(3);
  aptr->show();     
  cout << endl;
  aptr->display();  

  cout << endl;
  aobj = A(10);
  aobj.show();
  aobj = bobj;
  aobj.show(); 
  A a5(5);
  //bobj = a5;  There is no defined member function to assign an A Class object to B class object  

}


