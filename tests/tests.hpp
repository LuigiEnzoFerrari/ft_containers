#ifndef TESTS_HPP
#define TESTS_HPP

#include <vector>
#include <map>
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
typedef std::string string;
std::string *arraySet( void );
std::string *test( void );
class Sets {
	std::string *names;

	Sets( void ) {
		names = arraySet();
	};
	~Sets( void ) {
		delete[] names;
	}
};


void vector_iterator(UnitTest& unit);
void vector_reverse_iterator(UnitTest& unit);
void vector_modifiers(UnitTest& unit);
void vector_elements_access(UnitTest& unit);
void vector_constructors(UnitTest& unit);
void vector_capacity(UnitTest& unit);
void vector_non_member_functions(UnitTest& unit);

void map_capacity(UnitTest& unit);

#endif
