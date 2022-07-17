#include <iostream>
#include "Truck.h"
using namespace std;

int main(){
	string input;

	while (input != "q"){
		cin >> input;
		if (input == "ai"){
			Truck::CmdAddItem();
		}
		else if (input == "ri"){
			Truck::CmdRemoveItem();
		}
		else if (input == "depart"){
			Truck::CmdDepartTrucks();
		}
		else if (input == "rd"){
			Truck::CmdReportDetailed();
		}
		else if (input == "rs"){
			Truck::CmdReportSummary();
		}
	}
	cout << "Quited" << endl;

	return 0;
}