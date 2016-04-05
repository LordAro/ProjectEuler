%:
	clang++ -o builds/euler$@ -g -Wall -std=c++14 euler$@.cpp
	./builds/euler$@


# Special cases
013 015 016 020 025 029 048 053 055 056 057:
	clang++ -o builds/euler$@ -g -Wall -std=c++0x euler$@.cpp -lgmpxx -lgmp
	./builds/euler$@

004b:
	clang++ -o builds/euler$@ -Ofast -std=c++0x euler$@.cpp
	./builds/euler$@
