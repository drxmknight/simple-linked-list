#ifndef LIST_H
#define LIST_H

typedef struct _node {
    int value;
    struct _node *next;
}Node;

typedef struct _list {
    Node *first;
}List;

// Initialize the list.
void init(List *list);

// Insert element first into the list.
void push_first(List *list, int value);

void push_last(List *list, int value);

// return the last element that entered into the list.
int pop_last(List *list);

// return the element that entered first.
int pop_first(List *list);

// Print all values of the list.
void print_list(List list);

void free_list(List *list);

#endif
