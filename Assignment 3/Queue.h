#include <iostream>
#ifndef _Queue_H
#define _Queue_H

struct Node{
	Node(char givenElement);
	char element;
	Node* next;
};

class Queue{
public:
	Queue ();
	char Front();
	void Enqueue(char c);
	bool Dequeue();
	bool IsEmpty();
	void Clear();
private:
	Node* front;
	Node* back;
};
#endif