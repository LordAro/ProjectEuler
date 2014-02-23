#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

bool IsPrime(long n)
{
	if (n < 2) return false;
	if (n % 2 == 0 && n != 2) return false;
	for (int i = 3; i * i < n; i += 2) {
		if (n % i == 0) return false;
	}
	return true;
}

int main()
{
	int best_a = 0;
	int best_b = 0;
	int best_n = 0;
	for (int a = -1000; a <= 1000; a++) {
		for (int b = -1000; b <= 1000; b++) {
			int n = 0;
			for (;; n++) {
				long res = (n * n) + (a * n) + b;
				if (!IsPrime(res)) break;
			}
			if (n > best_n) {
				best_n = n;
				best_a = a;
				best_b = b;
			}
		}
	}
	std::cout << "The equation n*n + " << best_a << "n + " << best_b << " produces " << best_n << " consecutive primes" << std::endl;
	std::cout << "The product of a and b is " << best_a * best_b << std::endl;
}
