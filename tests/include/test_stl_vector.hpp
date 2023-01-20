#ifndef VECTOR_HPP
#define VECTOR_HPP


/*
** Normal Iterator
*/
void testCompareOperators(UnitTest& unit);
void testConstructors(UnitTest& unit);
void TestCompoundAssignmentOperations(UnitTest& unit);
void offsetDereferenceOperator(UnitTest& unit);
void testIncrementedDecremented(UnitTest& unit);

void rerverseCompoundAssignmentOperations(UnitTest& unit);
void testReverseIteratorIncrementedDecremented(UnitTest& unit);
void reverseOffsetDereferenceOperator(UnitTest& unit);
void reverseBaseFunction(UnitTest& unit);
void reverseDereference(UnitTest& unit);

void testVectorIterator(UnitTest& unit);
void testVectorCapacity(UnitTest& unit);
void testVectorModifiers(UnitTest& unit);

void testVectorPushBack(UnitTest& unit);
void testVectorPopBack(UnitTest& unit);

void testVectorInsertRange(UnitTest& unit);
void testVectorInsertSingleElement(UnitTest& unit);
void testVectorInsertFillElements(UnitTest &unit);

void testVectorErase(UnitTest& unit);
void testVectorEraseRange(UnitTest& unit);

void testVectorClear(UnitTest& unit);

void testVectorElementsAcess(UnitTest& unit);
void testVectorConstructors(UnitTest& unit);
#endif
