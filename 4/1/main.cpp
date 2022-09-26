#include <iostream>
#include <vector>
#include <algorithm>

void check_number(std::vector<double>::iterator it, std::vector<double>::iterator end) {
    if (it != end) {
        std::cout << "Found the number: " << *it << std::endl;
    } else {
        std::cout << "Did not find the number." << std::endl;
    }
}

int main() {
    std::vector<double> numbers = {0,1,2,3,4};

    std::cout << "First element of vector: " << numbers.front() << std::endl;
    std::cout << "Last element of vector: " << numbers.back() << std::endl;

    // Etter første element, som instruert i oppgaven
    numbers.emplace(numbers.begin()+1, 9); 
    
    // Første element som instruert i oppgaven
    std::cout << "First element of vector: " << numbers.front() << std::endl;
    std::cout << "Second element of vector: " << numbers.at(1) << std::endl;

    auto it = find(numbers.begin(), numbers.end(), 3);
    check_number(it, numbers.end());

    it = find(numbers.begin(), numbers.end(), 7);
    check_number(it, numbers.end());
}
