#ifndef STD
	#define STD 0
	#include "stl_vector.hpp"
#else
	#include <vector>
	#include <stack>
	#include <map>
	#include <set>
	namespace ft = std;
#endif

#include "UnitTest.hpp"

void assign2(UnitTest unit) {
	int *p = new int[5];
	ft::vector<int> vec(5, 100);
	ft::vector<int> vec2(5, 100);
	
	unit.assertTrue(vec.size() == 5, "size 5");

	vec.assign(vec2.begin(), vec2.end());

	unit.assertTrue(vec.size() == 5, "size 5");

	size_t i = ft::distance(vec.begin(), vec.end());
	std::cout << i << std::endl;
	delete[] p;
}

void assign(UnitTest unit) {
	int *p = new int[5];
	ft::vector<int> vec(p, p + 5);

	vec.assign(6, 3);
	unit.assertTrue(vec.capacity() == 6, "Capacity 6");
	unit.assertTrue(vec.size() == 6, "Size 6");

	vec.assign(3, 3);
	unit.assertTrue(vec.capacity() == 6, "Capacity 6");
	unit.assertFalse(vec.size() == 6, "Size 6");
	unit.assertTrue(vec.size() == 3, "Size 3");

	vec.assign(0, 3);
	unit.assertTrue(vec.capacity() == 6, "Capacity 6");
	unit.assertTrue(vec.size() == 0, "Size 0");

	delete[] p;
}

void elementAccess(UnitTest unit) {
	int *p = new int[5];
	int *tmp = p;
	for (int i = 0; i < 5; i++) { p[i] = i<<1; }
	ft::vector<int> vec(p, p + 5);

	bool equal = true;
	for (int i = 0; i < 5; i++) { (p[i] != vec[i]) ? equal = false : equal = true;}
	unit.assertTrue(equal, "p[i] != vec[i]");
	unit.assertEqual(vec.at(4), vec[4], "compare at");
	try {
		vec.at(5);
	}
	catch (const std::out_of_range &e) {
		unit.assertTrue(true, e.what());
	}
	unit.assertEqual(vec.front(), p[0]);
	unit.assertEqual(vec.back(), p[4]);
	delete[] tmp;
}

int main( void ) {
	testlist velementAccess = {elementAccess};
	testSuite("elementAccess", velementAccess);
	testlist vassign = {assign, assign2};
	testSuite("assign", vassign);
	return (0);
}
