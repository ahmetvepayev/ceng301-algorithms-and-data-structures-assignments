#include "Item.h"

Item::Item(int givenVolume, int givenPosition) {
	volume = givenVolume;
	position = givenPosition;
	nextItem = NULL;
}

int Item::Position() const {
	return position;
}

Item* Item::CreateItem(Item* tailItem, int givenVolume) {
	return tailItem->nextItem = new Item(givenVolume, tailItem->position + 1);
}

Item* Item::SearchItem(Item* headItem, int itemPos) {
	if (headItem->position == itemPos){
		return NULL;
	}
	while (headItem->nextItem != NULL && headItem->nextItem->position != itemPos){
		headItem = headItem->nextItem;
	}
	return headItem;
}

void Item::UpdatePositions(Item *itemPtr) {
	while (itemPtr->nextItem != NULL){
		itemPtr = itemPtr->nextItem;
		itemPtr->position = itemPtr->position - 1;
	}
}

void Item::DeleteItem(Item* itemPtr, Item* & headItem, Item* & tailItem, int & totalVolume) {
	if (itemPtr == NULL){
		itemPtr = headItem;
		headItem = itemPtr->nextItem;
		if (tailItem == itemPtr){
			tailItem = NULL;
		}
	}
	else {
		Item* tmpPtr = itemPtr;
		itemPtr = itemPtr->nextItem;
		tmpPtr->nextItem = itemPtr->nextItem;
		if (tailItem == itemPtr){
			tailItem = tmpPtr;
		}
	}
	if (itemPtr->nextItem != NULL){
		UpdatePositions(itemPtr);
	}
	totalVolume = totalVolume - itemPtr->volume;
	delete itemPtr;
}

void Item::Report(Item* itemPtr) {
	while (itemPtr != NULL){
		cout << itemPtr->volume << "(" << itemPtr->position << ")";
		if (itemPtr->nextItem != NULL){
			cout << " + ";
		}
		itemPtr = itemPtr->nextItem;
	}
}