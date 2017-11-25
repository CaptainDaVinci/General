#include "stack.h"

double stack_top(void) {
    return (top == NULL) ? '\0' : top->data;
}
