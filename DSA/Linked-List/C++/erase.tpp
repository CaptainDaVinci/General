#include "linkedlist.h"

template <typename T>
void custom::List<T>::erase(int pos) {
    Node *curr, *prev;
    curr = prev = head;

    if (head == nullptr) {
        throw std::out_of_range("List is empty");
    }

    if (pos < 1) {
        throw std::out_of_range("Invalid Postion");
    }

    if (pos == 1) {
        prev = head;
        head = prev->next;
        delete prev;

        return ;
    }

    for (int i = 1; i < pos; ++i) {
        if (curr == nullptr) {
            throw std::out_of_range("Invalid Position");
        }

        prev = curr;
        curr = curr->next;
    }

    prev->next = curr->next;
    delete curr;
}
