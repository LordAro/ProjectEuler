#include <algorithm>
#include <cmath>
#include <iostream>
#include <tuple>
#include <vector>

template<class T>
std::vector<T> continued_fraction_coeffs(int S)
{
	std::vector<std::tuple<T, T, T>> coeff;
	T m = 0;
	T d = 1;
	coeff.push_back(std::make_tuple((T)std::sqrt(S), 0, 0));

	for (size_t i = 1; ; i++) {
		m = (d * std::get<0>(coeff[i - 1])) - m;
		d = (S - (m * m)) / d;
		if (d == 0) break; // perfect square
		size_t c = (std::get<0>(coeff[0]) + m) / d;
		std::tuple<T, T, T> tup = std::make_tuple(c, m, d);
		if (std::find(coeff.begin() + 1, coeff.end(), tup) != coeff.end()) break;
		coeff.push_back(tup);
	}
	std::vector<T> out;
	for (const auto &t : coeff) out.push_back(std::get<0>(t));
	return out;
}

int main()
{
	int count = 0;
	const int N = 10000;
	for (int root = 2; root <= N; root++) {
		auto frac = continued_fraction_coeffs<uint64_t>(root);
		if (frac.size() == 1) continue;
		if ((frac.size() - 1) % 2 == 1) count++;
	}
	std::cout << "Number of odd period continued fractions: " << count << '\n';
}
