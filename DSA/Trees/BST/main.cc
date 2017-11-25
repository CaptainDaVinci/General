#include <iostream>
#include "BST.h"

int main() {
    custom::BST<int> bst;

    std::cout << "1. Insert\n"
              << "2. Delete\n"
              << "3. Search\n"
              << "4. Postorder\n"
              << "5. Inorder\n"
              << "6. Preorder\n"
              << "7. Exit\n";

    while (1) {
        int op, data;
        std::cout << "\nOption: ";
        std::cin >> op;

        switch (op) {
            case 1:
                std::cout << "Data: ";
                std::cin >> data;

                bst.insert(data);
                break;

            case 2:
                std::cout << "Data: ";
                std::cin >> data;

                bst.erase(data);
                break;

            case 3:
                std::cout << "Data: ";
                std::cin >> data;

                if (bst.find(data)) {
                    std::cout << "Found!\n";
                } else {
                    std::cout << "Not found\n";
                }

                break;

            case 4:
                std::cout << "Postorder: ";
                bst.postorder();
                break;

            case 5:
                std::cout << "Inorder: ";
                bst.inorder();
                break;

            case 6:
                std::cout << "Preorder: ";
                bst.preorder();
                break;

            case 7:
                bst.~BST();
                exit(EXIT_SUCCESS);
                break;

            default:
                std::cout << "Try again\n";
                break;
        }
    }
}
