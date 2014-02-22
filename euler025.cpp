#include <iostream>
#include <gmp.h>
#include <gmpxx.h>

int main()
{
	mpz_class fin = 0;
	mpz_class a = 1;
	mpz_class b = 1;
	int count = 1;
	for (;;) {
		if (a.get_str().length() == 1000) {
			fin = a;
			break;
		}
		mpz_class tmp = a;
		a = b;
		b += tmp;
		count++;
	}
	std::cout << "Fibonacci number " << count << ": " << fin << std::endl;
}
