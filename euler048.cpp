#include <iostream>
#include <gmp.h>
#include <gmpxx.h>

int main()
{
	mpz_class sum = 0;
	for (int i = 1; i <= 1000; i++) {
		mpz_class pow;
		mpz_ui_pow_ui(pow.get_mpz_t(), i, i);
		sum += pow;
	}
	std::cout << "Sum: " << sum << std::endl;
}
