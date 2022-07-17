#include "Stack.h"
using namespace std;

Stack stack;
bool isEnclosed (string input);

int main() {
	string input;

	while (true){
		cin >> input;
		if (input == "q"){
			break;
		}
		cout << input << " brackets are ";
		if (!isEnclosed(input)){
			cout << "not ";
		}
		cout << "enclosed." << endl;
	}
	return 0;
}

bool isEnclosed (string input){
	if (input.length()%2 != 0){
		return false;
	}
	int index = 0;
	while (index < input.length()/2){
		if (!(input[index] == '(' || input[index] == '[' || input[index] == '{')){
			stack.Clear();
			return false;
		}
		stack.Push(input[index]);
		index++;
	}
	for (char c = stack.Top(); c; c = stack.Top()){
		if (!((c == '(' && input[index] == ')') || (c == '[' && input[index] == ']') || (c == '{' && input[index] == '}'))){
			stack.Clear();
			return false;
		}
		stack.Pop();
		index++;
	}
	return true;
}