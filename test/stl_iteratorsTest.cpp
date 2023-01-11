#include <iostream>
#include <gtest/gtest.h>
#include "stl_iterator.hpp"
#include "stl_vector.hpp"

TEST(TestEqual, TestVector) {
	std::vector<int> one(3, 10);
	ft::vector<int> two(3, 10);
	bool equal = true;
	std::vector<int>::iterator it = one.begin();
	ft::vector<int>::iterator it2 = two.begin();
	for (; it != one.end();) {
		if (*it++ != *it2++) {
			equal = false;
		}
	}
	ASSERT_TRUE(equal);	
}

TEST(TestEqual, TestRAIteratorPosIncrement) {
	int array[6] = {5, 4, 8, 0, 9, 10};
	ft::normal_iterator<int> it(array);
	bool equal = true;
	if (*it++ != 5) {
		equal = false;
	}
	ASSERT_TRUE(equal);
	if (*it != 4) {
	equal = false;
	}
	ASSERT_TRUE(equal);
}

TEST(TestEqual, TestRAIteratorDereference) {
	int array[6] = {5, 4, 8, 0, 9, 10};
	ft::normal_iterator<int> it(array);
	int t = 404;
	*it = t;

	ASSERT_TRUE(*it = 404);
}

TEST(TestEqual, TestRAIteratorReferencea) {
	int array[6] = {5, 4, 8, 0, 9, 10};
	ft::normal_iterator<int> it(array);
	std::vector<int>::iterator it2(array);

	ASSERT_TRUE(*it == *it2);
}

TEST(TestEqual, TestRAIteratorReference) {
	int array[6] = {3, 4, 8, 0, 9, 10};
	ft::normal_iterator<int> it(array);

	ASSERT_TRUE(*it == 3);
}


TEST(TestEqual, TestRAIteratorDecrement) {
	int array[6] = {3, 4, 8, 0, 9, 10};
	bool equal = true;
	ft::normal_iterator<int> it(&array[5]);
	for (int i = 5; i >= 0; i--) {
		if (array[i] != *it--) {
			equal = false;
		}
	}
	ASSERT_TRUE(equal);
}

TEST(TestEqual, TestRAIteratorIncrement) {
	int array[6] = {3, 4, 8, 0, 9, 10};
	bool equal = true;
	ft::normal_iterator<int> it(array);
	std::vector<int>::iterator it2(array);
	for (int i = 0; i < 6; i++) {
		if (*it2++ != *it++) {
			equal = false;
		}
	}

	ASSERT_TRUE(equal);
}

TEST(TestEqual, TestRAIteratorCopyAsssingment) {
	int array[6] = {3, 4, 8, 0, 9, 10};
	ft::normal_iterator<int> it(array);
	ft::normal_iterator<int> it2(array);

	ASSERT_TRUE(it == it2);
}

TEST(TestEqual, TestRAIteratorDefaultConstructor) {
	ft::normal_iterator<int> it;
	ft::normal_iterator<int> it2(NULL);

	ASSERT_TRUE(it == it2);
}

TEST(TestEqual, TestRAIteratorCopyConstructor) {
	int array[6] = {3, 4, 8, 0, 9, 10};
	bool equal = true;
	ft::normal_iterator<int> it(array);
	for (int i = 0; i < 6; i++) {
		if (array[i] != it[i]) {
			equal = false;
		}
	}

	ASSERT_TRUE(equal);
}

