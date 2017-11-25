#include <iostream>
#include "BST.h"

template <typename type>
void custom::BST<type>::postorderHelper(Node *parent) const {
    if (parent == nullptr) {
        return ;
    }

    postorderHelper(parent->left);
    std::cout << parent->val << ' ';
    postorderHelper(parent->right);
}

template <typename type>
void custom::BST<type>::postorder() const {
    postorderHelper(root);

    std::cout << '\n';
}
