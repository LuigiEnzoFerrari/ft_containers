#include "tests.hpp"
void testeEqual(UnitTest& unit) {
	string *names = arraySet();
	{
		std::vector<string> vec(names, names + 5);
		unit.assertTrue(ft::equal(vec.begin(), vec.end(), names));
	}
	{
		std::vector<string> vec(names, names + 3);
		unit.assertTrue(!ft::equal(names, names + 4, vec.begin()));
	}
	delete[] names;
}

void vector_not_member_functions(UnitTest& unit) {
	testeEqual(unit);
}
