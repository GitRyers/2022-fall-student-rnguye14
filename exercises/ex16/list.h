#ifndef LIST_H
#define LIST_H


typedef struct node_ {
  char data;
  struct node_ * next;
} Node; // Node is a linked list node that holds char data



Node * create_node(char); // put char into a newly created node
void print(const Node *); // output the list iteratively

// add more function declarations here . . .
int length(const Node *); // find # of values in linked list
void add_after(Node *, char); // insert new node after given node
void reverse_print(const Node *); //output list in reverse order recursively
#endif

