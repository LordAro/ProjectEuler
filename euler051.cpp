#include <algorithm>
#include <iostream>
#include <string>
#include "prime.hpp"

static const int NUM_PRIMES = 8;

int main()
{
	for (int i = 1; i <= 4; i++) {
		std::string stars(i, '*');
		for (int j = 0; j < 10000; j++) {
			std::string tmpl = stars + std::to_string(j);
			do {
				// Get rid of obvious non-primes
				if (tmpl[0] == '0') continue;
				if (tmpl.back() == '*' || ((tmpl.back() - '0') % 2) == 0) continue;

				int prime_count = 0;
				for (char d = '0'; d <= '9'; d++) {
					std::string num = tmpl;
					std::replace(num.begin(), num.end(), '*', d);
					if (num[0] != '0' && IsPrime(std::stoi(num))) {
						prime_count++;
					}
				}
				if (NUM_PRIMES == prime_count) {
					std::string smallest = tmpl;
					std::replace(smallest.begin(), smallest.end(), '*', tmpl[0] == '*' ? '1' : '0');
					std::cout << "Smallest primes with " << NUM_PRIMES
					          << " prime permutations: " << smallest << std::endl;
					return 0;
				}
			} while(std::next_permutation(tmpl.begin(), tmpl.end()));
		}
	}
	return 0;
}
