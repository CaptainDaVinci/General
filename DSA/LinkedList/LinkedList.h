#ifndef __LIST_H__
#define __LIST_H__

struct node
{
    int data;
    struct node *link;
};
struct node *head; // Global variable

void delete(int n);
void insert(int x);
void insert2(int x, int n);
void recursion(struct node *curr);
void reverse();
void traverse(void);

#endif
