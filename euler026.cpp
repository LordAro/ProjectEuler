#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::string LongDivision(int numer, int denom)
{
	std::string s = "0.";
	std::vector<int> numers;
	while (numer != 0) {
		while (numer < denom) numer *= 10;
		auto pos = std::find(std::begin(numers), std::end(numers), numer);
		if (pos != numers.end()) {
			s.insert(std::distance(std::begin(numers), pos) + 2, "(");
			s += ')';
			break;
		}
		numers.push_back(numer);
		s += std::to_string(numer / denom);
		numer = numer % denom;
	}
	return s;
}

int main()
{
	std::string final_repeat = "";
	int final_d = 0;
	for (int d = 1; d < 1000; d++) {
		std::string repeat = LongDivision(1, d);
		if (repeat.length() > final_repeat.length()) {
			final_repeat = repeat;
			final_d = d;
		}
	}
	std::cout << "Longest repeating decimal is 1/" << final_d << " with: " << final_repeat << std::endl;
}
