#include <cmath>
#include <gmp.h>
#include <gmpxx.h>
#include <iostream>

// Because sizeinbase isn't accurate enough
size_t digit_count(mpz_class num)
{
	size_t count = 0;
	for (; num > 0; count++) {
		num /= 10;
	}
	return count;
}

int main()
{
	int count = 0;
	for (size_t exp = 1; exp < 100; exp++) {
		for (size_t base = 1; base < 10; base++) {
			mpz_class pow;
			mpz_ui_pow_ui(pow.get_mpz_t(), base, exp);
			size_t d_count = digit_count(pow);
			if (d_count == exp) {
				std::cout << base << '^' << exp << '=' << pow << " (" << d_count << ")\n";
				count++;
			}
			if (d_count > exp) {
				break;
			}
		}
	}
	std::cout << "Number of numbers: " << count << '\n';
}
