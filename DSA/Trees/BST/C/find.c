#include "BST.h"

bool find(const Node *parent, const int data) {
    if (parent == NULL) return false;
    if (parent->data == data) return true;

    if (data < parent->data) {
        return find(parent->left, data);
    }

    return find(parent->right, data);
}
