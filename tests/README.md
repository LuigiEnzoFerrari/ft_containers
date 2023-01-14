# HOW TO USE

Create a function for test with this prototype
```c++
void f(UnitTest unit);
``` 
make your own tests.

```c++
void testVecIterator(UnitTest unit = UnitTest()) {
	int p[4] = {3, 4, 5, 2};
	std::vector<int> vec(p, p + 4);

	std::vector<int>::iterator it = vec.begin();
	unit.assertEqual(*(it + 2), *(p + 2));

	it = vec.end();
	unit.assertEqual(*it, p[3]);
}
```  

The UnitTest class has some asserts methods 
```c++
void assertTrue(bool condition);
void assertEqual(const T actual, const T expected);
. . .
```
You can use this test in a main function
```c++
int main( void ) {
	testVecIterator();
	return (0);
}
```
The output should be something like this
```shell
lenzo@Ferrari$ ./a.out 
  Pass
  Fail
lenzo@Ferrari$ 
```
You can put all the test functions inside a testSuite function   
```c++
	testlist veciterators = {testVecIterator, testVecReverse};
	
	testSuite("normal_and_reverse_iterators", veciterators, 2);
```

```c++
void testVecReverse(UnitTest unit) {
	int p[4] = {3, 4, 5, 2};
	std::vector<int> vec(p, p + 4);

	std::vector<int>::reverse_iterator it = vec.rbegin();
	unit.assertEqual(*(it + 2), *(p + 2));
}

void testVecIterator(UnitTest unit = UnitTest()) {
	int p[4] = {3, 4, 5, 2};
	std::vector<int> vec(p, p + 4);

	std::vector<int>::iterator it = vec.begin();
	unit.assertEqual(*(it + 2), *(p + 2));

	it = vec.end();
	unit.assertEqual(*it, p[3]);
}

int main( void ) {
	testlist veciterators = {testVecIterator, testVecReverse};
	testSuite("normal_and_reverse_iterators", veciterators, 2);
	return (0);
}
```
The output will be this.
```shell
lenzo@Ferrari$ ./a.out 
normal_and_reverse_iterators
1 Test
  Pass
  Fail
2 Test
  Fail
lenzo@Ferrari$ 
```

