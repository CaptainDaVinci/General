#include "BST.h"

bool insert(Node* parent, const int data) {
    if (parent->data == data) {
        return false;
    }

    if (data < parent->data) {
        if (parent->left == NULL) {
            parent->left = createNode(data);
            return true;
        }

        return insert(parent->left, data);
    }

    if (parent->right == NULL) {
        parent->right = createNode(data);
        return true;
    }

    return insert(parent->right, data);
}
