#include <iostream>

int main()
{
	for (int i = 1;; i++) {
		/* Generate triangle number */
		int trinum = 0;
		for (int j = 1; j <= i; j++) {
			trinum += j;
		}

		/* Get number of factors */
		int numfactors = 0;
		for (int j = 1; j * j < trinum; j++) {
			if (trinum % j == 0) numfactors += 2;
		}

		if (numfactors > 100) std::cout << trinum << ":" << numfactors << std::endl;
		if (numfactors > 500) {
			std::cout << "The triangle number: " << trinum
			          << " has " << numfactors << " factors" << std::endl;
			return 0;
		}
	}
}
