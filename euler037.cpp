#include <cmath>
#include <iostream>

bool IsPrime(long num)
{
	if (num < 2) return false;
	if (num != 2 && num % 2 == 0) return false;
	for (int i = 3; i * i <= num; i += 2) {
		if (num % i == 0) return false;
	}
	return true;
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
	long sum = 0;
	for (long i = 11; i < 1000000; i += 2) {
		if (!IsPrime(i)) continue;
		long num = i;
		bool valid = true;
		while (num != 0) {
			if (!IsPrime(num)) {
				valid = false;
				break;
			}
			num /= 10;
		}
		if (!valid) continue;

		num = i;
		while(num != 0) {
			if (!IsPrime(num)) {
				valid = false;
				break;
			}
			num %= (long)std::pow(10, NumDigits(num) - 1);
		}
		if (valid) {
			std::cout << i << " is a truncatable prime" << std::endl;
			sum += i;
		}
	}
	std::cout << "Sum of truncatable primes: " << sum << std::endl;
}
