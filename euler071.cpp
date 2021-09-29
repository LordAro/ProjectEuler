#include <iostream>
#include <vector>

static const int DENOM_MAX = 8;
//static const int DENOM_MAX = 1'000'000;

struct Fraction {
	int n, d;
};

double to_double(int n, int d)
{
	return (double)n / (double)d;
}

/* Iterative as recursive causes stack overflow */
/* This way exhausts all memory, but at least it doesn't crash... right? */
std::vector<Fraction> coprime_pair_gen(Fraction start)
{
	std::vector<Fraction> result;
	result.push_back(start);
	for (size_t idx = 0; idx < result.size(); idx++) {
		const Fraction &f = result[idx];
		const Fraction f1 = {f.d, 2*f.d - f.n};
		const Fraction f2 = {f.d, 2*f.d + f.n};
		const Fraction f3 = {f.n, f.d + 2*f.n};
		if (f1.d <= DENOM_MAX) result.push_back(f1);
		if (f2.d <= DENOM_MAX) result.push_back(f2);
		if (f3.d <= DENOM_MAX) result.push_back(f3);
	}
	return result;
}

int main()
{
	const auto oddeven_pairs = coprime_pair_gen({1, 2});
	const auto oddodd_pairs = coprime_pair_gen({1, 3});

	std::vector<Fraction> coprime_pairs;
	coprime_pairs.insert(coprime_pairs.end(), oddeven_pairs.begin(), oddeven_pairs.end());
	coprime_pairs.insert(coprime_pairs.end(), oddodd_pairs.begin(), oddodd_pairs.end());

//	for (Fraction f : coprime_pairs) std::cout << f.n << '/' << f.d << '\n';

	const double THREE_SEVENTHS = to_double(3, 7);
	int cur_max_n = 0;
	int cur_max_d = 0;
	double cur_max_double = 0;
	for (Fraction f : coprime_pairs) {
		double frac = to_double(f.n, f.d);
		if (frac < THREE_SEVENTHS && frac > cur_max_double) {
			cur_max_double = frac;
			cur_max_n = f.n;
			cur_max_d = f.d;
		}
	}
	std::cout << "Fraction to the left of 3/7: " << cur_max_n << '/' << cur_max_d << '\n';
}
