#include <algorithm>
#include <iostream>
#include <vector>

static const int N_MAX = 10'000'000;

std::vector<int> split_digits(uint64_t n)
{
	std::vector<int> digits;
	while (n > 0) {
		digits.emplace_back(n % 10);
		n /= 10;
	}
	return digits;
}

int main()
{
	// totient function sieve
	std::vector<uint64_t> phi(N_MAX + 1, 0); // could use an array, but stack size says no
	for (int i = 2; i <= N_MAX; i++) {
		if (phi[i] == 0) {
			phi[i] = i - 1; // prime default case
			for (int j = i * 2; j <= N_MAX; j += i) {
				if (phi[j] == 0) phi[j] = j;
				phi[j] = phi[j] * (i - 1) / i;
			}
		}
	}

	int min_n = 0;
	double min_divisor_n = 10.0;

	for (int n = 2; n <= N_MAX; n++) {
		auto n_digits = split_digits(n);
		auto phi_digits = split_digits(phi[n]);
		if (std::is_permutation(n_digits.begin(), n_digits.end(), phi_digits.begin(), phi_digits.end())) {
			double divisor = (double)n / phi[n];
			if (divisor < min_divisor_n) {
				min_n = n;
				min_divisor_n = divisor;
			}
		}
	}
	std::cout << "Min n for n/totient(n) where n is a permutation of phi(n): " << min_n << '\n';
}
