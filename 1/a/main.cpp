#include <iostream>

int main() {
	const int length = 5;
	unsigned int undr10 = 0, btween10n20 = 0, ovr20 = 0;

	std::cout << "Du skal skrive inn 5 temperaturer." << std::endl;

	for (unsigned int i = 1; i <= length; i++) {
		double input;
		std::cout << "Temperatur nr " << i << ": ";
		std::cin >> input;

		if (input < 10) undr10++;
		else if (input >= 10 && input <=20) btween10n20++;
		else if (input > 20) ovr20++;
	}

	std::cout << "Antall under 10 er " << undr10 << std::endl;
	std::cout << "Antall mellom 10 og 20 (inkl 10 og 20) er " << btween10n20 << std::endl;
	std::cout << "Antall over 20 er " << ovr20 << std::endl;
}
