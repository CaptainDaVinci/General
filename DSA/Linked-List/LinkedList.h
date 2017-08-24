#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

static const char *MEM_FAIL_MSG = "ERROR: Memory allocation failed";
static const char *INDEX_OUT_OF_RANGE = "ERROR: Index out of range";
static const char *EMPTY_LIST = "ERROR: List is empty";

struct Node {
    int data;
    struct Node *next;
};

int size;
struct Node *head;

void insert(int data);
void insertAtN(int data, int position);
void delete(int postion);
void reverse(void);
void traverse(void);
int size_of_list(void);
void dealloc(void);

#endif
