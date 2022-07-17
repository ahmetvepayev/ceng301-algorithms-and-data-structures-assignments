#include "Queue.h"

Node::Node(char givenElement) {
	element = givenElement;
	next = NULL;
}

Queue::Queue() {
	front = NULL;
	back = NULL;
}

char Queue::Front() {
	if (IsEmpty()){
		return '\0';
	}
	return front->element;
}

void Queue::Enqueue(char c) {
	if (IsEmpty()){
		front = back = new Node(c);
	}
	else {
		back = back->next = new Node(c);
	}
}

bool Queue::Dequeue() {
	if (IsEmpty()){
		return false;
	}
	if (front == back){
		back = NULL;
	}
	Node* dltNode = front;
	front = front->next;
	delete dltNode;
	return true;
}

bool Queue::IsEmpty() {
	return front == NULL && back == NULL;
}

void Queue::Clear() {
	while (Dequeue());
}

