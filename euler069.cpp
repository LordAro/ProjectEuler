#include <array>
#include <iostream>

static const int N_MAX = 1'000'000;

int main()
{
	// totient function sieve
	std::array<uint64_t, N_MAX + 1> phi = {};
	for (int i = 2; i <= N_MAX; i++) {
		if (phi[i] == 0) {
			phi[i] = i - 1; // prime default case
			for (int j = i * 2; j <= N_MAX; j += i) {
				if (phi[j] == 0) phi[j] = j;
				phi[j] = phi[j] * (i - 1) / i;
			}
		}
	}

	int max_n = 0;
	float max_divisor_n = 0;

	for (int n = 2; n <= N_MAX; n++) {
		float divisor = (float)n / phi[n];
		if (divisor > max_divisor_n) {
			max_divisor_n = divisor;
			max_n = n;
		}
	}
	std::cout << "Max n for n/totient(n) = " << max_n << '\n';
}
