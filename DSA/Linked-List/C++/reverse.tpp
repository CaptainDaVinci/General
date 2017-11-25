#include "linkedlist.h"

template <typename T>

void custom::List<T>::reverse() {
    if (head == nullptr) {
        return ;
    }

    Node *curr, *prev, *next_node;
    prev = nullptr;
    curr = next_node = head;

    while (curr != nullptr) {
        next_node = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next_node;
    }

    head = prev;
}
