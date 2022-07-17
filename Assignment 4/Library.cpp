#include "Library.h"
#include <iostream>
using namespace std;

Book* Library::root = NULL;

Book::Book(int givenId) {
	id = givenId;
	left = NULL;
	right = NULL;
}

void Library::Insert(const int & givenId, Book* & bookPtr) {
	if (bookPtr == NULL){
		bookPtr = new Book(givenId);
	}
	else if (givenId < bookPtr->id){
		Insert(givenId, bookPtr->left);
	}
	else if (givenId > bookPtr->id){
		Insert(givenId, bookPtr->right);
	}
}

void Library::Clear() {
	Clear(root);
	root = NULL;
}

void Library::Clear(Book* bookPtr) {
	if (bookPtr == NULL){
		return;
	}
	Clear(bookPtr->left);
	Clear(bookPtr->right);
	delete bookPtr;
}

int Library::GetSmallestSubtreeRootId(const int & id1, const int & id2, Book* bookPtr) {
	if (id1 < bookPtr->id && id2 < bookPtr->id){
		GetSmallestSubtreeRootId(id1, id2, bookPtr->left);
	}
	else if (id1 > bookPtr->id && id2 > bookPtr->id){
		GetSmallestSubtreeRootId(id1, id2, bookPtr->right);
	}
	else{
		return bookPtr->id;
	}
}