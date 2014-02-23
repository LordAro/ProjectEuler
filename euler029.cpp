#include <iostream>
#include <set>

#include <gmp.h>
#include <gmpxx.h>

int main()
{
	int limit = 100;
	std::set<mpz_class> nums;
	for (int a = 2; a <= limit; a++) {
		for (int b = 2; b <= limit; b++) {
			mpz_class r;
			mpz_ui_pow_ui(r.get_mpz_t(), a, b);
			nums.insert(r);
		}
	}
	std::cout << "Number of distinct numbers: " << nums.size() << std::endl;
}
