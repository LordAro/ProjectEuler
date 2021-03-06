#include <algorithm>
#include <iostream>
#include <string>

#include "prime.hpp"

int main()
{
	int count = 1;
	for (int i = 1; i < 1000000; i += 2) {
		if (!IsPrime(i)) continue;
		bool valid = true;
		std::string str = std::to_string(i);

		std::string nums = "02468";
		bool found = false;
		for (auto &c : nums) {
			if (str.find(c) != std::string::npos) {
				found = true;
				break;
			}
		}
		if (found) continue;

		std::string rot = str;
		do {
			if (!IsPrime(std::stoi(rot))) {
				valid = false;
				break;
			}
			std::rotate(rot.begin(), rot.begin() + 1, rot.end());
		} while(rot != str);
		if (valid) {
			count++;
			std::cout << i << " is a circular prime" << std::endl;
		}
	}
	std::cout << "There are " << count << " circular primes under 1000000" << std::endl;
}
