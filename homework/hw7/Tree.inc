#include "Tree.h"
#include <iostream>
#include <string> 
#include <typeinfo>
#include <sstream>

using std::cout;
using std::endl; 
using std::string; 

//Destructor
template <typename T>
Tree<T>::~Tree() {
    delete sibs;
    delete kids;  
}

template <typename T>
Tree<T>& Tree<T>::operator+(Tree<T>& rt) {
    addChild(&rt);
    return *this;  
}

template <typename T>
bool Tree<T>::operator==(const Tree<T> &root) {
    return treeCompare(this, &root); 
}

template <typename T>
int Tree<T>::checkUniq(T val, Tree<T> * node) {
    int count = 0;  
    if (node->data != val) { 
        if (node->sibs != NULL) { 
            count += checkUniq(val, node->sibs); 
        } 
    }
    else {
        count++;  
    }
    return count; 
}

template <typename T>
bool Tree<T>::addChild(T val) {
    if (kids) {
        if (checkUniq(val, kids) == 0) {
            Tree<T> *cur = kids;
            while (cur) {
                if (val > cur->data) {
                    if (cur->sibs == NULL) {
                        cur->sibs = new Tree<T>(val, NULL, NULL, cur); 
                        break; 
                    }
                    else {
                        cur = cur->sibs; 
                    }
                }
                else {
                    Tree<T> *node = new Tree<T>(val, NULL, cur, cur->prev); 
                    if (cur->prev->kids == cur) {
                        cur->prev->kids = node; 
                    }
                    else {
                        cur->prev->sibs = node;
                        cur->prev = node; 
                    }
                    break; 
                }
            } 
            return true; 
        }
        else {
            return false; 
        }
    }
    else {
        kids = new Tree<T>(val, NULL, NULL, this); 
        return true; 
    }
}

template <typename T>
bool Tree<T>::addChild(Tree<T> *root) {
    if (!root->prev||!root->sibs) {
        if (kids) {
            if (checkUniq(root->data, kids) == 0) {
                Tree<T> *cur = kids;
                while (cur) {
                    if (root->data > cur->data) {
                        if (cur->sibs == NULL) {
                            cur->sibs = root;
                            root->prev = cur->sibs;  
                            break; 
                        }
                        else {
                            cur = cur->sibs; 
                        }
                    }
                    else {
                        root->prev = cur->prev; 
                        root->sibs = cur;
                        if (cur->prev->kids == cur) {
                            cur->prev->kids = root; 
                        }
                        else {
                            cur->prev->sibs = root;
                            cur->prev = root;  
                        }
                        break; 
                    }
                } 
                return true; 
            }
            else {
                return false; 
            }
        }
        else {
            kids = root; 
            root->prev = this; 
            return true; 
        }
    }  
    else {
        return false; 
    }
}

template <typename T>
string Tree<T>::toString() {
    std::stringstream ss;
    ss << data << endl;  
    std::string str = ss.str(); 
    if (kids) {
        str = str + kids->toString(); 
    } 
    if (sibs) {
        str = str + sibs->toString(); 
    }
    return str; 
}

template <typename T>
bool Tree<T>::addSibling(T val) {
    if (prev) {
        if (checkUniq(val, this) == 0) {
            sibs = new Tree<T>(val, NULL, NULL, this); 
            return true; 
        }
        else {
            return false; 
        }
    }
    else {
        return false; 
    }
}

template <typename T>
bool Tree<T>::addSibling(Tree<T> *root){
    if (prev) {
        if (checkUniq(root->data, this) == 0) {
            sibs = root;
            root->prev = this; 
            return true; 
        }
        else {
            return false; 
        }
    }
    else {
        return false; 
    }
}

template <typename U>
std::ostream& operator<<(std::ostream& os, Tree<U>& node) {
    os << node.toString(); 
    return os; 
}

template <typename T>
bool Tree<T>::treeCompare(const Tree<T> *a, const Tree<T> *b) const {
    if (a->data == b->data) {
        if (a->sibs && b->sibs) {
            if (treeCompare(a->sibs, b->sibs)) {return true;} else {return false;}
        }
        if (a->kids && b->kids) {
            if (treeCompare(a->kids, b->kids)) {return true;} else {return false;}
        }
        return true; 
    }
    else {
        return false; 
    }
}