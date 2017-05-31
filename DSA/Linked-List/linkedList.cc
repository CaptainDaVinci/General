#include <iostream>
#include <cstdlib>
#include "linkedList.h"

List::List()
{
	head = nullptr;
}

List::~List()
{
	Node *curr = head, *prev = head;

	std::cout << size() << '\n';
	while(curr != nullptr)
	{
		prev = curr;
		curr = curr->next;
		prev->next = nullptr;
		delete prev;
	}
	
	head = nullptr;
	std::cout << size() << '\n';

}

void List::push(int data)
{
	Node *new_node;
	new_node = new Node;

	new_node->data = data;
	new_node->next = nullptr;

	if(head == nullptr)
	{
		head = new_node;
		return ;
	}
	
	Node *curr = head;

	while(curr->next != nullptr)
		curr = curr->next;

	curr->next = new_node;
}

int List::size()
{
	Node *curr = head;
	int size = 0;

	while(curr != nullptr)
	{
		curr = curr->next;
		++size;
	}
	
	return size;
}

void List::insert(int data, int pos)
{
	if(pos >= size())
	{
		std::cout << "Position out of bounds!\n";
		return;
	}

	Node *new_node, *curr, *prev;
	new_node = new Node;
	curr = prev = head;

	new_node->data = data;

	for(int i = 0; i < pos; ++i)
	{
		prev = curr;
		curr = curr->next;
	}

	prev->next = new_node;
	new_node->next = curr;
}

void List::deleteNode(int pos)
{
	if(pos >= size())
	{
		std::cout << "Position out of bounds!\n";
		return ;
	}

	Node *curr, *prev;
	curr = prev = head;

	if(pos == 0)
	{
		head = curr->next;
		delete curr;
		curr = nullptr;	
		return ;
	}

	for(int i = 0; i < pos; ++i)
	{
		prev = curr;
		curr = curr->next;
	}

	Node *temp = curr->next;
	prev->next = temp;
	delete curr;
	curr = nullptr;
}

void List::reverse()
{
	Node *curr, *prev, *fwd;
	prev = head;
	curr = fwd = head->next;
	prev->next = nullptr;

	while(fwd != nullptr)
	{
		curr = fwd;
		fwd = curr->next;
		curr->next = prev;
		prev = curr;
	}

	head = curr;
}

void List::show()
{
	if(head == nullptr)
	{
		std::cout << "List is empty!";
		return ;
	}
	Node *curr = head;

	while(curr != nullptr)
	{
		std::cout << curr->data << ' ';
		curr = curr->next;
	}
}