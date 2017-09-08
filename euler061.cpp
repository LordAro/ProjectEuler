#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int triangle(int n)
{
	return n * (n + 1) / 2;
}

int square(int n)
{
	return n * n;
}

int pentagonal(int n)
{
	return n * (3 * n - 1) / 2;
}

int hexagonal(int n)
{
	return n * (2 * n - 1);
}

int heptagonal(int n)
{
	return n * (5 * n - 3) / 2;
}

int octagonal(int n)
{
	return n * (3 * n - 2);
}

bool form_cycle(int a, int b)
{
	return a % 100 == b / 100;
}

int main()
{
	std::vector<int> triangles;
	std::vector<int> squares;
	std::vector<int> pentagons;
	std::vector<int> hexagons;
	std::vector<int> heptagons;
	std::vector<int> octagons;
	for (int i = 1; ; i++) {
		int tri = triangle(i);
		if (tri >= 1000 && tri < 10000) triangles.emplace_back(tri);
		int squ = square(i);
		if (squ >= 1000 && squ < 10000) squares.emplace_back(squ);
		int pen = pentagonal(i);
		if (pen >= 1000 && pen < 10000) pentagons.emplace_back(pen);
		int hex = hexagonal(i);
		if (hex >= 1000 && hex < 10000) hexagons.emplace_back(hex);
		int hep = heptagonal(i);
		if (hep >= 1000 && hep < 10000) heptagons.emplace_back(hep);
		int oct = octagonal(i);
		if (oct >= 1000 && oct < 10000) octagons.emplace_back(oct);
		if (tri > 10000 && squ > 10000 && pen > 10000 && hex > 10000 && hep > 10000 && oct > 10000) break;
	}

	std::vector<int> group(6);
	for (auto i : triangles) {
		if (i % 100 < 10) continue;
		if (i % 100 == i / 100) continue;
		for (auto j : squares) {
			if (j % 100 < 10) continue;
			if (j % 100 == j / 100) continue;
			if (form_cycle(j, i) && form_cycle(i, j)) continue;
			for (auto k : pentagons) {
				if (k % 100 < 10) continue;
				if (k % 100 == k / 100) continue;
				if ((form_cycle(i, k) && form_cycle(k, i)) || (form_cycle(j, k) && form_cycle(k, j))) continue;
				for (auto l : hexagons) {
					if (l % 100 < 10) continue;
					if (l % 100 == l / 100) continue;
					if ((form_cycle(i, l) && form_cycle(l, i)) || (form_cycle(j, l) && form_cycle(l, j)) || (form_cycle(k, l) && form_cycle(l, k))) continue;
					for (auto m : heptagons) {
						if (m % 100 < 10) continue;
						if (m % 100 == m / 100) continue;
						if ((form_cycle(i, m) && form_cycle(m, i)) || (form_cycle(j, m) && form_cycle(m, j)) || (form_cycle(k, m) && form_cycle(m, k)) || (form_cycle(l, m) && form_cycle(m, l))) continue;
						for (auto n : octagons) {
							if (n % 100 < 10) continue;
							if (n % 100 == n / 100) continue;
							if ((form_cycle(i, n) && form_cycle(n, i)) || (form_cycle(j, n) && form_cycle(n, j)) || (form_cycle(k, n) && form_cycle(n, k)) || (form_cycle(l, n) && form_cycle(n, l)) || (form_cycle(n, m) && form_cycle(m, n))) continue;
							std::vector<int> group = {i, j, k, l, m, n};
							std::vector<int> group_u = {i / 100, j / 100, k / 100, l / 100, m / 100, n / 100};
							std::vector<int> group_l = {i % 100, j % 100, k % 100, l % 100, m % 100, n % 100};
							if (std::is_permutation(group_u.begin(), group_u.end(), group_l.begin(), group_l.end())) {
									for (const auto &a : group) std::cout << a << ' ';
									std::cout << "Sum: " << std::accumulate(group.begin(), group.end(), 0) << '\n';
									return 0; // Only solution
							}
						}
					}
				}
			}
		}
	}
}
