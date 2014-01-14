#include <iostream>

int d(int n)
{
	int sum = 1;
	for (int i = 2; i * i < n; i++) {
		if (n % i == 0) {
			sum += i + n / i;
		}
	}
	return sum;
}

int main()
{
	int sum = 0;
	for (int i = 1; i < 10000; i++) {
		int div1 = d(i);
		if (div1 != i && d(div1) == i) {
			std::cout << i << ':' << div1 << std::endl;
			sum += i;
		}
	}
	std::cout << "Sum of amicable numbers: " << sum << std::endl;
}