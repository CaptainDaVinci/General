#include <stdio.h>
#include "BST.h"

int main(void) {
    root = NULL;
    printf("Binary Search Tree\n");
    printf("1. Insert\n2. Erase\n3. Find\n4. Preorder\n5. Inorder\n6. Postorder\n7. Exit\n");

    while (1) {
        int op, data;
        printf("\nOption: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("Data: ");
                scanf("%d", &data);

                if (root == NULL) {
                    root = createNode(data);
                    printf("Successfull insertion!\n");
                } else {
                    if (insert(root, data)) {
                        printf("Successfull insertion!\n");
                    } else {
                        printf("Unsuccessfull\n");
                    }
                }

                break;

            case 2:
                printf("Data: ");
                scanf("%d", &data);

                root = erase(root, data);
                break;

            case 3:
                printf("Data: ");
                scanf("%d", &data);

                if (find(root, data)) {
                    printf("Found!\n");
                } else {
                    printf("Not found\n");
                }

                break;

            case 4:
                preorder(root);
                printf("\n");
                break;

            case 5:
                inorder(root);
                printf("\n");
                break;

            case 6:
                postorder(root);
                printf("\n");
                break;

            case 7:
                dealloc(root);
                exit(EXIT_SUCCESS);
        }
    }
}
