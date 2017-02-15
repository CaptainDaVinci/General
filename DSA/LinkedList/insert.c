#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

void insert(int x)
{
    struct node *curr = malloc(sizeof(struct node));

    if(head == NULL)    // for empty list condition
    {
        head = curr;
        curr->data = x;
        curr->link = NULL;
        return;
    }
    struct node *prev = head;
    while(prev->link != NULL) // traverse throughout the list
    {
        prev = prev->link;
    }
    curr->data = x;
    prev->link = curr;
    curr->link = NULL;
}

void insert2(int x, int n)
{
    if(head == NULL) // to check if list is empty
    {
        printf("The list is empty\n");
        return;
    }
    struct node *curr = malloc(sizeof(struct node));
    struct node *prev = head;
    int i;
    if(n == 1) // when node is to be inserted as the first node
    {
        prev = head;
        curr->data = x;
        curr->link = prev;
        head = curr;
        return;
    }
    for(i = 0; i < n - 2; i++)      // iterates upto (n - 1)th node.
    {
        if(prev == NULL)     // when the position(n), if greater than the size of list.
        {
            printf("ERROR-Exceeded size of list\n");
            return;
        }
        prev = prev->link;
    }
    curr->data = x;
    curr->link = prev->link;
    prev->link = curr;
}
