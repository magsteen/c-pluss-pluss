#pragma once

const double pi = 3.141592;

namespace shape
{
    class Circle {
    public:
        Circle(double radius_);
        
        double get_area() const;
        double get_circumference() const;

    private:
        double radius;
    };
}
