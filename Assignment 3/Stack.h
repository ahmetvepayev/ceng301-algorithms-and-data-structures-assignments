#include "Queue.h"
#ifndef _Stack_H
#define _Stack_H

class Stack{
public:
	char Top();
	void Push(char charPushed);
	bool Pop();
	bool IsEmpty();
	void Clear();
private:
	Queue Q1;
	Queue Q2;
};
#endif