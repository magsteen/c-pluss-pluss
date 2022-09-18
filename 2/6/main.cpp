#include <iostream>

int find_sum(const int *table, int length);

int main() {
	int length = 20;
	int table[length];
	int len_sum_one = 10;
	int len_sum_two = 5;
	int len_sum_three = 5;

	for (int i = 0; i < length; i++) {
		table[i] = i+1;
	}

	std::cout 
	<< find_sum(table, len_sum_one) << std::endl
	<< find_sum(table + len_sum_one, len_sum_two) << std::endl 
	<< find_sum(table + len_sum_one + len_sum_two, len_sum_three) << std::endl;

	return 0;
}

int find_sum(const int *table, int length) {
	int sum = 0;
	for (int i = 0; i < length; i++) {
		sum += *table;
		table++;
	}

	return sum;
}
