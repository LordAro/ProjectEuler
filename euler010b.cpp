#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>

int main()
{
	const uint64_t NUM_ITERATE = 1000;
	double timecount = 0;
	for (uint64_t count = 0; count < NUM_ITERATE; count++) {
		/* Timer Start */
		auto t1 = std::chrono::high_resolution_clock::now();

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

		/* Timer End */
		auto t2 = std::chrono::high_resolution_clock::now();

		std::cout << "Sum of primes: " << sum << std::endl;

		auto time_span = std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(t2 - t1);
		timecount += time_span.count();
	}
	std::cout << "Average time taken: " << timecount / NUM_ITERATE << "ms" << std::endl;
}
