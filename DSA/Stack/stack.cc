#include <iostream>
#include "stack.h"

Stack::Stack()
{
	head = nullptr;
	stack_ptr = nullptr;
}

Stack::~Stack()
{
	Node *curr, *prev;
	curr = prev = head;

	while(curr != nullptr)
	{
		prev = curr;
		curr = curr->next;
		delete prev;
	}

	head = stack_ptr = nullptr;
}

void Stack::push(int x)
{
	Node *new_node = new Node;
	new_node->data = x, new_node->next = nullptr;

	if(head == nullptr)
	{
		head = stack_ptr = new_node;
		return;
	}

	Node *curr = head;
	while(curr->next != nullptr)
		curr = curr->next;
	
	curr->next = stack_ptr = new_node;
}

int Stack::pop()
{
	if(head == nullptr)
	{
		std::cout << "Stack is empty!\n";
		return -1;
	}

	int x = stack_ptr->data;
	Node *curr = head;

	if(stack_ptr == head)
	{
		delete stack_ptr;
		stack_ptr = head = nullptr;
		return x;
	}

	while(curr->next != stack_ptr)
		curr = curr->next;
	
	curr->next = nullptr;
	delete stack_ptr;
	stack_ptr = curr;

	return x;
}

int Stack::top()
{
	if(head == nullptr)
	{
		std::cout << "Stack is empty!\n";
		return -1;
	}

	return stack_ptr->data;
}