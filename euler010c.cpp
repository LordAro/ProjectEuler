#include <chrono>
#include <iostream>
#include <vector>

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
	return ans;
}

int main()
{
	const uint64_t NUM_ITERATE = 10000;
	double timecount = 0;
	for (uint64_t count = 0; count < NUM_ITERATE; count++) {
		/* Timer Start */
		auto t1 = std::chrono::high_resolution_clock::now();

	long ans = sieve_of_eratosthenes_total();

		/* Timer End */
		auto t2 = std::chrono::high_resolution_clock::now();


	std::cout << "The sum of all primes under 2000000 is: " << ans << '\n';

		auto time_span = std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(t2 - t1);
		timecount += time_span.count();
	}
	std::cout << "Average time taken: " << timecount / NUM_ITERATE << "ms" << std::endl;
}
