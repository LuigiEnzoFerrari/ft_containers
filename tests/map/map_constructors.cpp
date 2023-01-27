#include "tests.hpp"

static void test_red_black(UnitTest& unit) {
	ft::map<int, int> one;
	ft::pair<int, int> arr = ft::make_pair(4, 5);
	one.insert(arr);
	std::cout << one._black.root->_data.second << std::endl;
	std::cout << one._black.root->_data.first << std::endl;
	ft::pair<int, int> arr2 = ft::make_pair(80, 45);
	one.insert(arr2);
	std::cout << "  oo " << std::endl;
	std::cout << one._black.root->_right->_data.second << std::endl;
	std::cout << one._black.root->_right->_data.first << std::endl;
	// unit.assertTrue();
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
