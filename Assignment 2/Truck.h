#include "Item.h"
#ifndef _Truck_H
#define _Truck_H

class Truck{
public:
	Truck (int givenVolume = 0);
	static Truck* SearchTruck(int trkPos);
	static Truck* SearchAvailable(int givenVolume);
	bool IsAvailable(int givenVolume = maxVolume - fullThreshold + 1);
	void AddItem(int givenVolume);
	void RemoveItem(int itemPos);
	void DeleteTruck();

	static void CmdAddItem();
	static void CmdRemoveItem();
	static void CmdDepartTrucks();
	static void CmdReportDetailed();
	static void CmdReportSummary();
private:
	static int maxVolume;
	static int maxItems;
	static int fullThreshold;
	static int truckCount;
	static Truck* headTruck;
	static Truck* tailTruck;
	int totalVolume;
	Truck* prevTruck;
	Truck* nextTruck;
	Item* headItem;
	Item* tailItem;
};
#endif