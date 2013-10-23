#include <iostream>
int main()
{
	int ans = 0;
	int num1 = 1;
	int num2 = 2;
	while (num1 < 4000000 || num2 < 4000000) {
		if (num1 % 2 == 0) ans += num1;
		if (num2 % 2 == 0) ans += num2;
		num1 += num2;
		num2 += num1;
	}
	std::cout << "Sum of even fibonacci numbers: " << ans << std::endl;
}
