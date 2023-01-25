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
typedef std::map<string, int>::iterator map_iterator;

std::string *arraySet( void );
std::string *test( void );
string *setCars( void );


bool compareMapAndPair(std::map<string, int> map, std::pair<string, int> *arr, size_t n);

void print_values( std::map<std::string, int> mymap );
std::pair<string, int> *getCars( void );

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

void map_constructors(UnitTest& unit);
void map_iterators(UnitTest& unit);
void map_capacity(UnitTest& unit);
void map_element_acess(UnitTest& unit);

#endif
