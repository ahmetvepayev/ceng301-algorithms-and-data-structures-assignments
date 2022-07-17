#include <iostream>
#ifndef _Item_H
#define _Item_H

using namespace std;

class Item{
public:
	Item (int givenVolume = 0, int givenPosition = 1);
	int Position() const;
	static Item* CreateItem(Item* tailItem, int givenVolume);
	static Item* SearchItem(Item* headItem, int itemPos);
	static void UpdatePositions(Item* itemPtr);
	static void DeleteItem(Item* itemPtr, Item* & headItem, Item* & tailItem, int & totalVolume);

	static void Report(Item* itemPtr);
private:
	int volume;
	int position;
	Item* nextItem;
};
#endif
