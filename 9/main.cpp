#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::ostream &operator<<(std::ostream &out, const std::vector<int> &table) {
  for (auto &e : table)
    out << e << " ";
  return out;
}

bool equal_with_pred(std::vector<int> v1, std::vector<int> v2, int range_end) {
	return std::equal(
		v1.begin(), 
		v1.begin() + range_end, 
		v2.begin(), 
		[](int e1, int e2) { return abs(e1 -e2) <= 2; }
	);
}

int main() {
	std::vector<int> v1 = {3, 3, 12, 14, 17, 25, 30};
	std::cout << "v1: " << v1 << std::endl;
	std::vector<int> v2 = {2, 3, 12, 14, 24};
	std::cout << "v2: " << v2 << std::endl;

	// a)
	auto num = 15;
	auto pos = std::find_if(v1.begin(), v1.end(), [num](int e) { return e > num; });
	if (pos != v1.end()) {
    	std::cout << "Et tall større enn " << num << " fins i v1 på indeks " << (pos - v1.begin()) << std::endl;
	} else
		std::cout << "Et tall større enn " << num << " fins ikke i v1" << std::endl;

	// b)
	if (equal_with_pred(v1, v2, 5))
		std::cout << "Equal intervals" << std::endl;
	else
		std::cout << "Unequal intervals" << std::endl;
	
	if (equal_with_pred(v1, v2, 4))
		std::cout << "Equal intervals" << std::endl;
	else
		std::cout << "Unequal intervals" << std::endl;

	// c)
	std::vector<int> copy;
	copy.resize(v1.size());
	std::replace_copy_if(v1.begin(), v1.end(), copy.begin(), [](int e) { return e % 2 != 0; }, 100);

	std::cout << "Ny endret kopi av v1: " << copy << std::endl;
}
