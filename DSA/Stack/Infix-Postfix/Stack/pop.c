#include "stack.h"

double pop(void) {
    if (top == NULL) {
        return '\0';
    }

    struct Node *node = top;
    double data = top->data;

    node = top->next;
    free(top);
    top = node;

    --size;

    return data;
}
