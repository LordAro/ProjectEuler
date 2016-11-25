#include <numeric>
#include <iostream>
#include <vector>

#include "benchmark.hpp"

long prime_sum()
{
	static const int LIMIT = 2000000;
	std::vector<int> primes(LIMIT);
	std::iota(primes.begin(), primes.end(), 0);
	primes[1] = 0;
	for (int i = 2; i * i < LIMIT; i++) {
		if (primes[i] == 0) continue;
		for (int j = i + i; j < LIMIT; j += i) {
			primes[j] = 0;
		}
	}

	long sum = std::accumulate(primes.begin(), primes.end(), 0l);
	std::cout << "Sum of primes: " << sum << std::endl;
	return sum;
}

int main()
{
	return benchmark(1000, prime_sum) ? 0 : 1;
}
