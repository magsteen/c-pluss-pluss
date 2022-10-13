#pragma once

#include <vector>
#include <ostream>

class Set {
public:
    std::vector<int> set;

public:
    Set();
    Set(std::vector<int> set);
    // Set(int elem...);

    Set operator+(const int other) const;
    Set &operator+=(const int other);
    Set operator+(const Set &other) const;

    friend std::ostream &operator<<(std::ostream &out, Set set);
};
