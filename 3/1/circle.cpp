#include "circle.hpp" // header in local directory

namespace shape
{
    Circle::Circle(double radius_) : radius(radius_) {}

    double Circle::get_area() const {
        return pi * radius * radius;
    }

    double Circle::get_circumference() const {
        return 2.0 * pi * radius;
    }
}
