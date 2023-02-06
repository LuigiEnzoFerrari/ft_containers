#include "tests.hpp"
#include <algorithm>


static void testDefaultConstructor(UnitTest& unit) {
	{
		ft::stack<string> myStack;

		unit.assertTrue(myStack.empty(), "empty() == true");
		unit.assertTrue(myStack.size() == 0, "size() == 0");
		myStack.push("pera");
		unit.assertFalse(myStack.empty(), "empty() == true");
		unit.assertTrue(myStack.size() == 1, "size() == 1");

	}
	{
		ft::stack<string, std::deque<string> > myStack;

		unit.assertTrue(myStack.empty(), "empty() == true");
		unit.assertTrue(myStack.size() == 0, "size() == 0");
		myStack.push("pera");
		unit.assertFalse(myStack.empty(), "empty() == true");
		unit.assertTrue(myStack.size() == 1, "size() == 1");
	}
	string *names = arraySet();
	{
		ft::vector<string> arr(names, names + 5);
		ft::stack<string, ft::vector<string> > myStack(arr);

		unit.assertFalse(myStack.empty(), "empty() == false");
		unit.assertTrue(myStack.size() == 5, "size() == 5");
	}
	{
		std::deque<string> arr(names, names + 5);
		ft::stack<string, std::deque<string> > myStack(arr);

		unit.assertFalse(myStack.empty(), "empty() == false");
		unit.assertTrue(myStack.size() == 5, "size() == 5");
	}
	delete[] names;
}

static void testPushTopPop(UnitTest& unit) {
	string *names = arraySet();
	ft::stack<string> myStack;

	for (size_t i = 0; i < 5; i++) {
		myStack.push(names[i]);
	}
	unit.assertTrue(myStack.size() == 5, "size() == 5");

	std::string *ptr = &myStack.top();
	unit.assertTrue(*ptr == "Gustavo", "name == Gustavo");

	*ptr = "I can edit";

	std::string &name = myStack.top();
	unit.assertTrue(name == "I can edit", "name == I can edit");
	myStack.pop();

	name = myStack.top();
	unit.assertTrue(name == "Adrian", "name == Adrian");
	myStack.pop();

	name = myStack.top();
	unit.assertTrue(name == "Rafa", "name == Rafa");
	unit.assertTrue(myStack.size() == 3, "size == 3");
	myStack.pop();

	name = myStack.top();
	unit.assertTrue(name == "Caio", "name == Caio");
	myStack.pop();

	name = myStack.top();
	unit.assertTrue(name == "Luigi", "name == Luigi");
	myStack.pop();
	delete[] names;
}
void stack_member_functions(UnitTest& unit) {
	unit.runTest(testDefaultConstructor, "testDefaultConstrutor");
	unit.runTest(testPushTopPop, "testPushTopPop");
}
