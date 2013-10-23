#include <iostream>

int main()
{
	int ans = 0;
	for (int i = 2520;; i += 20) {
		bool pass = true;
		for (int div = 2; div < 20; div++) {
			if (i % div != 0) {
				pass = false;
				break;
			}
		}
		if (pass) {
			ans = i;
			break;
		}
	}
	std::cout << "Smallest number: " << ans << std::endl;
}
