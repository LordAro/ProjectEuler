#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

int main()
{
	std::ifstream nums_file("assets/p067_triangle.txt");
	std::vector<std::vector<int>> nums;
	std::string line;
	while (std::getline(nums_file, line)) {
		std::vector<int> nums_line;
		std::stringstream tmp(line);
		int num;
		while (tmp >> num) nums_line.push_back(num);
		nums.push_back(nums_line);
	}

	for (uint j = nums.size() - 1; j-- > 0; ) {
		for (uint i = 0; i < nums[j].size(); i++) {
			nums[j][i] += std::max(nums[j + 1][i], nums[j + 1][i + 1]);
		}
	}
	std::cout << "Maximum total: " << nums[0][0] << std::endl;
}
