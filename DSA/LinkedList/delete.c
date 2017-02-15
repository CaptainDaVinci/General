#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

void delete(int pos)
{
    struct node *curr = head;
    struct node *prev;
    int i;

    if(head == NULL)
    {
        printf("ERROR-The list is empty\n");
        return;
    }

    if(pos == 1)
    {
        head = curr->link;
        free(curr);
        return;
    }

    for(i = 0; i < pos - 2; i++)      //iterates upto (n - 1)th node.
    {
        if(curr == NULL)         // when the position(n), if greater than the size of list.
        {
            printf("ERROR-Exceeding size of list\n");
            return;
        }
        curr = curr->link;
    }
    
    prev = curr;
    curr = prev-> link;
    prev->link = curr->link;

    free(curr);
}
