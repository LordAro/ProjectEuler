#include <algorithm>
#include <iostream>
#include <vector>

//#include "prime.h"

int GetSmallestFactor(int num)
{
	if (num % 2 == 0) return 2;
	for (int i = 3; i * i <= num; i += 2) {
		if (num % i == 0) return i;
	}
	return num;
}

std::vector<int> GetDistinctFactors(int num)
{
	std::vector<int> facts;
	while (num != 1) {
		int fact = GetSmallestFactor(num);
		auto pos = std::find(facts.begin(), facts.end(), fact);
		if (pos != facts.end()) {
			*pos *= fact;
		} else if (facts.size() != 0 || fact != num) {
			facts.push_back(fact);
		}
		num /= fact;
	}
	return facts;
}

bool IsUnique(std::vector<int> v)
{
	std::sort(v.begin(), v.end());
	for (auto i = v.begin(); i < v.end() - 1; ++i) {
		if (*i == *(i + 1)) return false;
	}
	return true;
}

int main()
{
	for (int i = 1; i < 9999999; i++) {
		std::vector<std::vector<int>> facts_list;
		for (int j = 0; j < 4; j++) {
			facts_list.emplace_back(GetDistinctFactors(i + j));
		}

		std::vector<int> all;
		for (auto facts : facts_list) {
			all.insert(all.end(), facts.begin(), facts.end());
		}
		if (IsUnique(all) && all.size() / 4 >= 4) {
			std::cout << "Distinct factors:" << i << "," << i + 1 << "," << i + 2 << "," << i + 3 << std::endl;
			for (auto facts : facts_list) {
				for (auto i : facts) std::cout << i << ",";
				std::cout << std::endl;
			}
			return 0;
		}
	}
}
