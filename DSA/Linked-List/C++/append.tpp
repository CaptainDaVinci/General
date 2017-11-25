#include "linkedlist.h"

template <typename T>
void custom::List<T>::append(T data) {
    Node *new_node = new Node(data);
    Node *curr = head;

    if (curr == nullptr) {
        head = new_node;
        return ;
    }

    while (curr->next != nullptr) {
        curr = curr->next;
    }

    curr->next = new_node;
}
