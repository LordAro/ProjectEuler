#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	std::vector<int> digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	for (int count = 1; count < 1000000; count++) {
		std::next_permutation(digits.begin(), digits.end());
	}
	std::cout << "Millionth lexicographic permutation: ";
	for (const auto &d : digits) std::cout << d;
	std::cout << '\n';
}
