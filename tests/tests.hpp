#ifndef TESTS_HPP
#define TESTS_HPP

#include <vector>
#ifndef STD
	#include "./stl_vector.hpp"
#else	
	namespace ft = std;
#endif

#include <cstring>
#include "./include/UnitTest.hpp"
#include "./include/test_stl_vector.hpp"
std::string *arraySet( void );
#endif
