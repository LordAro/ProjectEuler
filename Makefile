%:
	g++ -o builds/euler$@ -g -Wall -std=c++0x euler$@.cpp
	./builds/euler$@


# Special cases
013 015 016 020 025 029 048:
	g++ -o builds/euler$@ -lgmpxx -lgmp -g -Wall -std=c++0x euler$@.cpp
	./builds/euler$@

004b:
	clang++ -o builds/euler$@ -Ofast -std=c++0x euler$@.cpp
	./builds/euler$@
