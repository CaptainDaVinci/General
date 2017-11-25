#include <stdlib.h>
#include "BST.h"

void dealloc(Node *parent) {
    if (parent == NULL) return ;

    dealloc(parent->left);
    dealloc(parent->right);
    free(parent);
    parent = NULL;
}
