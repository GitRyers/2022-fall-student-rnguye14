#include "CTree.h"
#include <iostream>
#include <string> 

using std::cout;
using std::endl; 
using std::string; 

//Destructor
CTree::~CTree() {
    delete sibs;
    delete kids;  
}

CTree& CTree::operator+(CTree& rt) {
    addChild(&rt);
    return *this;  
}

bool CTree::operator==(const CTree &root) {
    return treeCompare(this, &root); 
}

int CTree::checkUniq(char ch, CTree * node) {
    int count = 0;  
    if (node->data != ch) { 
        if (node->sibs != NULL) { 
            count += checkUniq(ch, node->sibs); 
        } 
    }
    else {
        count++;  
    }
    return count; 
}

bool CTree::addChild(char ch) {
    if (kids) {
        if (checkUniq(ch, kids) == 0) {
            CTree *cur = kids;
            while (cur) {
                if (ch > cur->data) {
                    if (cur->sibs == NULL) {
                        cur->sibs = new CTree(ch, NULL, NULL, cur); 
                        break; 
                    }
                    else {
                        cur = cur->sibs; 
                    }
                }
                else {
                    CTree *node = new CTree(ch, NULL, cur, cur->prev); 
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
        kids = new CTree(ch, NULL, NULL, this); 
        return true; 
    }
}

bool CTree::addChild(CTree *root) {
    if (!root->prev||!root->sibs) {
        if (kids) {
            if (checkUniq(root->data, kids) == 0) {
                CTree *cur = kids;
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

string CTree::toString() {
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

bool CTree::addSibling(char ch) {
    if (prev) {
        if (checkUniq(ch, this) == 0) {
            sibs = new CTree(ch, NULL, NULL, this); 
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

bool CTree::addSibling(CTree *root){
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

std::ostream& operator<<(std::ostream& os, CTree& node) {
    os << node.toString(); 
    return os; 
}

bool CTree::treeCompare(const CTree *a, const CTree *b) const {
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