#include <iostream>
#include "stack.h"

int main()
{
	std::cout << "---STACK----\n";

	int n;
	std::cout << "Initial stack size: ";
	std::cin >> n;

	Stack stack;
	std::cout << "Data: ";

	for (int i = 0; i < n; ++i)
	{
		int x;
		std::cin >> x;
		stack.push(x);
	}

	std::cout << "\n\n1. Pop\n"
			  << "2. Push\n"
			  << "3. Top\n"
			  << "4. Exit\n\n";

	while (true)
	{
		int option;
		std::cin >> option;

		switch (option)
		{
		case 1:
			std::cout << stack.pop() << " popped\n"
					  << "---------------\n";
			break;

		case 2:
		{
			int data;
			std::cout << "Data: ";
			std::cin >> data;
			stack.push(data);
			std::cout << "---------------\n";
			break;
		}

		case 3:
			std::cout << "Top: " << stack.top() << '\n'
					  << "---------------\n";
			break;

		case 4:
			std::cout << "Deallocation!\n";
			return 0;

		default:
			std::cout << "Not an option!\n";
		}
	}
}