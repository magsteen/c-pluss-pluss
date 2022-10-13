#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "set.hpp"

int main() {
    Set empty_set;
    std::cout << "Empty set: " << empty_set << std::endl << std::endl;

    Set one({1, 2, 3});
    Set two({2, 3, 4, 5});
    std::cout << "Take union between two sets: " << one << " and " << two << std::endl;
    std::cout << "Result: " << one + two << "\n\n";

    std::cout << "Add number " << 4 << " to set: " << one << std::endl;
    std::cout << "Result: " << one + 4 << "\n\n";

    std::cout << "Set one set equal to another set: " << one << " -> " << two << std::endl;
    one = two;
    std::cout << "Result: " << one << "\n\n";
}
