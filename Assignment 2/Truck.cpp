#include "Truck.h"

int Truck::maxVolume = 500;
int Truck::maxItems = 8;
int Truck::fullThreshold = 450; // <= maxVolume
int Truck::truckCount = 0;
Truck* Truck::headTruck = NULL;
Truck* Truck::tailTruck = NULL;

Truck::Truck(int givenVolume) {
	totalVolume = 0;
	prevTruck = tailTruck;
	nextTruck = NULL;
	if (headTruck == NULL){
		headTruck = this;
	}
	else {
		tailTruck->nextTruck = this;
	}
	tailTruck = this;
	headItem = NULL;
	tailItem = NULL;
	truckCount = truckCount + 1;
	AddItem(givenVolume);
}

Truck* Truck::SearchTruck(int trkPos) {
	Truck* trkPtr;
	if (trkPos <= truckCount/2){
		trkPtr = headTruck;
		while (trkPos > 1){
			trkPtr = trkPtr->nextTruck;
			trkPos = trkPos - 1;
		}
	}
	else {
		trkPtr = tailTruck;
		while (trkPos < truckCount){
			trkPtr = trkPtr->prevTruck;
			trkPos = trkPos + 1;
		}
	}
	return trkPtr;
}

Truck* Truck::SearchAvailable(int givenVolume) {
	Truck* trkPtr = headTruck;
	while (trkPtr != NULL){
		if (trkPtr->IsAvailable(givenVolume)){
			return trkPtr;
		}
		trkPtr = trkPtr->nextTruck;
	}
	return NULL;
}

bool Truck::IsAvailable(int givenVolume) {
	return (totalVolume + givenVolume <= maxVolume) && (tailItem->Position() < maxItems);
}

void Truck::AddItem(int givenVolume) {
	if (headItem == NULL && tailItem == NULL){
		headItem = tailItem = new Item(givenVolume);
	}
	else {
		tailItem = Item::CreateItem(tailItem, givenVolume);
	}
	totalVolume = totalVolume + givenVolume;
}

void Truck::RemoveItem(int itemPos) {
	Item* prevItem = Item::SearchItem(headItem, itemPos);
	Item::DeleteItem(prevItem, headItem, tailItem, totalVolume);
}

void Truck::DeleteTruck() {
	if (prevTruck == NULL){
		headTruck = nextTruck;
	}
	else {
		prevTruck->nextTruck = nextTruck;
	}
	if (nextTruck == NULL){
		tailTruck = prevTruck;
	}
	else {
		nextTruck->prevTruck = prevTruck;
	}
	delete this;
	truckCount = truckCount - 1;
}

void Truck::CmdAddItem(){
	int itemVolume;
	cin >> itemVolume;
	if (itemVolume > maxVolume){
		cout << "An item with a volume of more than " << maxVolume
			<< " units cannot loaded to any truck." << endl;
		return;
	}
	else{
		Truck* trkPtr = SearchAvailable(itemVolume);
		if (trkPtr == NULL){
			new Truck(itemVolume);
		}
		else {
			trkPtr->AddItem(itemVolume);
		}
	}
}

void Truck::CmdRemoveItem(){
	int truckPosition, itemPosition;
	cin >> truckPosition >> itemPosition;
	Truck* trkPtr = SearchTruck(truckPosition);
	if (trkPtr->headItem == trkPtr->tailItem){
		trkPtr->DeleteTruck();
	}
	else {
		trkPtr->RemoveItem(itemPosition);
	}
}

void Truck::CmdDepartTrucks() {
	int counter = 0;
	Truck* trkPtr = headTruck;
	while (trkPtr != NULL){
		if (! trkPtr->IsAvailable() ){
			counter = counter + 1;
			if (trkPtr == tailTruck){
				trkPtr->DeleteTruck();
				break;
			}
			else {
				trkPtr = trkPtr->nextTruck;
				trkPtr->prevTruck->DeleteTruck();
			}
		}
		else {
			trkPtr = trkPtr->nextTruck;
		}
	}
	cout << counter << " cargo truck departed." << endl;
}

void Truck::CmdReportDetailed() {
	int counter = 1;
	Truck* trkPtr = headTruck;
	while (trkPtr != NULL){
		cout << "Cargo truck " << counter << " with " << trkPtr->tailItem->Position()
			<< " item -> ";
		Item::Report(trkPtr->headItem);
		cout << " = " << trkPtr->totalVolume << endl;
		trkPtr = trkPtr->nextTruck;
		counter = counter + 1;
	}
}

void Truck::CmdReportSummary() {
	int counter = 1, countVolume = 0;
	Truck* trkPtr = headTruck;
	cout << "Summary: ";
	while (trkPtr != NULL){
		cout << "Truck" << counter << "(" << trkPtr->totalVolume << ")";
		if (trkPtr != tailTruck){
			cout << " + ";
		}
		counter = counter + 1;
		countVolume = countVolume + trkPtr->totalVolume;
		trkPtr = trkPtr->nextTruck;
	}
	cout << " = " << countVolume << endl;
}