#include "LinkedList.h"

void insertAtN(int data, int position) {
    struct Node *new_node = malloc(sizeof *new_node);

    if (new_node == NULL) {
        printf("%s\n", MEM_FAIL_MSG);
        return ;
    }

    if (position > size_of_list() || position < 0) {
        printf("%s\n", INDEX_OUT_OF_RANGE);
        return ;
    }

    ++size;
    new_node->data = data;
    new_node->next = NULL;

    if (position == 0) {
        new_node->next = head;
        head = new_node;
        return ;
    }

    struct Node *curr = head, *temp = head;

    for (int i = 0; i < position; ++i) {
        temp = curr;
        curr = curr->next;
    }

    temp->next = new_node;
    new_node->next = curr;
}
