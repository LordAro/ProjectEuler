CXX=clang++
CXX_FLAGS=-g -Wall -Wextra -pedantic -std=c++14


%:
	${CXX} -o builds/euler$@ ${CXX_FLAGS} euler$@.cpp
	./builds/euler$@


# Special cases
013 015 016 020 025 029 048 053 055 056 057:
	${CXX} -o builds/euler$@ ${CXX_FLAGS} euler$@.cpp -lgmpxx -lgmp
	./builds/euler$@

004b:
	g++ -o builds/euler$@ -Ofast -std=c++14 euler$@.cpp
	./builds/euler$@
