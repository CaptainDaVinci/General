#include "BST.h"

template <typename type>
typename custom::BST<type>::Node* custom::BST<type>::find_successor(Node *parent) {
    Node *successor = parent;

    while (successor->left != nullptr) {
        successor = successor->left;
    }

    return successor;
}

template <typename type>
typename custom::BST<type>::Node* custom::BST<type>::eraseHelper(Node *parent, type val) {
    if (parent == nullptr) return parent;

    if (val < parent->val) {
        parent->left = eraseHelper(parent->left, val);
    } else if (val > parent->val) {
        parent->right = eraseHelper(parent->right, val);
    } else {
        // No child.
        if (parent->left == nullptr && parent->right == nullptr) {
            delete parent;
            parent = nullptr;
        }

        // Left child absent.
        else if (parent->left == nullptr) {
            Node *temp = parent;
            parent = parent->right;
            delete temp;
        }

        // Right child absent.
        else if (parent->right == nullptr) {
            Node *temp = parent;
            parent = parent->right;
            delete temp;
        }

        // Both child present.
        else {
            Node *temp = find_successor(parent->right);
            parent->val = temp->val;
            parent->right = eraseHelper(parent->right, temp->val);
        }
    }

    return parent;
}

template <typename type>
void custom::BST<type>::erase(type val) {
    root = eraseHelper(root, val);
}
