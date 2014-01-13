%:
	g++ -o builds/euler$@ -g -Wall -std=c++0x euler$@.cpp
	./builds/euler$@


# Special cases
013 015 016:
	g++ -o builds/euler$@ -lgmpxx -lgmp -g -Wall -std=c++0x euler$@.cpp
	./builds/euler$@

004b:
	g++ -o builds/euler$@ -Ofast -std=c++0x euler$@.cpp
	./builds/euler$@
