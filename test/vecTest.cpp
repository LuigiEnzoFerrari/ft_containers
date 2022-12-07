#include <iostream>
#include "vec.hpp"
#include <gtest/gtest.h>
#include <vector>

TEST(TestEqual, TestEqualTrue) {
	std::vector<int> one;
	std::vector<int> two;
	Vec vec;
	for (int i = 0; i < 6; i++) {
		one.push_back(i);
	}
	two = vec.addSequence(6);

	ASSERT_TRUE(one == two);
}
