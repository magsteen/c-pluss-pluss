#include <iostream>

using namespace std;

int main() {
	int number = 0;
	int *ptr = &number;
	int &ref = number;
	cout << "Starting value: " << number << endl;

	// First
	number = 1;
	cout << number << endl;

	// Second
	*ptr = 2;
	cout << number << endl;

	// Third
	ref = 3;
	cout << number << endl;
}
