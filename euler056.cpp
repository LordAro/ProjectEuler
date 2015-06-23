#include <iostream>
#include <gmp.h>
#include <gmpxx.h>

mpz_class DigitSum(mpz_class num)
{
	mpz_class sum = 0;
	while (num != 0) {
		mpz_class digit = num % 10;
		sum += digit;
		num /= 10;
	}
	return sum;
}

int main()
{
	mpz_class max_sum = 0;
	for (int a = 1; a < 100; a++) {
		for (int b = 1; b < 100; b++) {
			mpz_class pow;
			mpz_ui_pow_ui(pow.get_mpz_t(), a, b);
			max_sum = std::max(max_sum, DigitSum(pow));
		}
	}
	std::cout << "Max digit sum: " << max_sum << std::endl;
}
