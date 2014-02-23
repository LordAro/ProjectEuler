#include <iostream>

long factorial(int num) {
	long result = 1;
	for(int i = 2; i <= num; i++) {
		result *= i;
	}
	return result;
}

int main()
{
	int total_sum = 0;
	for (int i = 10; i < 100000; i++) {
		int value = i;
		long sum = 0;
		while (value > 0) {
			int digit = value % 10;

			sum += factorial(digit);
			value /= 10;
		}
		if (sum == i) total_sum += i;
	}

	std::cout << "Sum of digit factorials: " << total_sum << std::endl;
}
