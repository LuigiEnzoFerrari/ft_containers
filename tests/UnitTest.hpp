#ifndef UNITEST_HPP
#define UNITEST_HPP
#include <iostream>
#include <vector>
#include <cstring>

#define RESET_COLOR "\e[0m" 

/*
** testSuite settings
*/

#define TEST_SUITE_NAME_COLOR "\e[1;36m"
#define TEST_SUITE_TEST_COLOR "\e[0m"
#define TEST_SUITE_TEST " Test"

class UnitTest {
	private:
		std::string _assert_fail;
		std::string _assert_pass;
		std::string _assert_color_fail;
		std::string _assert_color_pass;

	public:
		UnitTest( std::string assert_fail = "Fail",
			std::string assert_pass = "Pass",
			std::string assert_color_fail = "\e[31m",
			std::string assert_color_pass = "\e[32m"):
			_assert_fail(assert_fail),
			_assert_pass(assert_pass),
			_assert_color_fail(assert_color_fail),
			_assert_color_pass(assert_color_pass) {
		};

		~UnitTest( void ) {};

		void assertTrue(bool condition) const {
			std::string result = condition ? _assert_pass : _assert_fail;
			std::string color = condition ? _assert_color_pass : _assert_color_fail;
			std::cerr << color << result << RESET_COLOR << std::endl;
		};

		void assertFalse(bool condition) const {
			assertTrue(!condition);
		};

		void assertTrue(bool condition, std::string message) const {
			message = " " + message;
			std::string result = condition ? _assert_pass : _assert_fail;
			std::string color = condition ? _assert_color_pass : _assert_color_fail;
			std::cerr << color << result << RESET_COLOR << message << std::endl;
		};

		void assertFalse(bool condition, std::string message) const {
			assertTrue(!condition, message);
		};

		template <typename T>
		void assertEqual(const T actual, const T expected) const {
			assertTrue(actual == expected);
		};

		template <typename T>
		void assertEqual(const T* actual, const T* expected) const {
			assertTrue(actual == expected);
		};

		template <typename T>
		void assertEqual(const T actual, const T expected, std::string message) const {
			assertTrue(actual == expected, message);
		};

		template <typename T>
		void assertEqual(const T* actual, const T* expected, std::string message) const {
			assertTrue(actual == expected, message);
		};
};

typedef void (*testlist[])(UnitTest);
typedef std::vector<void(*)(UnitTest)> asserts;
template <typename T, std::size_t N>
T* end(T(&arr)[N])
{
    return arr + N;
}
template <typename T, std::size_t N>
T* begin(T(&arr)[N])
{
    return arr;
}

template <typename T, std::size_t N>
void testSuite(std::string name, T(&suit)[N], UnitTest unit = UnitTest()) {

	size_t n = end(suit) - begin(suit);
	std::cout << TEST_SUITE_NAME_COLOR << name << RESET_COLOR << std::endl;
	for(size_t i = 0; i < n; i++) {
		std::cout << (i + 1) << TEST_SUITE_TEST_COLOR << TEST_SUITE_TEST << "\n";
		suit[i](unit);
		std::cout << RESET_COLOR;
	};
};

#endif