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

/*
	IMPORTANT:
	This class should contain a copy and assignment constructor!
*/

class List
{
public:
	Node *head;
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