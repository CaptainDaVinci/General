#ifndef LINKED_LIST_H
#define LINKED_LIST_H

namespace custom {
    template <typename T>
    class List {
        struct Node {
            T data;
            Node *next;

            Node(T d) {
                data = d;
                next = nullptr;
            }
        };

        Node *head;
    public:
        List() {
            head = nullptr;
        }

        ~List() {
            Node *prev, *curr;
            prev = curr = head;

            while (curr != nullptr) {
                prev = curr;
                curr = curr->next;
                delete prev;
            }
        }

        void append(T d);
        void insert(T d, int pos);
        void erase(int pos);
        void display();
        void reverse();
    };
}

#include "append.tpp"
#include "insert.tpp"
#include "erase.tpp"
#include "display.tpp"
#include "reverse.tpp"

#endif
