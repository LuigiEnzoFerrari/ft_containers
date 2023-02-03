#ifndef TESTS_HPP
#define TESTS_HPP

#include <iostream>
#include <string>
#include <deque>

#ifndef STD
	#include "./stl_vector.hpp"
	#include "./stl_map.hpp"
#else
	namespace ft = std;
	#include <map>
	#include <vector>
#endif
#include <cstring>
#include "./UnitTest.hpp"

typedef std::string string;
typedef ft::map<string, int>::iterator map_iterator;

std::string *arraySet( void );
std::string *test( void );

bool compareMapAndPair(ft::map<string, int> map, ft::pair<string, int> *arr, size_t n);
string *setCars( void );
ft::pair<string, int> *getCars( void );

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
void map_element_access(UnitTest& unit);
void map_modifiers(UnitTest& unit);
void map_observers(UnitTest& unit);
void map_operations(UnitTest& unit);
void map_pair(UnitTest& unit);

#endif
