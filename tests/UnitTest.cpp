#include "UnitTest.hpp"

void testSuite(std::string name, testlist suit, size_t n) {
	asserts v(suit, suit + n);

	std::cout << TEST_SUITE_NAME_COLOR << name << RESET_COLOR << std::endl;

	for(size_t i = 0; i < n; i++) {
		std::cout << (i + 1) << TEST_SUITE_TEST_COLOR << TEST_SUITE_TEST << "\n";
		v[i](UnitTest());
		std::cout << RESET_COLOR;
	};
};
