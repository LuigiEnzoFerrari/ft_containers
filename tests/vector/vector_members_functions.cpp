#include "tests.hpp"

void testVectorCapacity(UnitTest& unit) {
	ft::vector<string> vec;
	string *names = arraySet();

	unit.assertTrue(vec.empty(), "Expected: True; vec.empty() == 0");
	unit.assertTrue(vec.size() == 0, "Expected: True; vec.size() == 0");
	unit.assertTrue(vec.capacity() == 0, "Expected: True; vec.capacity() == 0");

	vec.reserve(3);
	unit.assertTrue(vec.size() == 0, "Expected: True, reserve(3); vec.size() == 0");
	unit.assertTrue(vec.capacity() == 3, "Expected: True; vec.capacity() == 3");

	vec.resize(6);
	unit.assertFalse(vec.empty(), "Expected: False; vec.empty() != 0");
	unit.assertTrue(vec.size() == 6, "Expected: True, resize(6); vec.size() == 6");
	unit.assertTrue(vec.capacity() == 6, "Expected: True; vec.capacity() == 6");
	delete[] names;
}

void testVectorIterator(UnitTest& unit) {
	string *names = arraySet();
	ft::vector<string> vec(names, names + 5);
	ft::vector<string>::iterator it;

	it = vec.begin();
	unit.assertTrue((*it) == "Luigi", "Expected: Luigi; vec.begin() == Luigi");

	it = vec.end();
	unit.assertTrue((*(it - 1)) == "Gustavo", "Expected: Luigi; vec.end() - 1 == Gustavo");

	ft::vector<string>::reverse_iterator rit;

	rit = vec.rbegin();
	unit.assertTrue((*rit) == "Gustavo", "Expected: Luigi; vec.rbegin() == Gustavo");

	rit = vec.rend();
	unit.assertTrue((*(rit - 1)) == "Luigi", "Expected: Luigi; vec.rend() - 1 == Luigi");

	delete[] names;
}
