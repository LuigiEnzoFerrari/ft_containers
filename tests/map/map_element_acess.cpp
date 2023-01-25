#include "tests.hpp"

static void testOffSetOperator(UnitTest& unit) {
	std::map<string, string> map;

	map["Luigi"] = "Rabudo";
	unit.assertTrue(map["Luigi"] == "Rabudo", "Luigi == Rabudo");
	map["Caio"] = "Chad";
	unit.assertTrue(map["Caio"] == "Chad", "Caio == Cahd");

	map["Gariadno"];
	unit.assertTrue(map.size() == 3, "size == 3, The size always increases by 1 if does not found a key");
	map["Gariadno"] = "Shot Hair Hunter";
	unit.assertTrue(map["Gariadno"] == "Shot Hair Hunter", "Gariadno == Shot Hair Hunter");
	unit.assertTrue(map.size() == 3, "size == 3, The old value is replaced when found the key, and the size will be the same");

}

void map_element_acess(UnitTest& unit) {
	unit.runTest(testOffSetOperator, "map_element_acess");
}
