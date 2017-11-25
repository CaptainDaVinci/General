#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define SIZE 5

int queue[SIZE], front = -1, rear = -1;

bool isFull(void) {
    return (rear + 1) % SIZE == front;
}

bool isEmpty(void) {
    return front == -1 && rear == -1;
}

void enqueue(int data) {
    if (isFull()) {
        printf("Queue is full!!\n");
        return ;
    }

    rear = (rear  + 1) % SIZE;
    queue[rear] = data;
    front = (front == -1) ? rear : front;
}

int dequeue(void) {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return -1;
    }

    int val = queue[front];
    if (rear == front) {
        rear = front = -1;
        return val;
    }

    front = (front  + 1) % SIZE;
    return val;
}

void display(void) {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return ;
    }

    int i = front;
    while (i != rear) {
        printf("%d ", queue[i]);
        i = (i + 1) % SIZE;
    }

    printf("%d\n", queue[rear]);
}

int main(void) {
    printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
    while (1) {
        int op, d;
        printf("\nOption: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("Data: ");
                scanf("%d", &d);
                enqueue(d);
                break;

            case 2:
                printf("Popped val: %d\n", dequeue());
                break;

            case 3:
                printf("Current Queue\n");
                display();
                break;

            case 4:
                exit(EXIT_SUCCESS);
        }
    }
}
