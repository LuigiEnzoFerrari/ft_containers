#include "iterator.hpp"
#include "UnitTest.hpp"
int main( void ) {

	testlist veciterators = {testCopyConstructor};
	testSuite("vector iterators", veciterators);
	return (0);
}
