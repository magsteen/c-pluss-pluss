#include <iostream>
#include "circle.hpp"

int main() {
    shape::Circle circle(2.0);

    std::cout << "Circle area: " << circle.get_area() << std::endl
    << "Circle circumference: " << circle.get_circumference() << std::endl;
}
