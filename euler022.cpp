#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

int GetWordScore(std::string word)
{
	int sum = 0;
	for (auto c : word) {
		sum += c - 'A' + 1;
	}
	return sum;
}

int main()
{
	std::ifstream names_file("assets/p022_names.txt");
	std::vector<std::string> names;
	std::string name;
	while (std::getline(names_file, name, ',')) {
		names.emplace_back(name.substr(1, name.size() - 2)); // Remove quotes
	}
	std::sort(names.begin(), names.end());

	int total = 0;
	int pos = 1;
	for (const auto &word : names) {
		total += GetWordScore(word) * pos;
		pos++;
	}
	std::cout << "Total list score: " << total << std::endl;
}
