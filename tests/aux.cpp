#include "tests.hpp"
string *arraySet( void ) {
	string *names = new string[5];
	names[0] = "Luigi";
	names[1] = "Caio";
	names[2] = "Rafa";
	names[3] = "Adrian";
	names[4] = "Gustavo";
	return (names);
}

string *setCars( void ) {
	string *names = new string[5];
	names[0] = "Mitsubishi";
	names[1] = "Peugeot";
	names[2] = "Ferrari";
	names[3] = "Kawasaki";
	names[4] = "Porsche";
	return (names);
}

std::map<string, int> getCars( void ) {
	std::string *names = setCars();
	std::map<string, int> cars;
	
	for (size_t i = 0; i < 5; i++) {
		cars[names[i]] = i * 3;

	}
	delete[] names;
	// cars["Mitsubishi Lancer"] = 10;
	// cars["Peugeot 207"] = 9;
	// cars["Ferrari 458"] = 8;
	// cars["Kawasaki ZZR 250"] = 7;
	// cars["Porsche 911"] = 6;
	// cars["Subaru WRX"] = 5;
	return (cars);
}

void print_values( std::map<std::string, int> mymap ) {
	for (std::map<string, int>::iterator it = mymap.begin(); it != mymap.end(); it++)
	{
		std::cout << it->first    // string (key)
				<< ':'
				<< it->second   // string's value 
				<< std::endl;
	}
}
