#include <iostream>
#include <cstdlib>
#include "linkedlist.h"


int main() {
    custom::List<int> list;

    std::cout << "1. Append\n"
                << "2. Insert\n"
                << "3. Delete\n"
                << "4. Display\n"
                << "5. Reverse\n"
                << "6. Exit\n\n";

    while (true) {
        int op, pos;
        int data;
        std::cout << "\nOption: ";
        std::cin >> op;

        switch (op) {
            case 1:
                std::cout << "Data: ";
                std::cin >> data;
                list.append(data);
                break;

            case 2:
                std::cout << "Data: ";
                std::cin >> data;
                std::cout << "Postion: ";
                std::cin >> pos;

                try {
                    list.insert(data, pos);
                } catch (std::out_of_range &e) {
                    std::cout << e.what() << '\n';
                }
                break;

            case 3:
                std::cout << "Postion: ";
                std::cin >> pos;

                try {
                    list.erase(pos);
                } catch (std::out_of_range &e) {
                    std::cout << e.what() << '\n';
                }

                break;

            case 4:
                list.display();
                break;

            case 5:
                list.reverse();
                list.display();
                break;

            case 6:
                list.~List();
                exit(EXIT_SUCCESS);
        }
    }
}
