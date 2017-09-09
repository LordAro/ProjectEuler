#include <cmath>
#include <gmp.h>
#include <gmpxx.h>
#include <iostream>
#include <vector>

template<class T>
std::pair<T, T> continued_fraction(size_t n)
{
	std::vector<T> coeff;
	coeff.push_back(std::floor(M_E));

	for (size_t i = 1; i < n; i++) {
		coeff.push_back(((i + 1) % 3 == 0) ? ((i + 1) / 3 * 2) : 1);
	}

	auto frac = std::make_pair(static_cast<T>(1), coeff[--n]);
	for (n--; n > 0; n--) {
		T tmp = frac.first + coeff[n] * frac.second;
		frac.first = frac.second;
		frac.second = tmp;
	}
	frac.first += coeff[0] * frac.second;
	return frac;
}

size_t digit_sum(mpz_class num)
{
	size_t sum = 0;
	while (num > 0) {
		sum += num.get_si() % 10;
		num /= 10;
	}
	return sum;
}

int main()
{
	const size_t N = 100;
	auto frac = continued_fraction<mpz_class>(N);
	std::cout << frac.first << '/' << frac.second << '\n';
	std::cout << "Numerator digit count: " << digit_sum(frac.first) << '\n';
}
