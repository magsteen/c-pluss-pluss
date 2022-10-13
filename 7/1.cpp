#include "fraction.hpp"
#include <iostream>
#include <string>

using namespace std;

void print(const string &text, const Fraction &broek) {
  cout << text << broek.numerator << " / " << broek.denominator << endl;
}

int main() {
  Fraction a(10, 20);
  Fraction b(3, 4);
  Fraction c;
  c.set(5);
  Fraction d = a / b;

  print("a = ", a);
  print("b = ", b);
  print("c = ", c);
  print("d = ", d);

  b += a;
  ++c;
  d *= d;

  print("b = ", b);
  print("c = ", c);
  print("d = ", d);

  c = a + b - d * a;
  c = -c;

  print("c = ", c);

  if (a + b != c + d)
    cout << "a + b != c + d" << endl;
  else
    cout << " a + b == c + d" << endl;
  while (b > a)
    b -= a;
  print("b = ", b);


  Fraction fraction1(5, 10);
  auto test1 = fraction1 - 5;
  print("test1 = ", test1);
  auto test2 = 5 - fraction1;
  print("test2 = ", test2);
}

// Utskrift:
// a = 1 / 2
// b = 3 / 4
// c = 5 / 1
// d = 2 / 3
// b = 5 / 4
// c = 6 / 1
// d = 4 / 9
// c = -55 / 36
// a + b != c + d
// b = 1 / 4

// a)
// test1 = -9 / 2
// test2 = 9 / 2

// b)
// 5 - 3 - fraction1 - 7 - fraction2 -> (((5 - 3) - fraction1) - 7) - fraction2
// Operasjonene som brukes er 
//      primitiv int operator-(int, int)
//      Fraction operator-(const int, Fraction);
//      Fraction operator-(const int) const;
//      Fraction operator-(const Fraction); 
// 
