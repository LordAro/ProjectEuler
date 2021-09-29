CXX=clang++
CXX_FLAGS=-ggdb3 -Wall -Wextra -pedantic -std=c++17

ALL_SLNS=$(wildcard euler???.cpp)

all:
	@$(MAKE) $(ALL_SLNS:euler%.cpp=%)

%:
	${CXX} -o builds/euler$@ ${CXX_FLAGS} euler$@.cpp
	./builds/euler$@

# Special cases
013 015 016 020 025 029 048 053 055 056 057 063 065 066:
	${CXX} -o builds/euler$@ ${CXX_FLAGS} euler$@.cpp -lgmpxx -lgmp
	./builds/euler$@

004b 008b 010b 010c:
	g++ -o builds/euler$@ -Ofast -std=c++14 euler$@.cpp
	./builds/euler$@
