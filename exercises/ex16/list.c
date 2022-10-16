#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

// put char into a newly created node
Node * create_node(char ch) {
  Node * node = (Node *) malloc(sizeof(Node));
  assert(node); //confirm malloc didn't fail

  node->data = ch;
  node->next = NULL;
  return node;
}

// output the list iteratively
void print(const Node * cur) {
  while (cur != NULL) {
    printf("%c ", cur->data);
    cur = cur->next;  // advance to next node
  }
}

//find # of values in linked list
int length(const Node * cur) {
  int count = 0; 
  for (const Node * tmp = cur; tmp != NULL; tmp = tmp->next) {
    count++; //increase count for every node iterated over by for loop
  }
  return count; 
} 

//insert new node after given node
void add_after(Node * cur, char val) {
  assert(cur != NULL); 
  Node * node = create_node(val); //create new node with given val
  node->next = cur->next; //make new node point to next segment of linked list 
  cur->next = node; //make current node point to new node
}

//output list in reverse order recursively
void reverse_print(const Node * cur) {
  if (cur != NULL) {
    reverse_print(cur->next);
    printf("%c ", cur->data);
  }
}