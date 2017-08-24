#include "LinkedList.h"

void reverse(void) {
    if (head == NULL) {
        printf("%s\n", EMPTY_LIST);
        return ;
    }

    struct Node *curr_node, *next_node, *prev_node;
    curr_node = next_node = head;
    prev_node = NULL;

    while (curr_node != NULL) {
        next_node = curr_node->next;
        curr_node->next = prev_node;
        prev_node = curr_node;
        curr_node = next_node;
    }

    head = prev_node;
}

/* RECURSIVE APPROACH */
// void reverse(struct Node *node) {
//     if (node == NULL) {
//         printf("%s\n", EMPTY_LIST);
//         return ;
//     }
//
//     if (node->next == NULL) {
//         head = node;
//         return ;
//     }
//
//     reverse(node->next);
//
//     struct Node *temp = node->next;
//     temp->next = node;
//     node->next = NULL;
// }
