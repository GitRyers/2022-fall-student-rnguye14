#include "Tree.h"
#include <iostream>
#include <string> 

using std::cout;
using std::endl; 
using std::string; 

//Destructor
template <typename T>
CTree<T>::~CTree() {
    delete sibs;
    delete kids;  
}

template <typename T>
CTree<T>& CTree<T>::operator+(CTree<T>& rt) {
    addChild(&rt);
    return *this;  
}

template <typename T>
bool CTree<T>::operator==(const CTree<T> &root) {
    return treeCompare(this, &root); 
}

template <typename T>
int CTree<T>::checkUniq(T val, CTree<T> * node) {
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
bool CTree<T>::addChild(T val) {
    if (kids) {
        if (checkUniq(val, kids) == 0) {
            CTree<T> *cur = kids;
            while (cur) {
                if (val > cur->data) {
                    if (cur->sibs == NULL) {
                        cur->sibs = new CTree(val, NULL, NULL, cur); 
                        break; 
                    }
                    else {
                        cur = cur->sibs; 
                    }
                }
                else {
                    CTree<T> *node = new CTree(val, NULL, cur, cur->prev); 
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
        kids = new CTree(val, NULL, NULL, this); 
        return true; 
    }
}

template <typename T>
bool CTree<T>::addChild(CTree<T> *root) {
    if (!root->prev||!root->sibs) {
        if (kids) {
            if (checkUniq(root->data, kids) == 0) {
                CTree<T> *cur = kids;
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

string CTree<T>::toString() {
    string str;
    str.push_back(data); 
    str.push_back('\n'); 
    if (kids) {
        str = str + kids->toString(); 
    } 
    if (sibs) {
        str = str + sibs->toString(); 
    }
    return str; 
}

template <typename T>
bool CTree<T>::addSibling(T val) {
    if (prev) {
        if (checkUniq(val, this) == 0) {
            sibs = new CTree(val, NULL, NULL, this); 
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
bool CTree<T>::addSibling(CTree<T> *root){
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
std::ostream& operator<<(std::ostream& os, CTree<U>& node) {
    os << node.toString(); 
    return os; 
}

template <typename T>
bool CTree<T>::treeCompare(const CTree<T> *a, const CTree<T> *b) const {
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