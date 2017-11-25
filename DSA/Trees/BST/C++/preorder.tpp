#include <iostream>
#include "BST.h"

template <typename type>
void custom::BST<type>::preorderHelper(Node *parent) const {
    if (parent == nullptr) {
        return ;
    }

    preorderHelper(parent->left);
    std::cout << parent->val << ' ';
    preorderHelper(parent->right);
}

template <typename type>
void custom::BST<type>::preorder() const {
    preorderHelper(root);

    std::cout << '\n';
}
