#include <iostream>

constexpr int sum(int n) {
	return n * (n + 1) / 2;
}

constexpr int square(int n) {
	return n * n;
}

constexpr int sumsquare(int n) {
	return n * (n + 1) * (2*n + 1) / 6;
}

template<int N>
struct constN {};

template<int N>
std::ostream &operator<<(std::ostream &os, const constN<N> &) {
	return os << N;
}

int main() {
	std::cout << "Sum square difference: " << constN<square(sum(100)) - sumsquare(100)>() << "\n";
}
