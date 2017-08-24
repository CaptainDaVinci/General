#include "LinkedList.h"

void delete(int position) {
    if (head == NULL) {
        printf("%s\n", EMPTY_LIST);
        return ;
    }

    if (position >= size_of_list() || position < 0) {
        printf("%s\n", INDEX_OUT_OF_RANGE);
        return ;
    }

    struct Node *curr = head, *temp = head;
    --size;
    
    if (position == 0) {
        head = curr->next;
        free(curr);
        curr = temp = NULL;
        return ;
    }

    for (int i = 0; i < position; ++i) {
        temp = curr;
        curr = curr->next;
    }

    temp->next = curr->next;

    free(curr);
    curr = NULL;
}
