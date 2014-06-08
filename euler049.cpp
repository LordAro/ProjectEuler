#include <algorithm>
#include <iostream>
#include <string>
#include "prime.hpp"

int main()
{
	for (int i = 1001; i < 10000; i += 2) {
		if (!IsPrime(i)) continue;
		for (int j = 2; j < 5000; j += 2) {
			int i2 = i + j;
			int i3 = i + j + j;
			if (!IsPrime(i2) || !IsPrime(i3)) continue;

			std::string i_str = std::to_string(i);
			std::string i2_str = std::to_string(i2);
			if (!std::is_permutation(i_str.begin(), i_str.end(), i2_str.begin())) continue;
			std::string i3_str = std::to_string(i3);
			if (!std::is_permutation(i_str.begin(), i_str.end(), i3_str.begin())) continue;

			std::cout << "Concatenated prime permutations: " << i_str << i2_str << i3_str << std::endl;

		}
	}
}
