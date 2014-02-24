#include <iostream>

int main()
{
	for (int i = 1; i < 5000; i++) {
		int pent_i = (i * ((3 * i) - 1)) / 2;
		for (int j = i; j < 5000; j++) {
			int pent_j = (j * ((3 * j) - 1)) / 2;
			std::cout << "Checking " << i << ":" << pent_i << " and " << j << ":" << pent_j << std::endl;

			bool valid = false;
			int ij = pent_i + pent_j;
			for (int k = j; ; k++) {
				int pent_k = (k * ((3 * k) - 1)) / 2;
				if (pent_k > ij) break;

				if (pent_k == ij) {
					valid = true;
					break;
				}
			}
			if (!valid) continue;
			valid = false;

			int ij_diff = pent_j - pent_i;

			for (int k = i; ; k++) {
				int pent_k = (k * ((3 * k) - 1)) / 2;
				if (pent_k > ij_diff) break;

				if (pent_k == ij_diff) {
					valid = true;
					break;
				}
			}

			if (!valid) continue;

			std::cout << "Pair of pentagonal numbers found: " << pent_i << ", " << pent_j << " : Difference: " << ij_diff;
			return 0;
		}
	}
}
