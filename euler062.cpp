#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

std::vector<int> split_digits(uint64_t n)
{
	std::vector<int> digits;
	while (n > 0) {
		digits.emplace_back(n % 10);
		n /= 10;
	}
	return digits;
}

int main()
{
	const int NUMBER_OF_PERMUTATIONS = 5;
	std::vector<uint64_t> cubes;

	for (uint64_t i = 1; i < std::cbrt(UINT64_MAX); i++) {
		uint64_t cube = i * i * i;
		auto is_cube_permutation = [cube](const uint64_t &c) {
			if (std::floor(std::log10(cube)) + 1 != std::floor(std::log10(c)) + 1) return false;
			auto cube_digits = split_digits(cube);
			auto c_digits = split_digits(c);
			return std::is_permutation(cube_digits.begin(), cube_digits.end(), c_digits.begin(), c_digits.end());
		};
		if (std::count_if(cubes.rbegin(), cubes.rend(), is_cube_permutation) == NUMBER_OF_PERMUTATIONS - 1) {
			std::cout << "Smallest cube: " << *std::find_if(cubes.begin(), cubes.end(), is_cube_permutation) << '\n';
			return 0;
		}
		cubes.emplace_back(i * i * i);
	}
}
