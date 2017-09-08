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

bool is_compatible(int a, int b)
{
	return a % 100 == b / 100;
}

std::vector<std::pair<int, int>> find_compatibles(int num, std::vector<std::vector<int>> lists)
{
	std::vector<std::pair<int, int>> out;
	int idx = 0;
	for (const auto &l : lists) {
		for (const auto &n : l) {
			if (n % 100 < 10) continue;
			if (is_compatible(num, n)) out.push_back({idx, n});
		}
		idx++;
	}
	return out;
}

std::vector<int> get_cycle(std::vector<int> found, const std::vector<std::vector<int>> &lists)
{
	auto compats = find_compatibles(found.back(), lists);
	for (const auto &p : compats) {
		std::vector<int> new_found = found;
		new_found.push_back(p.second);
		std::vector<std::vector<int>> new_lists = lists;
		new_lists.erase(new_lists.begin() + p.first);
		auto result = get_cycle(new_found, new_lists);
		if (result.size() == 6 && is_compatible(result.back(), result.front())) return result;
	}
	return found;
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

	for (const auto &n : triangles) {
		std::vector<int> result = get_cycle({n}, {squares, pentagons, hexagons, heptagons, octagons});
		if (result.size() == 6) {
			for (const auto &i : result) std::cout << i << ' ';
			std::cout << ": " << std::accumulate(result.begin(), result.end(), 0) << '\n';
			return 0;
		}
	}
	return 1;
}

