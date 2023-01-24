#include "tests.hpp"

void testConstructor(UnitTest& unit) {
	std::map<string, int> cars = getCars();
	string *car_names = setCars();
	{
		std::map<string, int> cars2;
		unit.assertTrue(cars2.size() == 0, "size 0");
		unit.assertTrue(cars2.empty(), "empty");
	}
	{
		std::map<string, int> cars2(cars.begin(), cars.end());
		bool equal = true;
		for (size_t i = 0; i < 5; i++) {
			if (cars[car_names[i]] != cars2[car_names[i]]) {
				equal = false;
			}
		}
		unit.assertTrue(equal);
		unit.assertTrue(cars2.size() == 5, "size 5");
		unit.assertFalse(cars2.empty(), "!empty");
	}
	{
		std::map<string, int> cars2(cars);
		bool equal = true;
		for (size_t i = 0; i < 5; i++) {
			if (cars[car_names[i]] != cars2[car_names[i]]) {
				equal = false;
			}
		}
		unit.assertTrue(equal);
		unit.assertTrue(cars2.size() == 5, "size 5");
		unit.assertFalse(cars2.empty(), "!empty");
	}
	delete[] car_names;
}

void map_constructors(UnitTest& unit) {
	unit.runTest(testConstructor, "testConstructor");
}
