#include <iostream>

bool ContainsDigit(int digit, long num)
{
	/* Handle leading zeros */
	if (num < 1000000000 && digit == 0) return true;
	while (num != 0) {
	    int cur_digit = num % 10;
		num /= 10;
		if (cur_digit == digit) return true;
	}
	return false;
}

int main()
{
	long num = -1;
	int count = 362880 * 2;
	/* Only need to search between 2*10^9 and 3*10^9
	 * Explanation: Each 10^9 'block' always contains 9! permutations each.	*/
	for (long i = 2000000000; i <= 3000000000; i++) {
		bool valid = true;
		for (int j = 0; j <= 9; j++) {
			valid = valid && ContainsDigit(j, i);
		}
		if (valid) {
			count++;
			std::cout << i << " is valid permutation (" << count << ")" << std::endl;
			if (count == 1000000) {
				num = i;
				break;
			}
		}
	}
	std::cout << "Millionth lexiographic permutation: " << num << std::endl;
}
