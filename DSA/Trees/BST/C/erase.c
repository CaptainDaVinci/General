#include <stdio.h>
#include "BST.h"

static Node* findMin(Node* parent) {
    Node *successor = parent;

    while (successor->left != NULL) {
        successor = successor->left;
    }

    return successor;
}

Node* erase(Node *parent, const int data) {
    if (parent == NULL) return NULL;

    if (data < parent->data) {
        parent->left = erase(parent->left, data);
    } else if (data > parent->data) {
        parent->right = erase(parent->right, data);
    } else {
        if (parent->left == NULL && parent->right == NULL) {
            free(parent);
            parent = NULL;
        } else if (parent->left == NULL) {
            Node *temp = parent;
            parent = parent->right;
            free(temp);
        } else if (parent->right == NULL) {
            Node *temp = parent;
            parent = parent->left;
            free(temp);
        } else {
            Node *temp = findMin(parent->right);
            parent->data = temp->data;
            parent->right = erase(parent->right, temp->data);
        }
    }

    return parent;
}
