#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

struct Node {
    double data;
    struct Node *next;
};

static const char *EMPTY_STACK = "Stack is empty!";

struct Node *top;
size_t size;

void push(double data);
void dealloc(void);
double pop(void);
double stack_top(void);
int stack_size(void);

#endif
