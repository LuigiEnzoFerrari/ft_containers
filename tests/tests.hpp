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

/*
** TESTS_STL_VECTOR
*/
std::string *arraySet( void );
void vector_iterator(UnitTest& unit);
void vector_reverse_iterator(UnitTest& unit);
void vector_modifiers(UnitTest& unit);
void vector_elements_access(UnitTest& unit);
void vector_constructors(UnitTest& unit);
void vector_capacity(UnitTest& unit);
void vector_not_member_functions(UnitTest& unit);
#endif
