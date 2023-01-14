#include "iterator.hpp"
#include "UnitTest.hpp"

int main( void ) {
	testlist veciterators = {TestCompoundAssignmentOperations, testCompareOperators, testCopyConstructor};
	testSuite("vector iterators", veciterators, 3);
	return (0);
}
