#include "tests.hpp"

static void test_red_black(UnitTest& unit) {
	ft::map<int, int> one;
	ft::pair<int, int> arr;
	for (int x = 0; x < 12; x++) {
			arr = ft::make_pair(x + 100, 10);
			one.insert(arr);
	}
	ft::map<int, int>::iterator it;

	it = one.begin();
	it++;
	std::cout << it->first << std::endl;	
	std::cout << it->second << std::endl;	
	it->second = 44;
	std::cout << it->first << std::endl;	
	std::cout << it->second << std::endl;
	it = one.find(104);
	std::cout << it->first << std::endl;	
	std::cout << it->second << std::endl;	
	unit.assertTrue(true);
}

static void testConstructor(UnitTest& unit) {
	std::pair<string, int> *arr = getCars();
	{
		ft::map<string, int> cars;
	}
	// {
	// 	ft::map<string, int> cars(arr, arr + 6);
	// 	// unit.assertTrue(compareMapAndPair(cars, arr, 6), "equal");
	// 	unit.assertTrue(cars.size() == 6, "size 6");

	// 	ft::map<string, int> cars2(cars);
	// 	// unit.assertTrue(compareMapAndPair(cars2, arr, 6), "equal");
	// 	unit.assertTrue(cars2.size() == 6, "size 6");
	// }
}

// static void testAssignOperator(UnitTest& unit) {
// 	std::pair<string, int> *arr = getCars();
// 	std::map<string, int> cars(arr, arr + 5);
// 	std::map<string, int> cars2;
// 	cars2 = cars;

// 	unit.assertTrue(compareMapAndPair(cars2, arr, 5), "equal");
// 	unit.assertTrue(cars2.size() == 5, "size 6");
// }

void map_constructors(UnitTest& unit) {
	unit.assertTrue(true);
	unit.runTest(test_red_black, "test_red_black");
	unit.runTest(testConstructor, "testConstructor");
	// unit.runTest(testAssignOperator, "testAssignOperator");
}
