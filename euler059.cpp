#include <iostream>
#include <fstream>
#include <algorithm>

std::string xor_str(std::string str, const std::string &key)
{
	for (size_t i = 0; i < str.length(); i++) {
		str[i] ^= key[i % key.length()];
	}
	return str;
}

bool is_printable(const std::string &str)
{
	return std::all_of(str.begin(), str.end(), ::isprint);
}

std::string find_key(const std::string &cipher)
{
	for (char a = 'a'; a <= 'z'; a++) {
		for (char b = 'a'; b <= 'z'; b++) {
			for (char c = 'a'; c <= 'z'; c++) {
				std::string s(1, a); s += b; s += c;
				std::string xord = xor_str(cipher, s);
				if (!is_printable(xord)) continue;
				// Some common words
				if (xord.find("the") != std::string::npos &&
						xord.find("in") != std::string::npos &&
						xord.find("of") != std::string::npos &&
						xord.find("and") != std::string::npos) {
					return xord;
				}
			}
		}
	}
	return "";
}

int main()
{
	std::ifstream cipher_file("assets/p059_cipher.txt");
	std::string num;
	std::string cipher;
	while (std::getline(cipher_file, num, ',')) {
		cipher += (char)std::stoi(num);
	}

	std::string decrypted = find_key(cipher);
	int sum = std::accumulate(decrypted.begin(), decrypted.end(), 0);
	std::cout << "Sum of ASCII values of decrypted text: " << sum << "\n";
	return 0;
}
