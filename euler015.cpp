#include <iostream>
#include <gmpxx.h>

mpz_class factorial(int num)
{
	if (num < 1) return 0;
	mpz_class ans(num);
	for (int i = 2; i < num; i++)
		ans *= i;
	return ans;
}

mpz_class pascaltriangle(int pre, int post)
{
	if (pre < post) return 0;
	mpz_class top = factorial(pre);
	mpz_class bottom = factorial(post) * factorial(pre - post);
	return top / bottom;
}

int main()
{
	int num = 20;
	// Middle number
	std::cout << "Number of routes through a lattice path of 20x20: "
	          << pascaltriangle(num * 2, num) << std::endl;
}
