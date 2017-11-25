#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 10

int stack[STACK_SIZE], top = -1;

void push(int data);
int pop(void);
void display(void);

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
                exit(EXIT_SUCCESS);
        }
    }
}

void push(int data) {
    if (top == STACK_SIZE - 1) {
        printf("Stack overflow avoided : )\n");
        return ;
    }

    stack[++top] = data;
}

int pop(void) {
    if (top == -1) {
        printf("Stack is empty!\n");
        return -1;
    }

    return stack[top--];
}

void display(void) {
    for (int i = 0; i <= top; ++i) {
        printf("%d ", stack[i]);
    }

    printf("\n");
}
