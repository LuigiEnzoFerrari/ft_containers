#include "tests.hpp"

void testClear(UnitTest& unit) {
	std::string *names = arraySet();
	ft::vector<std::string> vec(names, names + 5);
	vec.clear();
	unit.assertTrue(vec.size() == 0, "vec.size() == 0");
	unit.assertTrue(vec.capacity() == 5, "vec.capacity() == 4");
}

void 	testEraseRange(UnitTest& unit) {
	std::string *names = arraySet();

	{
		ft::vector<std::string> vec(names, names + 4);
		vec.erase(vec.begin(), vec.begin() + 3);
		unit.assertTrue(vec.size() == 1, "vec.size() == 1");
		unit.assertTrue(vec.capacity() == 4, "vec.capacity() == 4");
	}
	{
		ft::vector<std::string> vec(names, names + 4);
		vec.erase(vec.begin() + 2, vec.begin() + 3);
		unit.assertTrue(vec.size() == 3, "vec.size() == 1");
		unit.assertTrue(vec.capacity() == 4, "vec.capacity() == 4");
	}
	{
		ft::vector<std::string> vec;
		vec.erase(vec.end(), vec.end());
		unit.assertTrue(vec.size() == 0, "vec.size() == 0");
		unit.assertTrue(vec.capacity() == 0, "vec.capacity() == 0");
	}
}

void testErase(UnitTest& unit) {
	std::string *names = arraySet();

	{
		ft::vector<std::string> vec(names, names + 4);
		vec.erase(vec.begin());
		unit.assertTrue(vec.size() == 3, "vec.size() == 3");
		unit.assertTrue(vec.capacity() == 4, "vec.capacity() == 4");
		bool equal = true;
		for (size_t i = 0; i < vec.size(); i++) {
			if(vec[i] != names[i + 1]) {
				equal = false;
			}
		}
		unit.assertTrue(equal, "vec[i] == names[i + 1]");
	}
	{
		ft::vector<std::string> vec(names, names + 4);
		vec.erase(vec.end());
		unit.assertTrue(vec.size() == 3, "vec.size() == 3");
		unit.assertTrue(vec.capacity() == 4, "vec.capacity() == 4");
		bool equal = true;
		for (size_t i = 0; i < vec.size(); i++) {
			if(vec[i] != names[i]) {
				equal = false;
			}
		}
		unit.assertTrue(equal, "vec[i] == names[i + 1]");
	}
}

void testInsertSingleElement(UnitTest& unit) 	{
	std::string *names = arraySet();
	ft::vector<std::string> vec(names, names + 5);

	vec.insert(vec.begin() + 2, names[0]);

	unit.assertTrue(vec[2] == "Luigi", "vec[2] == Luigi");
	unit.assertTrue(vec.capacity() == 10, "vec.capacity() == 10");

	ft::vector<std::string> vec2;

	vec2.insert(vec2.begin(), names[0]);

	unit.assertTrue(vec2[0] == "Luigi", "vec2[0] == Luigi");
	unit.assertTrue(vec2.size() == 1, "vec2.size() == 1");
	unit.assertTrue(vec2.capacity() == 1, "vec2.capacity() == 1");

	vec2.insert(vec2.end(), names[2]);

	unit.assertTrue(vec2[1] == "Rafa", "vec2[1] == Rafa");
	unit.assertTrue(vec2.size() == 2, "vec2.size() == 2");
	unit.assertTrue(vec2.capacity() == 2, "vec2.capacity() == 2");
}

void testInsertFillElements(UnitTest &unit) {
	std::string *names = arraySet();
	{
		ft::vector<std::string> vec;
		vec.insert(vec.begin(), 1, names[2]);
		unit.assertTrue(vec[0] == names[2], "vec[x] == name[x]");
		unit.assertTrue(vec.size() == 1, "size == 1");
		unit.assertTrue(vec.capacity() == 1, "capacity == 1");
	}
	{
		ft::vector<std::string> vec;
		vec.insert(vec.begin(), 3, names[3]);
		unit.assertTrue(vec[0] == names[3] && vec[1] == names[3] && vec[2] == names[3], "vec[x] == name[x]");
		unit.assertTrue(vec.size() == 3, "size == 3");
		unit.assertTrue(vec.capacity() == 3, "capacity == 3");
	}
	{
		ft::vector<std::string> vec(names, names + 5);
		vec.insert(vec.begin() + 2, 2, names[4]);
		unit.assertTrue(vec[2] == names[4] && vec[3] == names[4], "vec[x] == name[x]");
		unit.assertTrue(vec.size() == 7, "size == 7");
		unit.assertTrue(vec.capacity() == 10, "capacity == 10");
	}
	{
		ft::vector<std::string> vec(names, names + 4);
		vec.insert(vec.end(), 2, names[1]);
		unit.assertTrue(*(vec.end() - 1) == names[1] && *(vec.end() - 2) == names[1], "vec[x] == name[x]");
		unit.assertTrue(vec.size() == 6, "size == 6");
		unit.assertTrue(vec.capacity() == 8, "capacity == 8");
	}
}

