#include <iostream>

using namespace std;

int main() {
	int i = 3;
	int j = 5;
	int *p = &i;
	int *q = &j;

	*p = 7; 	// i = 7
	*q += 4;	// j = 9
	*q = *p + 1;// j = 7 + 1 = 8
	p = q;

	cout << *p << " " << *q << endl; // 8 8
}
