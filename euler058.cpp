#include <iostream>
#include <vector>

#include "prime.hpp"

int Sqrt(int num)
{
	for (int i = 1; i * i <= num; i += 2) {
		if (i * i == num) return i;
	}
	return -1; // Wat
}

std::vector<int> GenSpiralSquare(const std::vector<int> &old_nums, int len)
{
	std::vector<int> nums(old_nums);
	int last = nums[nums.size() - 1];
	int old_len = ((Sqrt(last) - 1) / 2);
	int inc = (old_len + 1) * 2;

	for (int i = last + inc, j = 0; j < 4; i += inc, j++) {
		nums.push_back(i);
	}
	return nums;
}

std::vector<int> GetPrimes(const std::vector<int> &old_primes, const std::vector<int> &num_list)
{
	std::vector<int> prime_list(old_primes);
	for (const auto &num : num_list) {
		if (old_primes.size() > 0 && num <= old_primes[old_primes.size() - 1]) continue;
		if (IsPrime(num)) prime_list.push_back(num);
	}
	return prime_list;
}

int main()
{
	std::vector<int> nums = {1};
	std::vector<int> primes;
	for (int i = 1; ; i++) {
		nums = GenSpiralSquare(nums, i);
		primes = GetPrimes(primes, nums);
		auto ratio = (float)primes.size() / nums.size();
		std::cout << i << ":" << ratio << "\n";
		if (ratio < 0.1) {
			std::cout << "Square spiral length: " << 2*i+1 << "\n";
			break;
		}
	}
	return 0;
}
