#include <array>
#include <cassert>
#include <fstream>
#include <iostream>
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

bool operator<(const Card &a, const Card &b)
{
	return a.first < b.first;
};

typedef std::pair<Rank, Card> HandResult;
typedef std::array<Card, 5> Hand;

std::istream& operator>>(std::istream &is, Card &card)
{
	char value = is.get();
	switch (value) {
		case '\n': is.setstate(std::ios_base::eofbit); return is;
		case 'T': card.first = 10; break;
		case 'J': card.first = 11; break;
		case 'Q': card.first = 12; break;
		case 'K': card.first = 13; break;
		case 'A': card.first = 14; break;
		default: card.first = value - '0'; break;
	}

	char suit = is.get();
	std::cout << card.first << suit << std::endl;
	switch (suit) {
		case 'C': card.second = Clubs; break;
		case 'D': card.second = Diamonds; break;
		case 'H': card.second = Hearts; break;
		case 'S': card.second = Spades; break;
		default: assert(false);
	}

	is.get();
	return is;
}

std::istream& operator>>(std::istream &is, Hand &hand)
{
	return is >> hand[0] >> hand[1] >> hand[2] >> hand[3] >> hand[4];
}

std::istream& operator>>(std::istream &is, std::vector<std::pair<Hand, Hand>> &handlist)
{
	std::pair<Hand, Hand> hand_pair;
	while (is.good()) {
		is >> hand_pair.first >> hand_pair.second;
		handlist.push_back(hand_pair);
		std::cout << std::endl;
	}
	return is;
}

HandResult GetHandType(Hand hand)
{
	return {RoyalFlush, {0, Hearts}};
}

int main()
{
	std::ifstream hands_file("assets/p054_poker.txt");
	std::vector<std::pair<Hand, Hand>> hand_pairs;
	hands_file >> hand_pairs;
}
