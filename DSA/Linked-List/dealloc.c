#include "LinkedList.h"

void dealloc(void) {
    if (head == NULL) {
        return ;
    }

    struct Node *curr = head, *temp = head;

    while (curr != NULL) {
        curr = curr->next;
        free(temp);
        temp = curr;
    }
}
