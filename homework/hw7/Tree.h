#ifndef _TREE_H
#define _TREE_H

#include <iostream>
#include <cstdlib>
#include <string>

// tree of characters, can be used to implement a trie
template<typename T>
class CTree {
  friend class CTreeTest;
  
  T data;     // the value stored in the tree node

  CTree<T> kids;  // children - pointer to first child of list, maintain order & uniqueness

  CTree<T> sibs;  // siblings - pointer to rest of children list, maintain order & uniqueness
                 // this should always be null if the object is the root of a tree

  CTree<T> prev;  // pointer to parent if this is a first child, or left sibling otherwise
                 // this should always be null if the object is the root of a tree

 public:
  friend std::ostream& operator<<(std::ostream& os, CTree& rt);
  CTree(T val, CTree<T> k = NULL, CTree<T> s = NULL, CTree<T> p = NULL): data(val), kids(k), sibs(s), prev(p) {}; 

  ~CTree();  // clear siblings to right and children and this node

  void printData() {std::cout << data << std::endl;}; 
  
  CTree& operator+(CTree<T>& rt);  //^ operator to do the same thing as addChild
  bool operator==(const CTree<T> &root); // return true if two CTrees match node by node
  
  int checkUniq(T val, CTree<T> node); //returns true if character is unique amongst its sibilings 

  // siblings and children must be unique, return true if added, false otherwise
  bool addChild(T val);

  // add tree root for better building, root should have null prev and sibs 
  // returns false on any type of failure, including invalid root
  bool addChild(CTree<T> root);

  std::string toString(); // all characters, separated by newlines, including at the end
  
  template<typename U> 
  friend std::ostream& operator<<(std::ostream& os, CTree<U>& node); 
  
 private:
  // these should only be called from addChild, and have the same restrictions
  // the root of a tree should never have any siblings
  // returns false on any type of failure, including invalid root
  bool addSibling(T val);
  bool addSibling(CTree<T> root);
  bool treeCompare(const CTree<T> a, const CTree<T> b) const;
};

#include "Tree.inc"
#endif