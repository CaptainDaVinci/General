#include <stdio.h>
#include <stdlib.h>

void push(int data);
int pop(void);
void display(void);
void dealloc(void);

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;

int main(void) {
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Display\n");
    printf("4. Exit\n");

    int option, data;
    while (1) {
        printf("\nOption: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Data: ");
                scanf("%d", &data);
                push(data);
                break;

            case 2:
                printf("Popped value: %d\n", pop());
                break;

            case 3:
                display();
                break;

            case 4:
                dealloc();
                exit(EXIT_SUCCESS);
        }
    }
}

void push(int data) {
    struct Node *new_node = malloc(sizeof *new_node);

    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        return ;
    }

    new_node->data = data;
    new_node->next = top;

    top = new_node;
}

int pop(void) {
    if (top == NULL) {
        printf("Stack is empty!\n");
        return -1;
    }

    struct Node *temp = top;
    int data = top->data;

    temp = top->next;
    free(top);
    top = temp;

    return data;
}

void display(void) {
    struct Node *curr_node = top;

    while (curr_node != NULL) {
        printf("%d ", curr_node->data);
        curr_node = curr_node->next;
    }

    printf("\n");
}

void dealloc(void) {
    struct Node *temp = top;

    while (top != NULL) {
        temp = top->next;
        free(top);
        top = temp;
    }
}
