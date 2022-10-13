#include "set.hpp"

bool set_contains(const std::vector<int> set, const int other) {
    for (auto elem : set) {
        if (other == elem) return true;
    }
    return false;
}

Set::Set() : set() {}

Set::Set(std::vector<int> vec_) {
    set = vec_;
}

Set Set::operator+(const int other) const {
    auto set = this->set;
    if (!set_contains(set, other))
        set.emplace_back(other);
    return Set(set);
}

Set &Set::operator+=(const int other) {
    if (!set_contains(this->set, other))
        this->set.emplace_back(other);
    return *this;
}

Set Set::operator+(const Set &other) const {
    auto set = *this;
    for (auto elem : other.set) {
        set += elem;
    }
    return set;
}

std::ostream &operator<<(std::ostream &out, Set set) {
    out << "{";
    for (auto i = set.set.begin(); i != set.set.end(); i++) {
        out << *i;
        if (i != set.set.end() - 1) {
            out << ", ";
        }
    }
    out << "}";
    return out;
}
