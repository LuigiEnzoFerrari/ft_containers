#include "tests.hpp"
#include <map>

struct Lenzo {
	std::string pera;
};

void reverseDereference(UnitTest unit) {
	Lenzo numbers[2];
	numbers[0].pera = "pera1";
	numbers[1].pera = "pera2";

	ft::vector<Lenzo> vec(numbers, numbers + 2);	

	ft::vector<Lenzo>::iterator it = vec.begin();
	ft::vector<Lenzo>::reverse_iterator rit(it + 2);

	unit.assertTrue(rit->pera == (it + 1)->pera, "Expected: True; rit(it + 2), rit->pera == (it + 1)->pera");
	unit.assertTrue((rit + 1)->pera == it->pera, "Expected: True; rit(it + 2), (rit + 1)->pera == it->pera");
}

void reverseBaseFunction(UnitTest unit) {
	int *p = new int[5];
	for (int i = 0; i < 5; i++) { p[i] = i<<1; }
	ft::vector<int>::iterator it(p);

	ft::vector<int>::reverse_iterator rit(it + 5);
	
	unit.assertTrue(*(it + 4) == *(rit.base() - 1), "Expect: True; *(it + 4) == *(rit.base() - 1)");
	
	delete[] p;
}

void reverseOffsetDereferenceOperator(UnitTest unit) {
	int *p = new int[5];
	bool equal = true;

	ft::vector<int>::iterator it(p);

	ft::vector<int>::reverse_iterator rit(it + 5);
	for (int i = 0; i < 5; i++) {
			p[i] = i<<1;
			if (rit[4 - i] != p[i]) {
				equal = false;
			}
		}
	unit.assertTrue(equal, "Expect: True; it[i] == p[i]");
	delete[] p;
}

void testReverseIteratorIncrementedDecremented(UnitTest unit) {
	int *p = new int[5];
	int *tmp = p;
	bool equal = true;
	for (int i = 0; i < 5; i++) {
		p[i] = i<<1;
	}
	typedef ft::vector<int>::iterator iter_type;
	ft::vector<int> src(p, p + 5);
	iter_type it = src.begin();
	ft::vector<int>::reverse_iterator rit(it + 5);
	it += 4;
	for (int i = 0; i < 5; i++, rit++, it--) {
		if (*rit != *it) {
			equal = false;
		}
	}
	unit.assertTrue(equal, "Expect: True; rit(it + 5), it+=4, *rit++ == *it--)");

	for (int i = 0; i < 5; i++, rit--, it++) {
		if (*(rit - 1) != *(it + 1)) {
			equal = false;
		}
	}
	unit.assertTrue(equal, "Expect: True; *rit-- == *it++)");

	for (int i = 0; i < 5; i++) {
		if (*it != *rit) {
			equal = false;
		}
		++rit;
		--it;
	}
	unit.assertTrue(equal, "Expect: True; *++it == *rit");
	for (int i = 0; i < 5; i++) {
		if (*(it + 1) != *(rit - 1)) {
			equal = false;
		}
		--rit;
		++it;
	}
	unit.assertTrue(equal, "Expect: True; *--it == *--rit");
	delete[] tmp;
}

void rerverseCompoundAssignmentOperations(UnitTest unit) {
	std::string *names = new std::string[5];
	names[0] = "Luigi";
	names[1] = "Caio";
	names[2] = "Rafa";
	names[3] = "Adrian";
	names[4] = "Gustavo";
	ft::vector<std::string>src(names, names + 5);
	ft::vector<std::string>::reverse_iterator it(src.end());
	it += 3;
	unit.assertTrue(!(*it).compare("Caio"), "Expected: True; it += 3, *it == Caio");
	unit.assertFalse(!(*it).compare("Rafa"), "Expected: Fase; it += 3, *it == Rafa");

	it -= 2;
	std::cout << *it << std::endl;
	unit.assertTrue(!(*it).compare("Adrian"), "Expected: True; it -= 2, *it == Adrian");
	unit.assertFalse(!(*it).compare("Gustavo"), "Expected: False; it -= 2, *it == Gustavo");
	delete[] names;
}
