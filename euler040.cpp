#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::string s = ".";
	for (int i = 1; s.length() <= 1000000; i++) {
		s += std::to_string(i);
	}

	std::vector<int> nums;
	for (int i = 1; i <= 1000000; i *= 10) {
		nums.push_back(s[i] - '0');
	}
	std::cout << "Total: " << std::accumulate(nums.begin(), nums.end(), 1, [](int x, int y){ return x * y; }) << std::endl;
}
