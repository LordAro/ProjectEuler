#include <iostream>

int gcd(int a, int b)
{
	while (b != 0) {
		int t = b;
		b = a % b;
		a = t;
	}
	return a;
}


int main()
{
	int numer_prod = 1;
	int denom_prod = 1;
	for (int numer = 10; numer < 100; numer++) {
		for (int denom = numer + 1; denom < 100; denom++) {
			std::string numer_s = std::to_string(numer);
			std::string denom_s = std::to_string(denom);

			for (auto &c : numer_s) {
				if (denom_s.find('0') != std::string::npos || numer_s.find('0') != std::string::npos)
					continue;
				if (denom_s.find(c) == std::string::npos) continue;

				int numer_i = numer_s[numer_s[0] == c ? 1 : 0] - '0';
				int denom_i = denom_s[denom_s[0] == c ? 1 : 0] - '0';

				if ((float)numer / denom == (float)numer_i / denom_i) {
					std::cout << numer << "/" << denom << " == " << numer_i << "/" << denom_i << std::endl;
					numer_prod *= numer_i;
					denom_prod *= denom_i;
				}
			}
		}
	}

	int div = gcd(numer_prod, denom_prod);
	numer_prod /= div;
	denom_prod /= div;
	std::cout << "Final fraction: " << numer_prod << "/" << denom_prod << std::endl;
}
