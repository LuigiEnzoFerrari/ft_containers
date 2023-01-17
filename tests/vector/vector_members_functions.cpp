#include "tests.hpp"

static std::string *arraySet( void ) {
	std::string *names = new std::string[5];
	names[0] = "Luigi";
	names[1] = "Caio";
	names[2] = "Rafa";
	names[3] = "Adrian";
	names[4] = "Gustavo";
	return (names);
}

void testVectorIterator(UnitTest unit) {
	std::string *names = arraySet();
	ft::vector<std::string> vec(names, names + 5);
	ft::vector<std::string>::iterator it;

	it = vec.begin();
	unit.assertTrue((*it) == "Luigi", "Expected: Luigi; vec.begin() == Luigi");

	it = vec.end();
	unit.assertTrue((*(it-1)) == "Gustavo", "Expected: Luigi; vec.end() - 1 == Gustavo");

	ft::vector<std::string>::reverse_iterator rit;

	rit = vec.rbegin();
	unit.assertTrue((*rit) == "Gustavo", "Expected: Luigi; vec.rbegin() == Gustavo");

	rit = vec.rend();
	unit.assertTrue((*(rit - 1)) == "Luigi", "Expected: Luigi; vec.rend() - 1 == Luigi");

	delete[] names;
}
