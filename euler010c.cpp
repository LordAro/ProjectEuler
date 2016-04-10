#include <iostream>
#include <vector>

#include "benchmark.hpp"

static constexpr int LIMIT = 1415; // ~sqrt(2 mil)
static constexpr int LIMIT2 = LIMIT * LIMIT;

long sieve_of_eratosthenes_total()
{
	std::vector<bool> sieve(LIMIT2, true);
	for (int p = 7; p < LIMIT; p += 2) {
		if (p % 3 == 0 || p % 5 == 0) continue;
		if (!sieve[p]) continue;
		for (int j = p * p; j < LIMIT2; j += p) sieve[j] = false;
	}

	long ans = 2 + 3 + 5;
	for (int p = 7; p < LIMIT2; p += 2) {
		if (p % 3 == 0 || p % 5 == 0) continue;
		if (sieve[p]) ans += p;
	}
	std::cout << "The sum of all primes under 2000000 is: " << ans << '\n';
	return ans;
}

int main()
{
	return benchmark(10000, sieve_of_eratosthenes_total) ? 0 : 1;
}
