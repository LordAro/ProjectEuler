#include <algorithm>
#include <array>
#include <cassert>
#include <fstream>
#include <iostream>
#include <iterator>
#include <set>
#include <tuple>
#include <vector>

enum Rank {
	Highest,
	OnePair,
	TwoPair,
	ThreeOfKind,
	Straight,
	Flush,
	FullHouse,
	FourOfKind,
	StraightFlush,
	RoyalFlush,
};

enum Suit {
	Clubs,
	Diamonds,
	Hearts,
	Spades,
};

typedef std::pair<int, Suit> Card;

std::istream& operator>>(std::istream &is, Card &card)
{
	char value;
	if (is >> value) {
		switch (value) {
			case 'T': card.first = 10; break;
			case 'J': card.first = 11; break;
			case 'Q': card.first = 12; break;
			case 'K': card.first = 13; break;
			case 'A': card.first = 14; break;
			default: card.first = value - '0'; break;
		}
	} else {
		return is;
	}

	char suit;
	if (is >> suit) {
		switch (suit) {
			case 'C': card.second = Clubs; break;
			case 'D': card.second = Diamonds; break;
			case 'H': card.second = Hearts; break;
			case 'S': card.second = Spades; break;
		}
	} else {
		return is;
	}

	return is;
}

std::ostream& operator<<(std::ostream &os, const Card &card)
{
	switch (card.first) {
		default: os << card.first; break;
		case 10: os << 'T'; break;
		case 11: os << 'J'; break;
		case 12: os << 'Q'; break;
		case 13: os << 'K'; break;
		case 14: os << 'A'; break;
	}

	switch (card.second) {
		case Clubs:    os << 'C'; break;
		case Diamonds: os << 'D'; break;
		case Hearts:   os << 'H'; break;
		case Spades:   os << 'S'; break;
	}
	return os;
}

bool operator<(const Card &a, const Card &b)
{
	return a.first < b.first;
}

typedef std::array<Card, 5> Hand;

std::istream& operator>>(std::istream &is, Hand &hand)
{
	for (int i = 0; i < 5; i++) {
		if (!(is >> hand[i])) break;
	}
	std::sort(hand.begin(), hand.end());
	return is;
}

std::ostream& operator<<(std::ostream &os, const Hand &hand)
{
	if (!hand.empty()) {
		std::copy(hand.begin(), hand.end() - 1, std::ostream_iterator<Card>(os, ","));
		os << hand.back();
	}
	return os;
}

template<typename ContainerT>
int CountUniqueSuits(ContainerT h)
{
	std::sort(h.begin(), h.end(), [](const Card &a, const Card &b){return a.second < b.second;});
	auto unique_end = std::unique(h.begin(), h.end(), [](const Card &a, const Card &b){return a.second == b.second;});
	return std::distance(h.begin(), unique_end);
}

bool IsStraight(const Hand &h)
{
	int test_val = h[0].first + 1;
	for (int i = 1; i < 5; i++, test_val++) {
		if (h[i].first != test_val) return false;
	}
	return true;
}

inline bool IsFlush(const Hand &h)
{
	return CountUniqueSuits(h) == 1;
}

bool Is4OfKind(const Hand &h)
{
	bool t1 = h[0].first == h[1].first && h[1].first == h[2].first && h[2].first == h[3].first;
	bool t2 = h[1].first == h[2].first && h[2].first == h[3].first && h[3].first == h[4].first;
	return t1 || t2;
}

bool IsFullHouse(const Hand &h)
{
	bool t1 = h[0].first == h[1].first && h[1].first == h[2].first && h[3].first == h[4].first; // xxxyy
	bool t2 = h[0].first == h[1].first && h[2].first == h[3].first && h[3].first == h[4].first; // yyxxx
	return t1 || t2;
}

bool Is3OfKind(const Hand &h)
{
	if (Is4OfKind(h) || IsFullHouse(h)) return false;

	bool t1 = h[0].first == h[1].first && h[1].first == h[2].first; // xxxab
	bool t2 = h[1].first == h[2].first && h[2].first == h[3].first; // axxxb
	bool t3 = h[2].first == h[3].first && h[3].first == h[4].first; // abxxx

	return t1 || t2 || t3;
}

bool Is2Pairs(const Hand &h)
{
	if (Is3OfKind(h) || IsFullHouse(h) || Is4OfKind(h)) return false;

	bool t1 = h[0].first == h[1].first && h[2].first == h[3].first; // aabbx
	bool t2 = h[0].first == h[1].first && h[3].first == h[4].first; // aaxbb
	bool t3 = h[1].first == h[2].first && h[3].first == h[4].first; // xaabb

	return t1 || t2 || t3;
}

bool IsPair(const Hand &h)
{
	if (Is2Pairs(h) || Is3OfKind(h) || IsFullHouse(h) || Is4OfKind(h)) return false;

	bool t1 = h[0].first == h[1].first;
	bool t2 = h[1].first == h[2].first;
	bool t3 = h[2].first == h[3].first;
	bool t4 = h[3].first == h[4].first;

	return t1 || t2 || t3 || t4;
}

std::pair<Rank, int> GetRank(const Hand &h)
{
	assert(std::is_sorted(h.begin(), h.end()));
	bool straight = IsStraight(h);
	bool flush = IsFlush(h);

	if (h[0].first >= 10 && straight && flush) return {RoyalFlush, h[4].first};
	if (straight && flush) return {StraightFlush, h[4].first};
	if (Is4OfKind(h)) return {FourOfKind, h[2].first};
	if (IsFullHouse(h)) return {FullHouse, h[2].first};
	if (flush) return {Flush, h[4].first};
	if (straight) return {Straight, h[4].first};
	if (Is3OfKind(h)) return {ThreeOfKind, h[2].first};
	if (Is2Pairs(h)) return {TwoPair, h[2].first};
	if (IsPair(h)) {
		int max = 0;
		if (h[0].first == h[1].first) max = h[0].first;
		else if (h[1].first == h[2].first) max = h[1].first;
		else if (h[2].first == h[3].first) max = h[2].first;
		else if (h[3].first == h[4].first) max = h[3].first;
		return {OnePair, max};
	}
	return {Highest, h[4].first};
}

bool operator<(const Hand &a, const Hand &b)
{
	Rank a_rank; int a_high;
	std::tie(a_rank, a_high) = GetRank(a);

	Rank b_rank; int b_high;
	std::tie(b_rank, b_high) = GetRank(b);

	if (a_rank != b_rank) {
		return a_rank < b_rank;
	} else if (a_high != b_high) {
		return a_high < b_high;
	}

	for (size_t i = a.size(); i > 0; i--) {
		if (a[i - 1].first != b[i - 1].first) {
			return a[i - 1].first < b[i - 1].first;
		}
	}
	assert("identical hands");
	return true;
}

int main()
{
	std::ifstream hands_file("assets/p054_poker.txt");
	std::vector<std::pair<Hand, Hand>> hand_pairs;
	std::pair<Hand, Hand> hand_pair;
	for (;;) {
		Hand p1;
		Hand p2;
		if (hands_file >> p1 && hands_file >> p2) {
			hand_pairs.emplace_back(p1, p2);
		} else {
			break;
		}
	}
	int count = 0;
	for (const auto &hp : hand_pairs) {
		if (hp.first > hp.second) count++;
	}
	std::cout << "Player 1 wins " << count << " hands" << std::endl;
}
