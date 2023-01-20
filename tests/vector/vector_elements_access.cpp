#include "tests.hpp"

void testElementsAcess(UnitTest& unit) {
	std::string *names = arraySet();
	{
		ft::vector<std::string> vec(names, names + 5);
		std::string& name = vec.at(3);
		unit.assertTrue(name == names[3], "name == names[3]");
		name = "Victor";
		unit.assertTrue(vec[3] == "Victor");
	}
	{
		//assert to confirm the value at function was a const
		ft::vector<std::string> const vec(names, names + 5);
		const std::string& name = vec.at(2);
		unit.assertTrue(name == names[2], "name == names[2]");
	}
	{
		ft::vector<std::string> vec(names, names + 5);
		std::string& name = vec.front();
		unit.assertTrue(name == names[0], "name == names[0]");
		name = "Victor";
		unit.assertTrue(vec[0] == "Victor");
	}
	{
		//assert to confirm the value at function was a const
		ft::vector<std::string> const vec(names, names + 5);
		const std::string& name = vec.front();
		unit.assertTrue(name == names[0], "name == names[0]");
	}
	{
		ft::vector<std::string> vec(names, names + 5);
		std::string& name = vec.back();
		unit.assertTrue(name == names[4], "name == names[4]");
		name = "Victor";
		unit.assertTrue(vec[4] == "Victor");
	}
	{
		//assert to confirm the value at function was a const
		ft::vector<std::string> const vec(names, names + 5);
		const std::string& name = vec.back();
		unit.assertTrue(name == names[4], "name == names[4]");
	}
}

void vector_elements_access(UnitTest& unit) {
	testElementsAcess(unit);
}
