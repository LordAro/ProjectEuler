#include <iostream>
#include <vector>

int main()
{
	long sum = 2;
	std::vector<long> primes;
	primes.push_back(sum);
	for (long i = 3; i < 2000000; i += 2) {
		bool isprime = true;
		for (auto it = primes.begin(); *it * *it <= i && it != primes.end(); ++it) {
			if (i % *it == 0) {
				isprime = false;
				break;
			}
		}
		if (isprime) {
			primes.push_back(i);
			sum += i;
		}

	}
	std::cout << "Sum of primes: " << sum << std::endl;
}
