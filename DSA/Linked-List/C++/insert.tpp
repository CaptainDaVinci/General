#include "linkedlist.h"

template <typename T>
void custom::List<T>::insert(T data, int pos) {
    Node *new_node = new Node(data);
    Node *prev, *curr;

    prev = curr = head;

    if (pos < 1) {
        throw std::out_of_range("Invalid Positon");
    }

    if (pos == 1) {
        new_node->next = head;
        head = new_node;
        return ;
    }

    for (int i = 1; i < pos; ++i) {
        if (curr == nullptr) {
            throw std::out_of_range("Invalid Positon");
        }

        prev = curr;
        curr = curr->next;
    }

    prev->next = new_node;
    new_node->next = curr;
}
