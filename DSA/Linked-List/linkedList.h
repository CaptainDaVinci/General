#ifndef LIST_H
#define LIST_H

class Node
{
	int data;
	Node *next;

	Node()
	{
		data = 0;
		next = nullptr;
	}
	friend class List;
};

class List
{
	Node *head;

public:
	List();
	~List();

	int size();
	void push(int data);
	void insert(int data, int pos);
	void deleteNode(int pos);
	void reverse();
	void show();
};

#endif