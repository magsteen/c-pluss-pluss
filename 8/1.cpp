#include <iostream>
#include <string>
#include <cmath>        // std::abs

template <typename Type> 
bool equal(Type a, Type b) {
	std::cout << "-template-" << std::endl;
	return a == b;
}

bool equal(double a, double b) {
	std::cout << "-regulare-" << std::endl;
	if(std::abs(a - b) < 0.00001) return true;
	return false;
}

int main() {
	double val1 = 0.00001;
	double val2 = 0.00001;
	double val3 = 0.00003;
	double val4 = 0.000003;

	std::cout << equal<double>(val1, val2) << std::endl;
	std::cout << equal<double>(val1, val3) << std::endl;

	std::cout << equal(val1, val2) << std::endl;
	std::cout << equal(val1, val3) << std::endl;
	std::cout << equal(val1, val4) << std::endl;
}
