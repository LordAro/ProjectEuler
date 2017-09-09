#include <cmath>
#include <gmp.h>
#include <gmpxx.h>
#include <iostream>
#include <vector>

bool is_square(int num)
{
	for (int i = 1; i * i <= num; i++) {
		if (i * i == num) return true;
	}
	return false;
}


template<class T>
std::pair<T, T> continued_fraction(int S, size_t n)
{
	std::vector<T> coeff(n + 1);
	T m = 0;
	T d = 1;
	coeff[0] = (T)std::sqrt(S);

	for (size_t i = 1; i <= n; i++) {
		m = (d * coeff[i - 1]) - m;
		d = (S - (m * m)) / d;
		coeff[i] = (coeff[0] + m) / d;
	}

	auto frac = std::make_pair((T)1, coeff[n]);
	for (n--; n > 0; n--) {
		T tmp = frac.first + coeff[n] * frac.second;
		frac.first = frac.second;
		frac.second = tmp;
	}
	frac.first += coeff[0] * frac.second;
	return frac;
}

int main()
{
	std::pair<mpz_class, uint64_t> max_x = {0, 0};
	for (uint64_t D = 2; D <= 1000; D++) {
		if (is_square(D)) continue;

		for (size_t i = 1; ; i++) {
			auto frac = continued_fraction<mpz_class>(D, i);
			mpz_class ans = frac.first * frac.first - (D * frac.second * frac.second);
			if (ans == 1) {
				if (frac.first > max_x.first) max_x = {frac.first, D};
				break;
			}
		}
	}
	std::cout << "Maximum minimal solution in x: " << max_x.first << " (D=" << max_x.second << ")\n";
}
