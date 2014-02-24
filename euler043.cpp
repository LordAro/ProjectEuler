#include <algorithm>
#include <iostream>
#include <string>

int main()
{
	long sum = 0;
	std::string s = "1023456789";
	do {
		if (std::stol(s.substr(1, 3)) % 2 == 0 &&
			std::stol(s.substr(2, 3)) % 3 == 0 &&
			std::stol(s.substr(3, 3)) % 5 == 0 &&
			std::stol(s.substr(4, 3)) % 7 == 0 &&
			std::stol(s.substr(5, 3)) % 11 == 0 &&
			std::stol(s.substr(6, 3)) % 13 == 0 &&
			std::stol(s.substr(7, 3)) % 17 == 0) sum += std::stol(s);
	} while (std::next_permutation(s.begin(), s.end()));

	std::cout << "Sum of number with divisible substrings: " << sum << std::endl;
}
