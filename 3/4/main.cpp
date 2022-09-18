  #include <iostream>
  #include <string>

int main() {
	// a
	std::cout << "A" << std::endl;
	std::string word1, word2, word3;
	std::cin >> word1; std::cin >> word2; std::cin >> word3;

	// b
	std::cout << "B" << std::endl;
	std::string sentence = word1 + " " + word2 + " " + word3 + ".";
	std::cout << "  # New sentence: " + sentence << std::endl;

	// c
	std::cout << "C" << std::endl;
	std::cout
	<< "  # word1 length: " << word1.length() << std::endl
	<< "  # word2 length: " << word2.length() << std::endl
	<< "  # word3 length: " << word3.length() << std::endl
	<< "  # sentence length: " << sentence.length() << std::endl;

	// d
	std::cout << "D" << std::endl;
	std::string sentence2 = sentence;
	std::cout
	<< "  # Original sentence: " + sentence << std::endl
	<< "  #   Copied sentence: " + sentence2 << std::endl;

	// e
	std::cout << "E" << std::endl;
	if (sentence2.length() < 12) {
		std::cout << "  # The 3 combined words must collectively be larger than 12 characters." << std::endl;
		exit(EXIT_FAILURE);
	}

	for (unsigned int i = 10; i <= 12; i++) {
		sentence2[i] = *"x";
	}
	
	std::cout 
	<< "  # Original sentence: " + sentence << std::endl
	<< "  # X'ed sentence: " + sentence2 << std::endl;

	// f
	std::cout << "F" << std::endl;
	std::string sentence_start = sentence.substr(5);
	std::cout 
	<< "  # Original sentence: " + sentence << std::endl 
	<< "  # Sentence from fifth char (inclusive): " + sentence_start << std::endl;

	// g
	std::cout << "G" << std::endl;
	size_t pos = sentence.find("hallo");
	if (pos == std::string::npos) std::cout << "  # No 'hallo found.'" << std::endl;
	else std::cout << "  # Found 'hallo' occurence at pos: " << pos << std::endl;

	// h
	std::cout << "H" << std::endl;
	int occurences = 0;
	for (size_t i = 0; i < sentence.length();) {
		size_t pos = sentence.substr(i).find("er");
		if (pos == std::string::npos or (pos == std::string::npos and i == 0)) {
			break;
		}
		occurences++;
		i += pos+1;
	}

	std::cout << "  # Number of 'er' in the provided words: " << occurences << std::endl;
}
