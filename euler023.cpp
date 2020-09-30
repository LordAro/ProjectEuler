#include <algorithm>
#include <iostream>
#include <vector>

bool isAbundant(int num)
{
	int sum = 0;
	for (int i = 1; i < num; i++) {
		if (num % i == 0) {
			sum += i;
		}
	}
	return sum > num;
}

int main()
{
	/* Get abundant numbers */
	std::vector<int> abundants;
	std::vector<bool> nums;
	nums.reserve(28124);
	for (int i = 0; i <= 28123; i++) {
		if (isAbundant(i)) {
			abundants.push_back(i);
			nums[i] = true;
		} else {
			nums[i] = false;
		}
	}

	int total = 0;
	for (int i = 1; i <= 28123; i++) {
		bool sumfound = false;
		for (auto abun = abundants.begin(); abun != abundants.end() && !sumfound; ++abun) {
			if (*abun > i) break;

			/* Sneaky shenanigans */
			if (nums[i - *abun]) sumfound = true;
		}
		if (!sumfound) {
			//std::cout << i << " - no sum found!" << std::endl;
			total += i;
		}
	}
	std::cout << "Sum of non-abundant numbers: " << total << std::endl;
}
