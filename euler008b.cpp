#include <iostream>
#include <fstream>

#include "benchmark.hpp"

int digit_product(const std::string &s, int digits)
{
	uint64_t largeprod = 0;
	for (size_t i = 0; i < s.length() - (digits - 1); i++) {
		uint64_t prod = 1;
		for (size_t j = i; j < i + digits; j++) {
			prod *= s[j] - '0';
		}

		largeprod = std::max(largeprod, prod);
	}
	std::cout << "Largest product of " << digits << " digits: " << largeprod << std::endl;
	return largeprod;
}

int main()
{
	std::string s;
	std::ifstream num_file("assets/p008_number.txt");
	std::string tmp;
	while (num_file >> tmp) s += tmp;

	return benchmark(100000, digit_product, s, 13) ? 0 : 1;
}
