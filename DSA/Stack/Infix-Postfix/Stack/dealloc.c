#include "stack.h"

void dealloc(void) {
    struct Node *temp = top;

    while (top != NULL) {
        temp = top->next;
        free(top);
        top = temp;
    }
}
