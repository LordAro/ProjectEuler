#include <iostream>
#include <chrono>

int main()
{
	const uint64_t NUM_ITERATE = 10000;
	double timecount = 0;
	for (uint64_t count = 0; count < NUM_ITERATE; count++) {

		/* Timer Start */
		auto t1 = std::chrono::high_resolution_clock::now();
		uint64_t ans = 0;
		uint64_t bigi, bigj, bigk, bigl;
		for (uint64_t i = 99; i > 10; i--) {
			for (uint64_t j = i; j > 10; j--) {
				uint64_t ij = i * j;
				if (ij % 10 == 0) continue;

				for (uint64_t k = j; k > 10; k--) {
					uint64_t ijk = ij * k;
					if (ijk % 10 == 0) continue;

					for (uint64_t l = k; l > 10; l--) {
						uint64_t num = ijk * l;

						if (num % 10 == 0) continue;
						if (num <= ans) break;

						/* Is palindrome? */
						uint64_t rev = 0;
						for (uint64_t tmp = num; tmp; tmp /= 10) {
							rev *= 10;
							rev += tmp % 10;
						}

						if (rev != num) continue;
						ans = num;
						bigi = i;
						bigj = j;
						bigk = k;
						bigl = l;
					}
				}
			}
		}

		/* Timer End */
		auto t2 = std::chrono::high_resolution_clock::now();

		std::cout << "Largest palindromic number: " << ans << '\n';
		std::cout << "Numbers: " << bigi << ", " << bigj << ", " << bigk << ", " << bigl << '\n';

		auto time_span = std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(t2 - t1);
		timecount += time_span.count();
	}

	std::cout << "Average time taken: " << timecount / NUM_ITERATE << "ms" << std::endl;
	return 0;
}
