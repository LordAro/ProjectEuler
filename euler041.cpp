#include <algorithm>
#include <iostream>
#include <string>

bool IsPrime(long num)
{
	if (num != 2 && num % 2 == 0) return false;
	for (int i = 3; i * i <= num; i += 2) {
		if (num % i == 0) return false;
	}
	return true;
}

bool IsPandigital(std::string s)
{
	for (char digit = '1'; digit < '1' + (int)s.length(); digit++) {
		if (s.find(digit) == std::string::npos) return false;
	}
	return true;
}

int main()
{
	std::string s = "987654321";
	while (s.length() > 1) {
		bool valid = false;
		do {
			if (IsPrime(std::stoi(s))) {
				valid = true;
				break;
			}
		} while (std::prev_permutation(s.begin(), s.end()));
		if (valid) break;
		std::sort(s.begin(), s.end(), std::greater<char>());
		s = s.substr(1);
	}

	std::cout << "Largest pandigital prime: " << s << std::endl;
}
