#include <iostream>
#include <vector>
#include <gmp.h>
#include <gmpxx.h>

int main()
{
	mpz_class fact = 1;
	for (int i = 100; i > 0; i--) {
		fact *= i;
	}
	std::string strnum = fact.get_str();
	int total = 0;
	for (uint i = 0; i < strnum.length(); i++) {
		total += (strnum[i] - '0');
	}
	std::cout << "Sum of digits of 100!: " << total << std::endl;
}