#include <iostream>
#include <vector>

std::vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200};

int findCombinationsCount(int amount, uint index)
{
	if (amount == 0) {
		return 1;
	} else if (amount < 0 || coins.size() == index) {
		return 0;
	} else {
		int withFirstCoin = findCombinationsCount(amount - coins[index], index);
		int withoutFirstCoin = findCombinationsCount(amount, index + 1);
		return withFirstCoin + withoutFirstCoin;
	}
}

int main()
{
	std::cout << "Total coin combinations: " << findCombinationsCount(200, 0) << std::endl;
}
