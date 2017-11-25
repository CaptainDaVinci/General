#include "LinkedList.h"

void partiton(struct Node *head, struct Node **front, struct Node **back) {
    if (head == NULL || head->next == NULL) {
        *front = head;
        *back = NULL;
    }

    struct Node *slow, *fast;
    slow = fast = head;

    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    *front = head;
    *back = slow->next;
    slow->next = NULL;
}

struct Node* merge(struct Node *a, struct Node *b) {
    struct Node *mergedList = NULL;

    if (b == NULL) {
        return a;
    }

    if (a == NULL) {
        return b;
    }

    if (a->data <= b->data) {
        mergedList = a;
        mergedList->next = merge(a->next, b);
    } else {
        mergedList = b;
        mergedList->next = merge(a, b->next);
    }

    return mergedList;
}

void merge_sort(struct Node **source) {
    struct Node *head = *source;

    if (head == NULL || head->next == NULL) {
        return ;
    }

    struct Node *a, *b;
    a = b = NULL;
    partiton(head, &a, &b);

    merge_sort(&a);
    merge_sort(&b);

    *source = merge(a, b);
}

void sort() {
    merge_sort(&head);
}
