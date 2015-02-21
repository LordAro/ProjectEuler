#include <algorithm>
#include <iostream>

int main()
{
	for (int x1 = 10; ; x1++) {
		int passed = true;
		std::string x1_str = std::to_string(x1);
		for (int i = 2; i <= 6; i++) {
			std::string mult = std::to_string(x1 * i);
			if (x1_str.length() != mult.length() ||
					!std::is_permutation(x1_str.begin(), x1_str.end(), mult.begin())) {
				passed = false;
				break;
			}
		}
		if (passed) {
			std::cout << x1 << std::endl;
			return 0;
		}
	}
}
