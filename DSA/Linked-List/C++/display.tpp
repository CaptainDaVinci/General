#include "linkedlist.h"

template <typename T>
void custom::List<T>::display() {
    Node *curr = head;

    if (head == nullptr) {
        std::cout << "List is empty" << '\n';
        return ;
    }

    while (curr != nullptr) {
        std::cout << curr->data << ' ';
        curr = curr->next;
    }

    std::cout << '\n';
}
