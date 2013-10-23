#include <iostream>
#include <vector>

int main()
{
	std::vector<int> primes;
	primes.push_back(2);
	for (int i = 3; primes.size() < 10001; i += 2) {
		bool isprime = true;
		for (std::vector<int>::iterator it = primes.begin() ; it != primes.end(); ++it) {
			if (i % *it == 0) {
				isprime = false;
				break;
			}
		}
		if (isprime) primes.push_back(i);
	}
	std::cout << "10001st prime: " << *(primes.end() - 1) << std::endl;
}
