#include "BST.h"

template <typename type>
void custom::BST<type>::insertHelper(Node *parent, type val) {
    if (val < parent->val) {
        if (parent->left == nullptr) {
            parent->left = new Node(val);
        } else {
            insertHelper(parent->left, val);
        }
    } else {
        if (parent->right == nullptr) {
            parent->right = new Node(val);
        } else {
            insertHelper(parent->right, val);
        }

    }
}

template <typename type>
void custom::BST<type>::insert(type val) {
    if (root == nullptr) {
        root = new Node(val);
    } else {
        insertHelper(root, val);
    }
}