void testInsertRange(UnitTest& unit) {
	std::string *names = arraySet();
	{
		ft::vector<std::string> vec;

		vec.insert(vec.begin(),vec.begin(), vec.begin());
		unit.assertTrue(vec.empty(), "vec.empty()");
		unit.assertTrue(vec.capacity() == 0, "vec.capacity() == 0");
	}
	{
		ft::vector<std::string> vec;
		ft::vector<std::string> vec2(names, names + 3);

		vec.insert(vec.end(), vec2.begin(), vec2.end());
		unit.assertTrue(vec[0] == names[0] && vec[1] == names[1] && vec[2] == names[2], "vec[x] == name[x]");
		unit.assertTrue(vec.size() == 3, "vec.size() == 3");
		unit.assertTrue(vec.capacity() == 3, "vec.capacity()== 3");
	}
	{
		ft::vector<std::string> vec(names, names + 3);
		ft::vector<std::string> vec2(names + 3, names + 5);

		vec.insert(vec.begin() + 2,vec2.begin(), vec2.end());

		unit.assertTrue(vec[2] == vec2[0] && vec[3] == vec2[1], "vec[x] == name[x]");
		unit.assertTrue(vec.size() == 5, "vec.size() == 4");
		unit.assertTrue(vec.capacity() == 6, "vec.capacity()== 6");
	}
	delete[] names;
}

void testPopBack(UnitTest& unit) {
	std::string *names = arraySet();
	ft::vector<std::string> vec(names, names + 1);
	vec.pop_back();
	unit.assertTrue(vec.size() == 0, "size == 0");
	unit.assertTrue(vec.capacity() == 1, "capacity == 1");

	ft::vector<std::string> vec2(names, names + 5);
	bool equal = false;
	vec2.pop_back();
	for (size_t i = 0; i < vec2.size(); i++) {
		
		if (vec2[i].compare(names[i]) != 0) {
			equal = false;
		}
	}
	unit.assertTrue(vec2.size() == 4, "size == 4");
	unit.assertTrue(vec2.size() == 4, "vec[i] == names[i]");

	delete[] names;
}

void testPushBack(UnitTest& unit) {
	std::string *names = arraySet();
	ft::vector<std::string> vec;

	for (size_t i = 0; i < 3; i++) {
		vec.push_back(names[i]);
		unit.assertTrue(vec.size() == i + 1, "Expeted: Equal; size() = i");
		unit.assertTrue(vec.capacity() == 1 << i, "Expeted: Equal; capacity() = 1 << i");
		unit.assertTrue(vec[i].compare(names[i]) == 0, "Expeted: Equal; vec[i] = names[i]");
	}
	vec.push_back(names[3]);
	vec.push_back(names[4]);

	unit.assertTrue(vec.size() == 5, "Expeted: Equal; size() = 5");
	unit.assertTrue(vec.capacity() == 8, "Expeted: Equal; capacity() = 8");
	unit.assertTrue(vec[3].compare(names[3]) == 0, "Expeted: Equal; vec[3] = names[3]");

	delete[] names;
}

void vector_modifiers(UnitTest& unit) {
	testPushBack(unit);
	testPopBack(unit);
	testInsertRange(unit);
	testInsertFillElements(unit);
	testInsertSingleElement(unit);
	testErase(unit);
	testEraseRange(unit);
}

// void testVectorModifiers(UnitTest& unit) {
// 	std::string *names = arraySet();
// 	ft::vector<std::string> vec(names, names + 5) ;
// 	vec.assign(3, "Victor");
// 	bool equal = true;
// 	for (size_t i = 0; i < 3; i++) {
// 		if(std::string("Victor").compare(vec[i]) != 0) {
// 			equal = false;
// 			break ;
// 		}
// 	}
// 	unit.assertTrue(equal, "Expected: True; i < 10 vec[i] == Victor");

// 	vec.assign(10, "Victor");
// 	for (size_t i = 0; i < 10; i++) {
// 		if(std::string("Victor").compare(vec[i]) != 0) {
// 			equal = false;
// 			break ;
// 		}
// 	}
// 	unit.assertTrue(equal, "Expected: True; i < 10 vec[i] == Victor");
// 	unit.assertTrue(vec.size() == 10, "vec.size() == 10");
// 	unit.assertTrue(vec.capacity() == 10, "vec.size() == 10");
// 	ft::vector<std::string> vec2(names, names + 5);
// 	vec.assign(vec2.begin() + 2, vec2.begin() + 4);
// 	size_t i = 0;
// 	for (
// 		ft::vector<std::string>::iterator it = vec.begin(); it < vec.begin() + 2; it++, i++) {
// 		if((*it).compare(names[i])) {
// 			equal = false;
// 			break ;
// 		}
// 	}
// 	delete[] names;
// }
