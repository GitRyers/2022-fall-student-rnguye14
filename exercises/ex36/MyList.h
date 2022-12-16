#ifndef MYLIST_H
#define MYLIST_H

#include <iostream>
#include "MyNode.h"

// A linked list template

template<typename T>
class MyList {

 private:
  MyNode<T>* head; // pointer to first node in linked list

 public:

  // *** DON'T CHANGE THIS FILE ABOVE THIS POINT ***


  /*-------------------------------------------------*/

  // TODO Part 3a:
  // For the nested iterator class `iterator`, you will have to
  // provide implementations for the member functions commented out.
  // You will also have to un-comment and implement the begin()
  // and end() MyList class member functions below.
  class iterator {
    MyNode<T>* ptr;

  public:
  
  iterator(MyNode<T>* initial) : ptr(initial) { }

    iterator& operator++() {
      ptr = ptr->next; 
      return *this; 
    }
  
    bool operator!=(const iterator& o) const {
      return (o.ptr != ptr ? false : true);
    }

    T& operator*() {
      return ptr->data; 
    }

  };

  MyNode<T>* begin() {
    return head; 
  }

  MyNode<T>* end() {
    MyNode<T>* cur = head;
    while(cur->next != nullptr) {
      cur = cur->next;
    }
    return cur; 
  } 

  /*-------------------------------------------------*/


  // TODO Part 4a:
  // For the nested iterator class `const_iterator`, you will have
  // to implement something like `iterator` but with additional
  // `const` constraints to disallow modification of the elements
  // via operator*().
  //
  // You will also have to un-comment and implement below the 
  // MyList class member functions cbegin() and cend().
  
  // class const_iterator {
  //     ...
  // };

  // const_iterator cbegin() const { ... }

  // const_iterator cend() const { ... }


  /*-------------------------------------------------*/


  // TODO Part 5:
  // You will need to un-comment and implement the MyList
  // constructor below which takes a begin and end iterator.
  //
  // Constructor for MyList that sets the linked list
  // to contain the elements in the container with begin
  // and end iterators provided as arguments.
  // template<typename Itr>
  //  MyList<T>(Itr i_begin, Itr i_end){
  //     ...
  // };




  // *** DON'T CHANGE THIS FILE BELOW THIS POINT ***

  MyList<T>() : head(nullptr) { } // create empty linked list
    
  ~MyList<T>();                   // deallocate all nodes

  void insertAtHead(const T& d);  // create new MyNode and add at head

  void insertAtTail(const T& d);  // create new MyNode and add at tail

  // get const pointer to head node
  const MyNode<T>* get_head() const { return head; }

};


#include "MyList.inc"

#endif
