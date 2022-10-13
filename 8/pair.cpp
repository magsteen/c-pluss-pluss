
template<typename T, typename G>
class Pair {
public:
    T first;
    G second;

    Pair(T first_, G second_) : first(first_), second(second_) {};

    bool operator>(const Pair other) {
        return this->first + this->second > other.first + other.second;
    }

    Pair operator+(const Pair other) {
        return Pair(this->first + other.first, this->second + other.second);
    }
};
