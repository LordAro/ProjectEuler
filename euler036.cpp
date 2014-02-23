#include <algorithm>
#include <iostream>
#include <string>

std::string DecToBin(int number)
{
	std::string result = "";

    do {
		if ((number & 1) == 0) {
			result += "0";
		} else {
			result += "1";
		}

		number >>= 1;
	} while (number != 0);

	std::reverse(result.begin(), result.end());
	return result;
}

int main()
{
	int sum = 0;
	for (int i = 0; i < 1000000; i++) {
		if (i % 10 == 0 || i % 2 == 0) continue;
		/* Binary string */
		std::string s = DecToBin(i);
		std::string s_r = s;
		std::reverse(s_r.begin(), s_r.end());

		/* Decimal string */
		std::string i_s = std::to_string(i);
		std::string i_s_r = i_s;
		std::reverse(i_s.begin(), i_s.end());
		if (s == s_r && i_s == i_s_r) {
			std::cout << i << " is palindromic in base 2 & 10" << std::endl;
			sum += i;
		}
	}
	std::cout << "Sum of numbers palindromic in base 2 & 10: " << sum << std::endl;
}
