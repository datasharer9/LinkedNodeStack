#include <iostream>
using namespace std;
#include <cctype>	// toupper
#include "LinkedNodeStack.h"

int main()
{
	LinkedNodeStack st;
	char c;
	int n;
	cout << "A to add, R to remove, or Q to quit\n";
	cin >> c;
	while (toupper(c) != 'Q') {
		switch (toupper(c)) {
		case 'A':
			cout << "Enter an integer number to add: ";
			cin >> n;
			if (!st.push(n)) cout << "Stack full.\n";
			break;
		case 'R':
			if (!st.pop(n)) cout << "Stack empty.\n";
			else cout << n << " popped.\n";
		}
		cout << "A to add, R to remove, or Q to quit\n";
		cin >> c;
	}
	cout << "Bye\n";
}