#include <iostream>
#include <cstring>

int main() {
	char text[5];
	char *pointer = text;
	char search_for = 'e';
	std::cin >> text;
	while (*pointer != search_for) {
		*pointer = search_for;
		pointer++;
	}

	return 0;
}
