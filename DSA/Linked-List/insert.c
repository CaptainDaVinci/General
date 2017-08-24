#include "LinkedList.h"

void insert(int data) {
    struct Node *new_node = malloc(sizeof *new_node);

    if (new_node == NULL) {
        printf("%s\n", MEM_FAIL_MSG);
        return ;
    }

    ++size;

    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        return ;
    }

    struct Node *curr = head;

    while (curr->next != NULL) {
        curr = curr->next;
    }

    curr->next = new_node;
}
