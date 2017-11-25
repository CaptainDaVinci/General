#include <iostream>
#include "BST.h"

template <typename type>
void custom::BST<type>::inorderHelper(Node *parent) const {
    if (parent == nullptr) {
        return ;
    }

    inorderHelper(parent->left);
    std::cout << parent->val << ' ';
    inorderHelper(parent->right);
}

template <typename type>
void custom::BST<type>::inorder() const {
    inorderHelper(root);

    std::cout << '\n';
}
