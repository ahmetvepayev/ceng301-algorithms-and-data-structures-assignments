#include "Stack.h"

char Stack::Top(){
	if (IsEmpty()){
		return '\0';
	}
	if (Q1.IsEmpty()){
		return Q2.Front();
	}
	else {
		return Q1.Front();
	}
}

void Stack::Push(char charPushed) {
	Queue* filled;
	Queue* emptied;
	if (Q1.IsEmpty()){
		filled = &Q1;
		emptied = &Q2;
	}
	else {
		filled = &Q2;
		emptied = &Q1;
	}

	filled->Enqueue(charPushed);
	for (char c = emptied->Front(); c; c = emptied->Front()){
		filled->Enqueue(c);
		emptied->Dequeue();
	}
}

bool Stack::Pop() {
	if (IsEmpty()){
		return false;
	}
	if (Q1.IsEmpty()){
		return Q2.Dequeue();
	}
	else {
		return Q1.Dequeue();
	}
}

bool Stack::IsEmpty() {
	return Q1.IsEmpty() && Q2.IsEmpty();
}

void Stack::Clear() {
	Q1.Clear();
	Q2.Clear();
}

