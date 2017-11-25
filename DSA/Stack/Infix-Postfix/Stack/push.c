#include "stack.h"

void push(double data) {
    struct Node *new_node = malloc(sizeof *new_node);

    if (new_node == NULL) {
        printf("%s\n", EMPTY_STACK);
        return ;
    }

    new_node->data = data;
    new_node->next = top;
    top = new_node;

    ++size;
}
