#include <iostream>
#include <cmath>

int main()
{
	int a = 0;
	int b = 0;
	double c = 0;
	for (a = 1; a < 1000; a++) {
		for (b = 1; b < 1000; b++) {
			c = std::sqrt((a * a) + (b * b));
			if (static_cast<int>(c) == c && a + b + c == 1000 && a < b && b < c) {
				std::cout << "a: " << a << " b: " << b << " c: " << c
				          << " abc: " << static_cast<int>(a * b * c) << std::endl;
				return 0;
			}

		}
	}
}
