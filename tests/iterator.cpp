#include "iterator.hpp"

void testVecReverse(UnitTest unit) {
	int p[4] = {3, 4, 5, 2};
	std::vector<int> vec(p, p + 4);

	std::vector<int>::reverse_iterator it = vec.rbegin();
	unit.assertEqual(*(it + 2), *(p + 2));
}

void testCopyConstructor(UnitTest unit) {
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2(it);

	unit.assertTrue(it == it2);

	int *p = new int[5];
	int *tmp = p;
	for (int i = 0; i < 5; i++) { p[i] = i<<1; }

	std::vector<int>::iterator it3(p);
	std::vector<int>::iterator it4(it3);
	unit.assertEqual(*it3, *it4);
	unit.assertEqual(*(it3 + 3), *(it4 + 3));
	delete[] tmp;
}

void TestCompoundAssignmentOperations(UnitTest unit) {

	int *p = new int[5];
	int *tmp = p;
	for (int i = 0; i < 5; i++) { p[i] = i<<1; }

	std::vector<int>::iterator it(p);

	unit.assertEqual(*(p + 3), *(it + 3));
	bool equal = true;
	for (size_t i = 0; i < 5; i++) {
		if (*it++ != *p++) {
			equal = false;
		}
	}
	unit.assertTrue(equal);

	unit.assertEqual(*(p - 3), *(it - 3));

	for (size_t i = 0; i < 5; i++) {
		if (*--it != *--p) {
			equal = false;
		}
	}

	unit.assertTrue(equal);
	for (size_t i = 0; i < 1; i++) {
		if (it[i] != p[i]) {
			unit.assertTrue(equal);
		}
	}

	p += 4;
	it += 4;
	unit.assertEqual(*p, *it);

	p -= 2;
	it -= 2;
	unit.assertEqual(*p, *it);

	delete[] tmp;
}

void testCompareOperators(UnitTest unit) {
	int *p = new int[5];
	for (int i = 0; i < 5; i++) { p[i] = i<<1; }
	std::vector<int>::iterator it(p);
	unit.assertTrue(it == it);
	unit.assertFalse(it + 1 == it);

	unit.assertFalse(it > it);
	unit.assertTrue(it + 1 > it);
	
	unit.assertFalse(it < it);
	unit.assertTrue(it < it + 1);
	
	unit.assertTrue(it >= it);
	unit.assertTrue(it + 1 >= it);
	unit.assertFalse(it >= it + 1);

	unit.assertTrue(it <= it);
	unit.assertTrue(it <= it + 1);
	unit.assertFalse(it + 1 <= it);
	delete[] p;
}