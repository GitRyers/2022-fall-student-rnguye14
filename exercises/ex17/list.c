#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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
void print_list(const Node * cur) {
  while (cur != NULL) {
    printf("%c ", cur->data);
    cur = cur->next;  // advance to next node
  }
}

// output the list recursively
void print_rec(const Node * head) {
  if (head != NULL) {
    printf("%c ", head->data);
    print_rec(head->next);
  }
}

// output the list in reverse (recursive)
void reverse_print(const Node * head) {
  if (head != NULL) {  // equivalent: if (head)
    reverse_print(head->next);
    printf("%c ", head->data);
  }
}

// count and return the number of elements in the List (recursive)
long length(const Node * head) {
  if (head == NULL)
    return 0;
  return 1 + length(head->next);
}

// get rid of (deallocate) entire list, recursively from end to start
void clear_list(Node ** list_ptr) {
  if (*list_ptr != NULL) {
    clear_list( &((*list_ptr)->next));
    free(*list_ptr);
    *list_ptr = NULL;
  }
}

// add char immediately after existing node
void add_after(Node * node, char val) {
  if (node == NULL)
    return;
  Node * n = create_node(val);
  n->next = node->next;
  node->next = n;
}

// add char to beginning of list
void add_front(Node ** list_ptr, char val) {
  Node * n = create_node(val);
  n->next = *list_ptr;
  *list_ptr = n;
}

// EXERCISE
// remove node after current, return removed char, or '?' if no node
char remove_after(Node * node) {
  if (node == NULL) {
    return '?'; 
  }
  else {
    Node * after = node->next; 
    char val = after->data; 
    node->next = after->next; 
    free(after); 
    return val; 
  }
}

// EXERCISE
// remove first node, if any, return removed char or '?' if no node
char remove_front(Node ** list_ptr) {
  Node *tmp = *list_ptr; 
  if (tmp == NULL) {  
    return '?';
  }  
  else {
    *list_ptr = (*list_ptr)->next; 
    char val = tmp->data; 
    free(tmp); 
    return val; 
  }
}

// EXERCISE
// remove all occurrences of a particular character
void remove_all(Node ** list_ptr, char val) {
  if (*list_ptr != NULL) {
    if ((*list_ptr)->data == val) {
      remove_front(list_ptr); 
      remove_all(list_ptr, val);
    }
    else {
      Node **next = &((*list_ptr)->next); 
      remove_all(next, val); 
    }
  }
}

// EXERCISE
// insert in order (assumes list is ordered)!!
// return the address of the node containing the character inserted
Node * insert(Node ** list_ptr, char val) {
  if (*list_ptr != NULL) {
    if ((*list_ptr)->data > val) {
      add_front(list_ptr, val); 
      return *list_ptr; 
    }
    insert(&((*list_ptr)->next), val); 
  }  
  else {
    add_front(list_ptr, val);
    return *list_ptr; 
  } 
}



// ---------- Other functions you may want to implement ----------

// insert char at end of list
void add_tail(Node ** list_ptr, char val) {
  if (*list_ptr != NULL) {
    while ((*list_ptr)->next != NULL) {
      *list_ptr = (*list_ptr)->next; 
    }
    add_after(*list_ptr, val); 
  }
}


// insert char at end of list (recursive)
void add_tail_rec(Node ** list_ptr, char val) {
  if (*list_ptr != NULL) {
    add_tail_rec(&(*list_ptr)->next, val);
  }
  else {
    add_front(list_ptr, val); 
  }
}

// find specfied val in the list, return pointer to first node in list
// that contains it, or NULL if val is not present
Node* find(Node * node, char value) {
  assert(node != NULL); 
  while ((node->data != value) && (node->next != NULL)) {
    node = node->next; 
  } 
  if (node->data == value) {
    return node; 
  }
  else {
    return NULL; 
  } 
}

// remove 1st occurrence of char from list if there, return 1 success, 0 failure
int remove_char(Node ** list_ptr, char val) {
  Node *node = find(*list_ptr, val);
  if (node == NULL) {
    return 0; 
  } 
  else {
    remove_front(&node); 
    return 1; 
  }
}

// recursive version of removing first occurrence
int remove_char_rec(Node ** list_ptr, char val)  {

  // not yet implemented
  return 0;  // replace this stub

}

// replace first occurrence of old with new, return 1 success, 0 failure
int replace(Node * head, char old, char new) {
  Node *node = find(head, old);
  if (node != NULL) {
    node->data = new;
    return 1; 
  }
  else {
    return 0; 
  }
}

