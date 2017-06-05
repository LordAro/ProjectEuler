#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>

int concat(int p, int q)
{
	int digits = std::floor(std::log10(q)) + 1;
	return p * std::pow(10, digits) + q;
}

static const int SEARCH_LIMIT = 10000;
static const int PRIME_LIMIT = SEARCH_LIMIT * SEARCH_LIMIT;
std::vector<int> primes;

template<typename It>
bool seq_all_primes(It begin, It end)
{
	std::vector<int> concats;
	for (auto p = begin; p != end; ++p) {
		for (auto q = begin; q != end; ++q) {
			if (p == q) continue;
			int c = concat(*p, *q);
			if (!std::binary_search(primes.begin(), primes.end(), c)) return false;
		}
	}
	return true;
}

std::vector<int> sieve_of_eratosthenes()
{
	std::vector<bool> sieve(PRIME_LIMIT, true);
	for (int p = 7; p < SEARCH_LIMIT; p += 2) {
		if (p % 3 == 0 || p % 5 == 0) continue;
		if (!sieve[p]) continue;
		for (int j = p * p; j < PRIME_LIMIT; j += p) sieve[j] = false;
	}

	std::vector<int> primes = {3, 5}; // 2 unnecessary
	for (int p = 7; p < PRIME_LIMIT; p += 2) {
		if (p % 3 == 0 || p % 5 == 0) continue;
		if (sieve[p]) primes.push_back(p);
	}
	return primes;
}

int main()
{
	primes = sieve_of_eratosthenes();
	auto search_end = std::find_if(primes.begin(), primes.end(), [](int i){ return i > SEARCH_LIMIT; });

	// Ew.
	for (auto p1 = primes.begin(); p1 != search_end; ++p1) {
		for (auto p2 = p1 + 1; p2 != search_end; ++p2) {
			auto s = {*p1, *p2};
			if (!seq_all_primes(s.begin(), s.end())) continue;

			for (auto p3 = p2 + 1; p3 != search_end; ++p3) {
				auto s = {*p1, *p2, *p3};
				if (!seq_all_primes(s.begin(), s.end())) continue;

				for (auto p4 = p3 + 1; p4 != search_end; ++p4) {
					auto s = {*p1, *p2, *p3, *p4};
					if (!seq_all_primes(s.begin(), s.end())) continue;

					for (auto p5 = p4 + 1; p5 != search_end; ++p5) {
						auto s = {*p1, *p2, *p3, *p4, *p5};
						if (!seq_all_primes(s.begin(), s.end())) continue;

						std::cout << "Prime list: " << *p1 << ", " << *p2 << ", " << *p3 << ", " << *p4 << ", " << *p5
							<< " Sum: " << std::accumulate(s.begin(), s.end(), 0) << '\n';
					}
				}
			}
		}
	}
}
