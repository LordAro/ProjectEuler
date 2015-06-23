#include <iostream>
#include <gmp.h>
#include <gmpxx.h>

mpz_class choose(int n, int k)
{
	mpz_class n_fac;
	mpz_fac_ui(n_fac.get_mpz_t(), n);

	mpz_class k_fac;
	mpz_fac_ui(k_fac.get_mpz_t(), k);

	mpz_class nk_fac;
	mpz_fac_ui(nk_fac.get_mpz_t(), n - k);

	return n_fac / (k_fac * nk_fac);
}


int main()
{
	int count = 0;
	for (int n = 1; n <= 100; n++) {
		for (int k = 1; k <= n; k++) {
			mpz_class res = choose(n, k);
			if (res > 1000000) {
				count++;
			}
		}
	}
	std::cout << "Total: " << count << std::endl;
}
