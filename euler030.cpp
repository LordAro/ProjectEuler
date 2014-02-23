#include <iostream>
#include <cmath>

int main()
{
	int sum = 0;
	/* Arbitrary limit */
	for (int i = 2; i < 1000000; i++) {
		int local_sum = 0;
		int value = i;
		while (value > 0) {
			int digit = value % 10;

			local_sum += std::pow(digit, 5);

			value /= 10;
		}
		if (local_sum == i) {
			std::cout << i << " is a digit fifth power" << std::endl;
			sum += i;
		}
	}
	std::cout << "Sum of digit fifth powers: " << sum << std::endl;
}
