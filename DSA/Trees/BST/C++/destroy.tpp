#include "BST.h"

template <typename type>
void custom::BST<type>::destroy(Node *parent) {
    if (parent == nullptr) {
        return ;
    }

    destroy(parent->left);
    destroy(parent->right);

    delete parent;
}
