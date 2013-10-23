#include <iostream>

int main()
{
	int anssteps = 0;
	int maxnum = 0;
	for (int count = 1; count < 1000000; count++) {
		int steps = 1;
		for (long i = count; i != 1; steps++) {
			if (i % 2 == 0) i /= 2;
			else i = (3 * i) + 1;
		}

		if (steps > anssteps) {
			anssteps = steps;
			maxnum = count;
		}
	}
	std::cout << "Maximum number of steps: " << anssteps
	          << " for " << maxnum << std::endl;
}
