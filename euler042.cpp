#include <iostream>
#include <string>
#include <vector>
#include <fstream>

int WordToNumCount(std::string word)
{
	int count = 0;
	for (auto c : word) count += c - 'A' + 1;
	return count;
}

bool IsTriangleNum(int num)
{
	/* Arbitrary cutoff */
	for (int n = 1; n < 40; n++) {
		int tri_num = (n * (n + 1)) / 2;
		if (num == tri_num) return true;
	}
	return false;
}

int main()
{
	std::ifstream words_file("assets/p042_words.txt");
	std::vector<std::string> words;
	std::string word;
	while (std::getline(words_file, word, ',')) {
		words.emplace_back(word.substr(1, word.size() - 2)); // Remove quotes
	}

	int count = 0;
	for (auto word : words) {
		if (IsTriangleNum(WordToNumCount(word))) count++;
	}
	std::cout << "There are " << count << " triangle words in words.txt" << std::endl;
}
