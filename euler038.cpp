#include <iostream>
#include <string>

int main()
{
	int bignum = 0;
	int bigmult = 0;
	int bigi = 0;
	for (int i = 1; i < 10000; i++) {
		std::string str = "";
		int mult = 1;
		for (; str.length() < 9; mult++) {
			str += std::to_string(i * mult);
		}
		if (str.length() != 9) continue;

		bool valid = true;
		for (int digit = 1; digit <= 9; digit++) {
			std::string digit_s = std::to_string(digit);
			if (str.find(digit_s) == std::string::npos) {
				valid = false;
				break;
			}
		}

		if (!valid) continue;

		int new_big = std::stoi(str);
		if (new_big > bignum) {
			bignum = new_big;
			bigmult = mult - 1;
			bigi = i;
		}
	}
	std::cout << "Biggest pandigital concatenation: " << bignum;
	std::cout << " = " << bigi << " * (";
	for (int i = 1; i <= bigmult; i++) {
		std::cout << i;
		if (i != bigmult) std::cout << ", ";
	}
	std::cout << ")" << std::endl;
}
