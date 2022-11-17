#include "CTree.h"
#include <iostream>

//Destructor
CTree::~CTree() {
    destroy(prev);
}

void CTree::destroy(CTree * node) {
    if (node) {
        destroy(node->sibs);
        destroy(node->kids);
        delete node;
    }
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

bool CTree::checkUniq(char ch, CTree * node) {
    if (data != ch) {
        if (node->sibs != NULL) {
            char temp = ch; 
            checkUniq(temp, node->sibs); 
        }
        return true; 
    }
    else {
        return false; 
    }
}

bool CTree::addChild(char ch) {
    if (checkUniq(ch, kids)) {
        CTree *cur = kids;
        while (cur) {
            if (cur->data < ch) {
                cur = cur->sibs; 
            }
            else {
                CTree(ch, NULL, cur->sibs, cur); 
                break; 
            }
        }
        return true; 
    }
    else {
        return false; 
    }
}

//bool CTree::addChild(CTree *root);

/*
std::string CTree::toString();

bool CTree::addSibling(char ch);
bool CTree::addSibling(CTree *root);
bool CTree::treeCompare(const CTree *a, const CTree *b) const;
*/
