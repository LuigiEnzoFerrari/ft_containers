#include "tests.hpp"

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
