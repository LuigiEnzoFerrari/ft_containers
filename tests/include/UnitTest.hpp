#ifndef UNITEST_HPP
#define UNITEST_HPP
#include <iostream>
#include <cstring>


#define RESET_COLOR "\033[0m" 

/*
** testSuite settings
*/

#define TEST_SUITE_NAME_COLOR "\033[1;36m"
#define TEST_SUITE_TEST_COLOR "\033[0m"
#define TEST_SUITE_TEST " Test"

class UnitTest {
	private:
		std::string _assert_fail;
		std::string _assert_pass;
		std::string _assert_color_fail;
		std::string _assert_color_pass;
		size_t _total;
		size_t _fail;
		bool _mode;

	public:
		UnitTest(
			std::string assert_fail = "Fail",
			std::string assert_pass = "Pass",
			std::string assert_color_fail = "\033[31m",
			std::string assert_color_pass = "\033[32m"):
			_assert_fail(assert_fail),
			_assert_pass(assert_pass),
			_assert_color_fail(assert_color_fail),
			_assert_color_pass(assert_color_pass),
			_total(0), _fail(0), _mode(false) {
		};

		~UnitTest( void ) {
			std::cout << _total << "/" << _fail << std::endl;
		};
		void setAll(std::string assert_fail = "",
			std::string assert_pass = "",
			std::string assert_color_fail = "",
			std::string assert_color_pass = "" ) {
			this->_assert_fail = assert_fail != "" ? assert_fail : this->_assert_fail;
			this->_assert_pass = assert_pass != "" ? assert_pass : this->_assert_pass;
			this->_assert_color_fail = assert_color_fail != "" ? assert_color_fail : this->_assert_color_fail;
			this->_assert_color_pass = assert_color_pass != "" ? assert_color_pass : this->_assert_color_pass;

		}
		bool getMode( void ) const {
			return (_mode);
		}
		void setMode( bool mode) {
			_mode = mode;
		}
		void assertTrue(bool condition, std::string message = "") {
			std::ostream* output_stream;
			
			message = !message.compare("") ? message : " " + message;
			output_stream = condition ?  &std::cerr : &std::cout;
			_fail = condition ?  _fail : _fail + 1;
			_total++;
			std::string result = condition ? _assert_pass : _assert_fail;
			std::string color = condition ? _assert_color_pass : _assert_color_fail;

			if (_mode) {
				*output_stream << color << result << RESET_COLOR << message << std::endl;
			} else {
				*output_stream << color << "# " << RESET_COLOR;
			}
		};

		void assertFalse(bool condition) {
			assertTrue(!condition);
		};

		void assertFalse(bool condition, std::string message) {
			assertTrue(!condition, message);
		};

		template <typename T>
		void assertEqual(const T actual, const T expected) {
			assertTrue(actual == expected);
		};

		template <typename T>
		void assertEqual(const T* actual, const T* expected) {
			assertTrue(actual == expected);
		};

		template <typename T>
		void assertEqual(const T actual, const T expected, std::string message) {
			assertTrue(actual == expected, message);
		};

		template <typename T>
		void assertEqual(const T* actual, const T* expected, std::string message) {
			assertTrue(actual == expected, message);
		};
};

typedef void (*testlist[])(UnitTest&);
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
	unit.setMode(true);
	std::cout << TEST_SUITE_NAME_COLOR << name << RESET_COLOR << std::endl;
	for(size_t i = 0; i < n; i++) {
		if (unit.getMode()) {
			std::cout << (i + 1) << TEST_SUITE_TEST_COLOR << TEST_SUITE_TEST << "\n";
		}
		suit[i](unit);
		std::cout << RESET_COLOR;
	};
}

#endif
