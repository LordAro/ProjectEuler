#include <iostream>
#include "prime.hpp"

int main()
{
	const int LIMIT = 1000000;
	int bignum = 0;
	uint bignumcount = 0;
	for (int startnum = 2; ; startnum++) {
		if (startnum > LIMIT) break;
		if (!IsPrime(startnum)) continue;
		int sum = 0;
		uint sumcount = 0;
		for (int i = startnum; ; i++) {
			if (!IsPrime(i)) continue;

			sum += i;
			sumcount++;
			if (sum > LIMIT) {
				break;
			} else if (IsPrime(sum) && sumcount > bignumcount) {
				bignum = sum;
				bignumcount = sumcount;
			}
		}
	}
	std::cout << "Prime with most consecutive prime sums: " << bignum << " with " << bignumcount << " sums" << std::endl;
}
