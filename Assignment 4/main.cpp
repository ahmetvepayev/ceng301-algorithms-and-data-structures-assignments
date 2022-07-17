#include <iostream>
#include "Library.h"
using namespace std;

int main() {
	int input, input2;

	while (true){
		cin >> input;
		if (input == -1){
			break;
		}
		for (int i=input; i > 0; i--){
			cin >> input;
			Library::Insert(input);
		}
		cin >> input >> input2;
		cout << Library::GetSmallestSubtreeRootId(input, input2) << endl;
		Library::Clear();
	}

	return 0;
}