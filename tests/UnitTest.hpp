#ifndef UNITEST_HPP
#define UNITEST_HPP
#include <iostream>
#include <vector>
#include <cstring>

#define RESET_COLOR "\e[0m" 

/*
** Asserts settings
*/

#define ASSERT_FAIL "  Fail"
#define ASSERT_PASS "  Pass"
#define ASSERT_FAIL_COLOR "\e[31m"
#define ASSERT_PASS_COLOR "\e[32m"

/*
** testSuite settings
*/

#define TEST_SUITE_NAME_COLOR "\e[1;36m"
#define TEST_SUITE_TEST_COLOR "\e[0m"
#define TEST_SUITE_TEST " Test"

class UnitTest {
	public:
		UnitTest( void ) {};
		~UnitTest( void ) {};

		void assertTrue(bool condition) const {
			if (!condition) {
				std::cerr << ASSERT_FAIL_COLOR << ASSERT_FAIL << RESET_COLOR << std::endl;
			} else {
				std::cout << ASSERT_PASS_COLOR << ASSERT_PASS << RESET_COLOR << std::endl;
			}
		};
		void assertFalse(bool condition) const {
			if (condition) {
				std::cerr << ASSERT_FAIL_COLOR << ASSERT_FAIL << RESET_COLOR << std::endl;
			} else {
				std::cout << ASSERT_PASS_COLOR << ASSERT_PASS << RESET_COLOR << std::endl;
			}
		};

		template <typename T>
		void assertEqual(const T actual, const T expected) const {
			if (actual != expected) {
				std::cerr << ASSERT_FAIL_COLOR << ASSERT_FAIL << RESET_COLOR << std::endl;
			} else {
				std::cout << ASSERT_PASS_COLOR << ASSERT_PASS << RESET_COLOR << std::endl;
			}
		};
		template <typename T>
		void assertEqual(const T* actual, const T* expected) const {
			if (actual != expected) {
				std::cerr << ASSERT_FAIL_COLOR << ASSERT_FAIL << RESET_COLOR << std::endl;
			} else {
				std::cout << ASSERT_PASS_COLOR << ASSERT_PASS << RESET_COLOR << std::endl;
			}
		};
};

typedef void (*testlist[])(UnitTest);
typedef std::vector<void(*)(UnitTest)> asserts;

void testSuite(std::string name, testlist suit, size_t n);

#endif
