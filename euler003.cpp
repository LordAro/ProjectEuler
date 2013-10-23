#include <iostream>

int main()
{
	long num = 600851475143;
	for (long i = 1; i * i < num; i++) {
		if (num % i == 0) {
			num /= i;
			i = 1;
		}

	}
	std::cout << "Largest prime factor: " << num << std::endl;
}
