#include <fstream>
#include <iostream>

void read_temperatures(double temperatures[], int length);

int main() {
	const unsigned int tempLen = 5;
	double temps[tempLen];
	unsigned int undr10 = 0, btween10n20 = 0, ovr20 = 0;

	read_temperatures(temps, tempLen);

	for (double temp : temps) {
		if (temp < 10) undr10++;
		else if (temp >= 10 && temp <=20) btween10n20++;
		else if (temp > 20) ovr20++;
	}

	std::cout << "Antall under 10 er " << undr10 << std::endl;
	std::cout << "Antall mellom 10 og 20 (inkl 10 og 20) er " << btween10n20 << std::endl;
	std::cout << "Antall over 20 er " << ovr20 << std::endl;
}

void read_temperatures(double temperatures[], int length)
{
	std::string filename;
	std::ifstream file;

	std::cout << "Define path to file with temperatures: ";
	getline(std::cin, filename);

	file.open(filename);

	if (!file) {
		std::cout << "Feil ved åpning av innfil." << std::endl;
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < length; i++) {
		if (!(file >> temperatures[i])) {
			std::cerr << "Uforventet EOF: Fikk ikke nok temperaturer inn. Forventer minst " 
			<< length << " temperaturer, men fikk bare " << i << " stk." << std::endl;
			exit(EXIT_FAILURE);
		}
	}

	file.close();
}
