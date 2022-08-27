#include <fstream>
#include <iostream>

using namespace std;

void read_temperatures(double temperatures[], int length);

int main() {
	unsigned int under_ten, between_ten_and_twenty, over_twenty;
	double temps[5];

	read_temperatures(temps, (sizeof(temps) / sizeof(*temps)));

	for (double temp : temps) {
		if (temp < 10) under_ten++;
		if (temp >= 10 && temp <=20) between_ten_and_twenty++;
		if (temp > 20) over_twenty++;
	}

	cout << "Antall under 10 er " << under_ten << endl;
	cout << "Antall mellom 10 og 20 (inkl 10 og 20) er " << between_ten_and_twenty << endl;
	cout << "Antall over 20 er " << over_twenty << endl;
}

void read_temperatures(double temperatures[], int length)
{
	string filename;
	ifstream file;

	cout << "Define path to file with temperatures: ";
	getline(cin, filename);

	file.open(filename);

	if (!file) {
		cout << "Feil ved åpning av innfil." << endl;
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < length; i++) {
		file >> temperatures[i];
	}

	file.close();
}
