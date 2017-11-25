#ifndef BST_H
#define BST_H

#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node *left, *right;
};
typedef struct Node Node;

static Node* createNode(int data) {
    Node *newNode = malloc(sizeof *newNode);
    if (newNode == NULL) {
        exit(EXIT_FAILURE);
    }

    newNode->right = newNode->left = NULL;
    newNode->data = data;

    return newNode;
}

Node *root;
bool insert(Node *root, const int data);
bool find(const Node *root, const int data);
Node* erase(Node *root, const int data);
void inorder(const Node *root);
void preorder(const Node *root);
void postorder(const Node *root);
void dealloc(Node *root);

#endif
