#include <iostream>
#include <gmp.h>
#include <gmpxx.h>

mpz_class Reverse(mpz_class num)
{
	mpz_class rev = 0;
	for (mpz_class tmp = num; tmp; tmp /= 10) {
		rev *= 10;
		rev += tmp % 10;
	}
	return rev;
}

bool IsPalindrome(mpz_class num)
{
	return num == Reverse(num);
}

bool IsLychrel(mpz_class num)
{
	static const int LIMIT = 50;

	num += Reverse(num);
	for (int i = 1; i < LIMIT; i++) {
		if (IsPalindrome(num)) return true;
		num += Reverse(num);
	}
	return false;
}

int main()
{
	int count = 0;
	for (mpz_class num = 1; num < 10000; num++) {
		if (!IsLychrel(num)) count++;
	}
	std::cout << "Number of Lychrel numbers: " << count << std::endl;
}
