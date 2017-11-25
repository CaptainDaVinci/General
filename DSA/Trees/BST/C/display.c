#include <stdio.h>
#include "BST.h"

void inorder(const Node *parent) {
    if (parent == NULL) return ;

    inorder(parent->left);
    printf("%d ", parent->data);
    inorder(parent->right);
}

void postorder(const Node *parent) {
    if (parent == NULL) return ;

    postorder(parent->left);
    postorder(parent->right);
    printf("%d ", parent->data);
}

void preorder(const Node *parent) {
    if (parent == NULL) return ;

    printf("%d ", parent->data);
    preorder(parent->left);
    preorder(parent->right);
}
