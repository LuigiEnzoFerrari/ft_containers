#include "tests.hpp"

static void testIterators(UnitTest& unit) {
	ft::pair<string, int> *arr = getCars();
	{
		ft::map<string, int> cars(arr, arr + 3);
		bool equal = false;
		for (ft::map<string, int>::iterator it = cars.begin(); it != cars.end(); it++) {
			equal = true;
		}
		unit.assertTrue(equal, "begin()~end()");
	}
	{
		ft::map<string, int> cars(arr, arr + 3);
		bool equal = false;
		for (ft::map<string,int>::reverse_iterator rit=cars.rbegin(); rit != cars.rend(); rit++) {
			equal = true;
		}
		unit.assertTrue(equal, "rbegin()~rend()");
	}
	delete[] arr;
}

static void testInsertAndRemovew(UnitTest& unit) {
    ft::map<char, int> map;
    ft::map<char, int>::iterator it;

    map.insert(ft::pair<char, int>('a', 100));
    map.insert(ft::pair<char, int>('b', 100));
    map.insert(ft::pair<char, int>('x', 100));
    map.insert(ft::pair<char, int>('z', 100));
    it = map.begin();
    unit.assertTrue(it->first == 'a');
	it++;
    unit.assertTrue(it->first == 'b');
	it++;
    unit.assertTrue(it->first == 'x');
	it++;
    unit.assertTrue(it->first == 'z');
    it = map.begin();
    map.erase(it);
    it = map.begin();
    unit.assertTrue(it->first == 'b');
	it++;
    unit.assertTrue(it->first == 'x');
	it++;
    unit.assertTrue(it->first == 'z');
}

void map_iterators(UnitTest& unit) {
	unit.runTest(testIterators, "testIterators");
	unit.runTest(testInsertAndRemovew, "testInsertAndRemovew");
}
