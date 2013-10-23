#include <iostream>
#include <sstream>

int main()
{
	int ans = 0;
	for (int i = 999; i > 0; i--) {
		for (int j = 999; j > 0; j--) {
			int num = i * j;
			std::stringstream stream;
			stream << num;
			std::string digits = stream.str();
			int numlength = digits.length();

			bool p = true;
			for (int it = 0; it < numlength / 2 + 1; it++) {
				if (digits[it] != digits[numlength - 1 - it]) {
					p = false;
					break;
				}
			}
			if (p) ans = std::max(ans, num);
		}
	}
	std::cout << "Largest palindromic number: " << ans << std::endl;
}
