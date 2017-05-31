#include <iostream>
#include "linkedList.h"

int main()
{
	List list;
	std::cout << "----Linked List----\n";
	int option;

	int n;
	std::cout << "Initial size: ";
	std::cin >> n;
	std::cout << "Elements: ";
	for (int i = 0; i < n; ++i)
	{
		int x;
		std::cin >> x;
		list.push(x);
	}

	while (true)
	{
		std::cout << "\n\n1. Push a Node\n"
				  << "2. Insert Node\n"
				  << "3. Delete Node\n"
				  << "4. Revese List\n"
				  << "5. Display List\n"
				  << "6. Exit\n\n";

		std::cin >> option;

		switch (option)
		{
		case 1:
		{
			int x;
			std::cout << "Data: ";
			std::cin >> x;
			list.push(x);
			break;
		}
		case 2:
		{
			int data, pos;
			std::cout << "Data: ";
			std::cin >> data;
			std::cout << "Position (0 indexed): ";
			std::cin >> pos;
			list.insert(data, pos);
			break;
		}
		case 3:
		{
			int pos;
			std::cout << "Position (0 indexed): ";
			std::cin >> pos;
			list.deleteNode(pos);
			break;
		}
		case 4:
			list.reverse();
			std::cout << "Reversed!\n";
			break;

		case 5:
			list.show();
			break;

		case 6:
			std::cout << "Deallocating\n";
			return 0;

		default:
			std::cout << "Not an option!\n";
			break;
		}
	}
}
