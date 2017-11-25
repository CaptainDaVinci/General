#include "LinkedList.h"

struct Node *head = NULL;
int size = 0;

int main(void) {
    int n;

    printf("Initial size: ");
    scanf("%d", &n);
    printf("Data: ");

    for (int i = 0; i < n; ++i) {
        int data;
        scanf("%d", &data);
        insert(data);
    }

    printf("\n1. Insert at Nth posion\n");
    printf("2. Delete\n");
    printf("3. Reverser\n");
    printf("4. Traverse\n");
    printf("5. Size\n");
    printf("6. Sort\n");
    printf("7. Exit\n");

    while (1) {
        printf("\nOption: ");

        int option, data, position;
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("\nData: ");
                scanf("%d", &data);
                printf("position: ");
                scanf("%d", &position);
                insertAtN(data, position);
                break;

            case 2:
                printf("\nPosition: ");
                scanf("%d", &position);
                delete(position);
                break;

            case 3:
                reverse();
                break;

            case 4:
                traverse();
                break;

            case 5:
                printf("%d", size_of_list());
                break;

            case 6:
                sort();
                traverse();
                break;
                
            case 7:
                dealloc();
                printf("\nAll blocks deallocated\n");
                exit(EXIT_SUCCESS);

            default:
                printf("\nInvalid choice!\n");
                break;
        }
    }
}
