#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> counts(1000 + 1, 0);

	for (int n = 1; n <= 500; n++) {
		for (int m = n + 1; m <= 500; m++) {
			if ((m - n) % 2 != 1) continue;
			int perim = 0;
			int k = 1;
			for (;;k++) {
				perim = 2 * m * k * (m + n);
				if (perim > 1000) break;
				counts[perim]++;
			}
			if (perim > 1000 && k == 1) break;

		}
	}
	auto max = std::max_element(counts.begin(), counts.end());
	std::cout << "Maximum number of pythagorean triples of a triangle of perimeter " << std::distance(counts.begin(), max) << " is " << *max << std::endl;
}

