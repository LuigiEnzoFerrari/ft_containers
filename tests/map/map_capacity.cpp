#include "tests.hpp"
#include <algorithm>
#include <utility>


void testCapacity(UnitTest& unit) {
	std::map<std::string, int> map;
	map["one"] = 1;
	map["two"] = 2;
	map["three"] = 3;
	// std::pair
	unit.assertTrue(map["two"] == 2, "map two");
}

void map_capacity(UnitTest& unit) {
	testCapacity(unit);
}
