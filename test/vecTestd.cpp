#include <iostream>
#include "vec.hpp"
#include <gtest/gtest.h>
#include <vector>

TEST(TestEqual, TestEqualTruee) {
	std::vector<int> one;
	std::vector<int> two;
	Vec vec;
	for (int i = 0; i < 7; i++) {
		one.push_back(i);
	}
	two = vec.addSequence(7);

	ASSERT_TRUE(one == two);
}
