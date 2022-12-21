#include <iostream>
#include "vector.hpp"
#include <gtest/gtest.h>

TEST(TestEqual, TestEqualTruee) {
	ft::vector<int> one;

	 int two = one.returnminustwo(4);

	ASSERT_TRUE(two == 2);
}

TEST(TestEqual, TestEqualTrueee) {
	ft::vector<int> one;

	 int two = one.returnminustwo(4);

	ASSERT_TRUE(two == 2);
}
