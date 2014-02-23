#include <iostream>

int main()
{
	int limit = 1001;

	int step = 2;
	int to4 = 0;
	int cur_num = 1;
	int sum = 0;
	while (step != limit + 1) {
		if (to4 == 4) {
			step += 2;
			to4 = 0;
		}
		sum += cur_num;
		cur_num += step;
		to4++;
	}
	std::cout << "Sum of 1001x1001 spiral is " << sum << std::endl;
}
