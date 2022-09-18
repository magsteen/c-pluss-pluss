#include <iostream>

int main() {
	// ORIGINALT PROBLEM
	// int a = 5;
	// int &b; // Referanse må være initialisert
	// int *c;
	// c = &b;
	// *a = *b + *c;
	// 		både a og b blir brukt som pekere, men a er en variabel
	//		og b er en referanse til en variabel.
	// &b = 2; 
	//		b er allerede en referanse så det gir ikke mening 
	//		å sette den som referanse igjen.

	// LØSNING
	int a = 5;
	int &b = a;
	int *c;
	c = &b;
	a = b + *c;
	b = 2;

	return 0;
}
