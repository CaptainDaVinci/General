#ifndef BST_H
#define BST_H

namespace custom {
    template <typename type>
    class BST {
    public:
        struct Node {
            type val;
            Node *right, *left;

            Node (type _val) {
                val = _val;
                right = left = nullptr;
            }
        };

        BST() {
            root = nullptr;
        }

        ~BST() {
            destroy(root);
        }

        void insert(type val);
        bool find(type val) const;
        void erase(type val);
        void postorder() const;
        void inorder() const;
        void preorder() const;

    private:
        Node *root;

        void insertHelper(Node *parent, type);
        Node* eraseHelper(Node *parent, type);
        Node* find_successor(Node *ptr) const;
        bool findHelper(Node *parent, type) const;
        void postorderHelper(Node *parent) const;
        void preorderHelper(Node *parent) const;
        void inorderHelper(Node *parent) const;
        void destroy(Node *parent);
    };
}

#include "insert.tpp"
#include "erase.tpp"
#include "find.tpp"
#include "inorder.tpp"
#include "preorder.tpp"
#include "postorder.tpp"
#include "destroy.tpp"

#endif
