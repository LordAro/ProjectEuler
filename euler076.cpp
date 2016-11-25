#include <iostream>
#include <map>

int partition(int N)
{
	static std::map<int, int> cache{};
	if (N < 0) return 0;
	if (N == 0) return 1;
	if (cache.find(N) != cache.end()) return cache[N];

	int c = 0;
	int g0 = 0;
	for (int k0 = 1; N - g0 > 0; k0++) {
		g0 = k0 * (3 * k0 - 1) / 2;
		c += (k0 % 2 == 0 ? -1 : 1) * partition(N - g0);
	}

	int g1 = 0;
	for (int k1 = -1; N - g1 > 0; k1--) {
		g1 = k1 * (3 * k1 - 1) / 2;
		c += (k1 % 2 == 0 ? -1 : 1) * partition(N - g1);
	}

	cache[N] = c;
	return c;
}

int main()
{
	int ans = partition(100) - 1;
	std::cout<< "Number of sums: " << ans << std::endl;
}
