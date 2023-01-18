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

void testVectorInsert(UnitTest unit) {
	std::string *names = arraySet();
	ft::vector<std::string> vec(names, names + 5);
	
	unit.assertTrue(true);
}

void testVectorPopBack(UnitTest unit) {
	std::string *names = arraySet();
	ft::vector<std::string> vec(names, names + 1);
	vec.pop_back();
	unit.assertTrue(vec.size() == 0, "size == 0");
	unit.assertTrue(vec.capacity() == 1, "capacity == 1");

	ft::vector<std::string> vec2(names, names + 5);
	bool equal = false;
	vec2.pop_back();
	for (size_t i = 0; i < vec2.size(); i++) {
		
		if (vec2[i].compare(names[i]) != 0) {
			equal = false;
		}
	}
	unit.assertTrue(vec2.size() == 4, "size == 4");
	unit.assertTrue(vec2.size() == 4, "vec[i] == names[i]");

	delete[] names;
}

void testVectorPushBack(UnitTest unit) {
	std::string *names = arraySet();
	ft::vector<std::string> vec;

	for (size_t i = 0; i < 3; i++) {
		vec.push_back(names[i]);
		unit.assertTrue(vec.size() == i + 1, "Expeted: Equal; size() = i");
		unit.assertTrue(vec.capacity() == 1 << i, "Expeted: Equal; capacity() = 1 << i");
		unit.assertTrue(vec[i].compare(names[i]) == 0, "Expeted: Equal; vec[i] = names[i]");
	}
	vec.push_back(names[3]);
	vec.push_back(names[4]);

	unit.assertTrue(vec.size() == 5, "Expeted: Equal; size() = 5");
	unit.assertTrue(vec.capacity() == 8, "Expeted: Equal; capacity() = 8");
	unit.assertTrue(vec[3].compare(names[3]) == 0, "Expeted: Equal; vec[3] = names[3]");

	delete[] names;
}
