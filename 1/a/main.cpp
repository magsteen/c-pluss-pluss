#include <iostream>

using namespace std;

int main() {
  const int length = 5;
  unsigned int under_ten, between_ten_and_twenty, over_twenty;

  cout << "Du skal skrive inn 5 temperaturer." << endl;

  for (size_t i = 0; i < length; i++) {
    string str;
    cout << "Temperatur nr " << i+1 << ": ";
    getline(cin, str);
    double input = atof(str.c_str());

    if (input < 10) under_ten++;
    if (input >= 10 && input <=20) between_ten_and_twenty++;
    if (input > 20) over_twenty++;
  }

  cout << "Antall under 10 er " << under_ten << endl;
  cout << "Antall mellom 10 og 20 (inkl 10 og 20) er " << between_ten_and_twenty << endl;
  cout << "Antall over 20 er " << over_twenty << endl;
}
