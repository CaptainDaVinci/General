#ifndef STACK_H
#define STACK_H

class Node
{
	int data;
	Node *next;

	friend class Stack;

	Node()
	{
		data = 0;
		next = nullptr;
	}
};

class Stack
{
	Node *head, *stack_ptr;

public:
	Stack();
	~Stack();

	void push(int x);
	int pop();
	int top();
};

#endif