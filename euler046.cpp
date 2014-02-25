#include <iostream>

#include "prime.hpp"

int main()
{
	for (int i = 9; ; i += 2) {
		if (IsPrime(i)) continue;

		bool valid = false;
		for (int j = 1; j < i; j++) {

			if (IsPrime(i - (2 * j * j))) {
				valid = true;
				break;
			}
		}
		if (!valid) {
			std::cout << "Smallest number disproving Goldbach's other conjecture: " << i << std::endl;
			return 0;
		}
	}
}
