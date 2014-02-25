#include <cmath>
#include <iostream>

bool IsPentagonal(long num)
{
	double res = (1 + std::sqrt((24 * num) + 1)) / 6;
	return std::floor(res) == res;
}

bool IsHexagonal(long num)
{
	double res = (1 + std::sqrt((8 * num) + 1)) / 4;
	return std::floor(res) == res;
}

int main()
{
	int count = 0;
	for (long i = 1; ; i++) {
		long tri_num = i * (i + 1) / 2;
		if (!IsPentagonal(tri_num) || !IsHexagonal(tri_num)) continue;

		std::cout << i << ":" << tri_num << " is a triangular, pentagonal and hexagonal number" << std::endl;
		if (count > 1) {
			return 0;
		}
		count++;
	}
}
