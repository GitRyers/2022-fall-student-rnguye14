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

//bool CTree::addChild(CTree *root);

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

/*
bool CTree::addSibling(char ch);
bool CTree::addSibling(CTree *root);
bool CTree::treeCompare(const CTree *a, const CTree *b) const;
*/
