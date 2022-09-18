#include <iostream>

int main() {
	int number = 0;
	int *ptr = &number;
	int &ref = number;
	std::cout << "Starting value: " << number << std::endl;

	// First
	number = 1;
	std::cout << number << std::endl;

	// Second
	*ptr = 2;
	std::cout << number << std::endl;

	// Third
	ref = 3;
	std::cout << number << std::endl;

	return 0;
}
