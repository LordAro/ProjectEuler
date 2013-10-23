#include <iostream>
#include <gmpxx.h>

int main()
{
	mpz_class num(2);
	for (int i = 1; i < 1000; i++) {
		num *= 2;
	}
	std::string strnum = num.get_str();
	int total = 0;
	for (uint i = 0; i < strnum.length(); i++) {
		total += (strnum[i] - '0');
	}
	std::cout << "Sum of 2^1000 digits: " << total << std::endl;
}
