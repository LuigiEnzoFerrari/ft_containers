#include "tests.hpp"

void testConstructors(UnitTest& unit) {
	std::string *names = arraySet();
	{
		ft::vector<std::string> vec;

		unit.assertTrue(vec.size() == 0, "size == 0");
		unit.assertTrue(vec.capacity() == 0, "size == 0");
	}
	{
		ft::vector<std::string> vec(3, names[1]);
		bool equal = true;
		for (size_t i = 0; i < vec.size(); i++) {if(vec[i] != "Caio") { equal = false;}}
		unit.assertTrue(equal, "vec[i] == Caio");
		unit.assertTrue(vec.size() == 3, "size == 3");
		unit.assertTrue(vec.capacity() == 3, "capacity == 3");
	}
	{
		ft::vector<std::string> vec(names + 2, names + 4);
		unit.assertTrue(vec[0] == "Rafa", "vec[0] == Rafa");
		unit.assertTrue(vec[1] == "Adrian", "vec[1] == Adrian");
		unit.assertTrue(vec.size() == 2, "size == 2");
		unit.assertTrue(vec.capacity() == 2, "capacity == 2");
	}
	{
		ft::vector<std::string> vec(names + 1, names + 5);
		ft::vector<std::string> vec2(vec);
		bool equal = true;
		for (size_t i = 0; i < vec.size(); i++) {if(vec[i] != vec2[i]) { equal = false;}}
		unit.assertTrue(equal, "vec[i] == vec2[i]");
		unit.assertTrue(vec.size() == 4, "size == 4");
		unit.assertTrue(vec.capacity() == 4, "capacity == 4");
	}
}

void vector_constructors(UnitTest& unit) {
	testConstructors(unit);
}
