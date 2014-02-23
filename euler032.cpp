#include <algorithm>
#include <iostream>
#include <vector>

bool ContainsDigit(int digit, long num)
{
	while (num != 0) {
	    int cur_digit = num % 10;
		num /= 10;
		if (cur_digit == digit) return true;
	}
	return false;
}

int NumDigits(long number)
{
    int digits = 0;
	while (number) {
		number /= 10;
		digits++;
	}
	return digits;
}

int main()
{
	std::vector<int> nums;
	for (int cand = 1; cand < 10000; cand++) {
		if (cand % 10 == 0) continue;
		int num_cand = NumDigits(cand);
		for (int plier = 1; plier < 10000; plier++) {
			if (plier % 10 == 0) continue;
			int num_plier = NumDigits(plier);

			int prod = cand * plier;
			int num_prod = NumDigits(prod);
			if (prod % 10 == 0) continue;
			if (num_cand + num_plier + num_prod != 9) continue;
			bool valid = true;
			for (int dig = 1; dig <= 9; dig++) {
				int has_digit_sum = ContainsDigit(dig, cand);
				has_digit_sum += ContainsDigit(dig, plier);
				has_digit_sum += ContainsDigit(dig, prod);
				if (has_digit_sum != 1) {
					valid = false;
					break;
				}
			}
			if (valid && std::find(std::begin(nums), std::end(nums), prod) == nums.end()) {
				std::cout << cand << " * " << plier << " = " << prod << std::endl;
				nums.push_back(prod);
			}
		}
	}
	std::cout << "Sum of all unique pandigital products: "
	          << std::accumulate(std::begin(nums), std::end(nums), 0) << std::endl;
}
