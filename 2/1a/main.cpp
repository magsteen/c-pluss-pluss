#include <iostream>

void printIntVariable(int &var) {
    std::cout << "Adressen til var: " << &var << std::endl
              << " Verdien til var: " << var << std::endl;
}

void printIntPointer(int *&var) {
    std::cout << "Adressen til var: " << &var << std::endl
              << " Verdien til var: " <<  var << std::endl;
}

int main() {
    int i = 3;
    int j = 5;
    int *p = &i;
    int *q = &j;

    printIntVariable(i);
    printIntVariable(j);
    printIntPointer(p);
    printIntPointer(q);

    return 0;
}
