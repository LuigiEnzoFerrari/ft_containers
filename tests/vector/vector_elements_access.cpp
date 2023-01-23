#include "tests.hpp"

void testElementsAcess(UnitTest& unit) {
	string *names = arraySet();
	{
		ft::vector<string> vec(names, names + 5);
		string& name = vec.at(3);
		unit.assertTrue(name == names[3], "name == names[3]");
		name = "Victor";
		unit.assertTrue(vec[3] == "Victor");
	}
	{
		ft::vector<string> const vec(names, names + 5);
		const string& name = vec.at(2);
		unit.assertTrue(name == names[2], "name == names[2]");
	}
	{
		ft::vector<string> vec(names, names + 5);
		string& name = vec.front();
		unit.assertTrue(name == names[0], "name == names[0]");
		name = "Victor";
		unit.assertTrue(vec[0] == "Victor");
	}
	{
		//assert to confirm the value at function was a const
		ft::vector<string> const vec(names, names + 5);
		const string& name = vec.front();
		unit.assertTrue(name == names[0], "name == names[0]");
	}
	{
		ft::vector<string> vec(names, names + 5);
		string& name = vec.back();
		unit.assertTrue(name == names[4], "name == names[4]");
		name = "Victor";
		unit.assertTrue(vec[4] == "Victor");
	}
	{
		ft::vector<string> const vec(names, names + 5);
		const string& name = vec.back();
		unit.assertTrue(name == names[4], "name == names[4]");
	}
	delete[] names;
	
}

void vector_elements_access(UnitTest& unit) {
	testElementsAcess(unit);
}
