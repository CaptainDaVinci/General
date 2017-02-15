#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

void traverse(void)
{
    struct node *curr = head;
    if(head == NULL) // to check if list is empty.
    {
        printf("The List is empty\n");
        return;
    }
    while(curr != NULL) // traverse till the end of the list
    {
        printf("%d ", curr->data);
        curr = curr->link;
    }
    printf("\n");
}

// Following is a recursive approach to traverse and
// is not used in the LinkedList.c file, on interchanging
// line 7 and 8, we can print the list in reverse, but
// not necessarily reverse the list.
//
// void recursion(struct node *curr)
// {
//     if (curr == NULL) return;
//     printf("%d ", curr->data);
//     recursion(curr->link);
// }

void reverse(void)
{
    struct node *curr;
    struct node *prev;
    struct node *next;

    prev = NULL;
    curr = head;
    next = curr->link;
    head = prev;

    while(curr != NULL)
    {
        curr->link = prev;
        prev = curr;
        curr = next;
        if(next != NULL) next = next->link;
    }
    head = prev;
}
