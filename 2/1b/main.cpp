#include <iostream>

int main() {
	int i = 3;
	int j = 5;
	int *p = &i;
	int *q = &j;

	*p = 7; 	 // i settes til verdi 7
	*q += 4;	 // j settes til verdi 5 + 4, som blir 9
	*q = *p + 1; // j settes til 7 + 1, som blir 8
	p = q;		 // i settes til 8

	std::cout << *p << " " << *q << std::endl; // printer ut 8 og 8

	return 0;
}
