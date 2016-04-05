#include <iostream>
#include <fstream>

int c2i(char c)
{
	return c - '0';
}

static const int NUM_DIGITS = 5;

int main()
{
	std::string s;
	std::ifstream num_file("assets/p008_number.txt");
	std::string tmp;
	while (num_file >> tmp) s += tmp;

	uint64_t largeprod = 0;
	for (size_t i = 0; i < s.length() - (NUM_DIGITS - 1); i++) {
		uint64_t prod = 1;
		for (size_t j = i; j < NUM_DIGITS; j++) {
			prod *= c2i(s[j]);
		}

		largeprod = std::max(largeprod, prod);
	}
	std::cout << "Largest product of " << NUM_DIGITS << " digits: " << largeprod << std::endl;
}
