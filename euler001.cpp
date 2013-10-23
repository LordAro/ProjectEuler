#include <iostream>

int main()
{
	int ans = 0;
	for (int i = 3; i < 1000; i++)
		if (i % 3 == 0 || i % 5 == 0) ans += i;
	std::cout<< "Total: " << ans << std::endl;
}
