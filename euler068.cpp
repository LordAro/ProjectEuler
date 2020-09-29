#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>

/* Order of these is important!
 * There must be a way of generating these, but IDK */
static const std::vector<std::array<int, 3>> indices {
	{5, 4, 3},
	{9, 3, 2},
	{8, 2, 1},
	{7, 1, 0},
	{6, 0, 4},
//	{3, 2, 1},
//	{5, 1, 0},
//	{4, 0, 2},
};

std::string to_string(const std::vector<int> &digits)
{
	std::vector<std::array<int, 3>> arms;
	for (const auto &ixs : indices) {
		arms.push_back({
			digits[ixs[0]],
			digits[ixs[1]],
			digits[ixs[2]],
		});
	}
	int min = *std::min_element(digits.begin() + indices.size(), digits.end()); // outer arms
	while (arms[0][0] != min) {
		std::rotate(arms.begin(), arms.begin() + 1, arms.end());
	}
	// Wheeee
	return std::accumulate(
		arms.begin(), arms.end(), std::string(),
		[](std::string acc, std::array<int, 3> a) {
			return acc + std::accumulate(
				a.begin(), a.end(), std::string(),
				[](std::string acc, int b){ return acc + std::to_string(b); }
			);
		});
}

int main()
{
	std::set<std::string> digit_strings;
	std::vector<int> digits(indices.size() * 2); // Inside and outside rings
	std::iota(digits.begin(), digits.end(), 1);
	/* Ends up doing the work approximately N times, but eh. */
	do {
		std::vector<int> arm_totals;
		for (const auto &ixs : indices) {
			arm_totals.push_back(std::accumulate(ixs.begin(), ixs.end(), 0,
			                               [&digits](int acc, int a){ return acc + digits[a]; }));
		}
		if (std::equal(arm_totals.begin() + 1, arm_totals.end(), arm_totals.begin())) {
			std::string digit_str = to_string(digits);
			digit_strings.insert(digit_str);
		}
	} while (std::next_permutation(digits.begin(), digits.end()));

	std::cout << "Maximum 16-digit string for magic 5-gon: " << *digit_strings.rbegin() << '\n';
}
