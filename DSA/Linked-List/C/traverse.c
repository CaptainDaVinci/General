#include "LinkedList.h"

void traverse(void) {
    struct Node *curr = head;

    if (curr == NULL) {
        printf("%s\n", EMPTY_LIST);
        return ;
    }

    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
}
