#include "CTree.h"
#include <iostream>

//Destructor
CTree::~CTree() {
    delete sibs;
    delete kids;  
}

/*
CTree& CTree::operator+(CTree& rt) {
    if (addChild(rt)) {
        return this; 
    } 
    else {
        return NULL; 
    }
}

bool CTree::operator==(const CTree &root); 
*/

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
    if (kids != NULL) {
        if (checkUniq(ch, kids) == 0) {
            std::cout << "reached target" << std::endl; 
            CTree *cur = kids;
            while (cur) {
                if (cur->data < ch) {
                    cur = cur->sibs; 
                }
                else {
                    CTree *node = new CTree(ch, NULL, cur, cur->prev);
                    cur->prev->sibs = node; 
                    cur->prev = node; 
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

//bool CTree::addChild(CTree *root);

/*
std::string CTree::toString();

bool CTree::addSibling(char ch);
bool CTree::addSibling(CTree *root);
bool CTree::treeCompare(const CTree *a, const CTree *b) const;
*/
