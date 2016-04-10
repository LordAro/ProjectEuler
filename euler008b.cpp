#include <iostream>
#include <fstream>
#include <chrono>

static const size_t NUM_DIGITS = 13;

int main()
{
	std::string s;
	std::ifstream num_file("assets/p008_number.txt");
	std::string tmp;
	while (num_file >> tmp) s += tmp;

	const uint64_t NUM_ITERATE = 100000;
	double timecount = 0;
	for (uint64_t count = 0; count < NUM_ITERATE; count++) {
		/* Timer Start */
		auto t1 = std::chrono::high_resolution_clock::now();

		uint64_t largeprod = 0;
		for (size_t i = 0; i < s.length() - (NUM_DIGITS - 1); i++) {
			uint64_t prod = 1;
			for (size_t j = i; j < i + NUM_DIGITS; j++) {
				prod *= s[j] - '0';
			}

			largeprod = std::max(largeprod, prod);
		}

		/* Timer End */
		auto t2 = std::chrono::high_resolution_clock::now();

		std::cout << "Largest product of " << NUM_DIGITS << " digits: " << largeprod << std::endl;

		auto time_span = std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(t2 - t1);
		timecount += time_span.count();
	}
	std::cout << "Average time taken: " << timecount / NUM_ITERATE << "ms" << std::endl;
}
