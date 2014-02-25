#include <cmath>
#include <iostream>

bool IsPentagonal(int num)
{
	double res = (1 + std::sqrt((24 * num) + 1)) / 6;
	return std::floor(res) == res;
}

int main()
{
	for (int i = 1; i < 5000; i++) {
		int pent_i = (i * ((3 * i) - 1)) / 2;
		for (int j = i; j < 5000; j++) {
			int pent_j = (j * ((3 * j) - 1)) / 2;

			int ij_diff = pent_j - pent_i;

			if (!IsPentagonal(ij_diff)) continue;

			int ij = pent_i + pent_j;
			if (!IsPentagonal(ij)) continue;


			std::cout << "Pair of pentagonal numbers found: " << pent_i << ", " << pent_j << " : Difference: " << ij_diff << std::endl;
			return 0;
		}
	}
}
