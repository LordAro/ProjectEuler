#include <iostream>

int main()
{
	int sum = 0;
	int squaresum = 0;
	for (int i = 1; i <= 100; i++) {
		sum += i;
		squaresum += i * i;
	}
	int sumsquare = sum * sum;
	std::cout << "Sum square difference: " << sumsquare - squaresum << std::endl;
}
