#include <iostream>

using namespace std;

int find_sum(const int *table, int length);

int main() {
	int length = 20;
	int table[length];
	int len_sum_one = 10;
	int len_sum_two = 5;
	int len_sum_three = 5;

	for (int i = 0; i < length; i++) {
		table[i] = i;
	}

	cout 
	<< find_sum(table, len_sum_one) << endl
	<< find_sum(table + len_sum_one, len_sum_two) << endl 
	<< find_sum(table + len_sum_one + len_sum_two, len_sum_three) << endl;
}

int find_sum(const int *table, int length) {
	int sum = 0;
	for (int i = 0; i < length; i++) {
		sum += *table;
		table++;
	}

	return sum;
}
