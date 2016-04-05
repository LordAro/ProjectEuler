#include <iostream>
#include <cmath>
#include <vector>
#include <gmp.h>
#include <gmpxx.h>

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
	int count = 0;
	for (size_t it = 1; it <= 1000; it++) {
		auto frac = continued_fraction<mpz_class>(2, it);
		if (frac.first.get_str().length() > frac.second.get_str().length()) {
			count++;
		}
	}
	std::cout << "sqrt(2) expansions with larger dnumerator than denominator: " << count << "\n";
	return 0;
}
