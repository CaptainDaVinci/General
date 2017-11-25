#include "BST.h"

template <typename type>
bool custom::BST<type>::findHelper(Node *parent, type val) const {
    if (parent == nullptr) {
        return false;
    }

    if (parent->val == val) {
        return true;
    }

    if (val < parent->val) {
        return findHelper(parent->left, val);
    }

    return findHelper(parent->right, val);
}

template <typename type>
bool custom::BST<type>::find(type val) const {
    return findHelper(root, val);
}
