#include <iostream>
#include <map>

std::map<int, std::string> n2w = {
	{1,    "one"},
	{2,    "two"},
	{3,    "three"},
	{4,    "four"},
	{5,    "five"},
	{6,    "six"},
	{7,    "seven"},
	{8,    "eight"},
	{9,    "nine"},
	{10,   "ten"},
	{11,   "eleven"},
	{12,   "twelve"},
	{13,   "thirteen"},
	{14,   "fourteen"},
	{15,   "fifteen"},
	{16,   "sixteen"},
	{17,   "seventeen"},
	{18,   "eighteen"},
	{19,   "nineteen"},
	{20,   "twenty"},
	{30,   "thirty"},
	{40,   "forty"},
	{50,   "fifty"},
	{60,   "sixty"},
	{70,   "seventy"},
	{80,   "eighty"},
	{90,   "ninety"},
	{100,  "hundred"},
	{1000, "thousand"},
};

std::string num2words(int i)
{
	std::string s = "";
	auto it = n2w.find(i);
	if (it != n2w.end()) {
		if (i == 100 || i == 1000) s.append(n2w.find(1)->second);
		s.append(it->second);
		return s;
	}

	if (i > 100) {
		s.append(n2w.find((i / 100))->second);
		s.append(n2w.find(100)->second);
		if (i % 100 == 0) return s;
		s.append("and");
	}

	int tensandunits = i % 100;
	int units = tensandunits % 10;
	int tendigit = tensandunits / 10;

	it = n2w.find(tensandunits);
	if (it != n2w.end()) {
		s.append(it->second);
		return s;
	}

	it = n2w.find(tendigit * 10);
	if (it != n2w.end()) s.append(it->second);

	it = n2w.find(units);
	if (it != n2w.end()) s.append(it->second);

	return s;
}

int main()
{
	int totallen = 0;
	for (int i = 1; i <= 1000; i++) {
		totallen += num2words(i).length();
	}
	std::cout << "Total length of strings: " << totallen << std::endl;
}
