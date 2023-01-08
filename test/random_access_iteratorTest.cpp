#include <iostream>
#include <gtest/gtest.h>
#include "random_access_iterator.hpp"
#include "vector.hpp"

TEST(TestEqual, TestRAIteratorPosIncrement) {
	int array[6] = {5, 4, 8, 0, 9, 10};
	ft::random_access_iterator<int> it(array);
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
	ft::random_access_iterator<int> it(array);
	int t = 404;
	*it = t;

	ASSERT_TRUE(*it = 404);
}

TEST(TestEqual, TestRAIteratorReferencea) {
	int array[6] = {5, 4, 8, 0, 9, 10};
	ft::random_access_iterator<int> it(array);
	std::vector<int>::iterator it2(array);

	ASSERT_TRUE(*it == *it2);
}

TEST(TestEqual, TestRAIteratorReference) {
	int array[6] = {3, 4, 8, 0, 9, 10};
	ft::random_access_iterator<int> it(array);

	ASSERT_TRUE(*it == 3);
}


TEST(TestEqual, TestRAIteratorDecrement) {
	int array[6] = {3, 4, 8, 0, 9, 10};
	bool equal = true;
	ft::random_access_iterator<int> it(&array[5]);
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
	ft::random_access_iterator<int> it(array);
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
	ft::random_access_iterator<int> it(array);
	ft::random_access_iterator<int> it2(array);

	ASSERT_TRUE(it == it2);
}

TEST(TestEqual, TestRAIteratorDefaultConstructor) {
	ft::random_access_iterator<int> it;
	ft::random_access_iterator<int> it2(NULL);

	ASSERT_TRUE(it == it2);
}

TEST(TestEqual, TestRAIteratorCopyConstructor) {
	int array[6] = {3, 4, 8, 0, 9, 10};
	bool equal = true;
	ft::random_access_iterator<int> it(array);
	for (int i = 0; i < 6; i++) {
		if (array[i] != it[i]) {
			equal = false;
		}
	}

	ASSERT_TRUE(equal);
}

