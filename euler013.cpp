// Build command: g++ euler012.cpp -g -Wall -lgmp -lgmpxx -std=c++0x -o euler

#include <iostream>
#include <vector>
#include <fstream>
#include <gmp.h>
#include <gmpxx.h>

int main()
{
	std::ifstream nums_file("assets/p013_numbers.txt");
	std::vector<mpz_class> nums;
	std::string num_str;
	while(std::getline(nums_file, num_str)) {
		nums.emplace_back(num_str);
	}
	mpz_class ans = 0;
	for (auto i : nums)
		ans += i;
	std::cout << "Sum: " << ans << std::endl;
}
