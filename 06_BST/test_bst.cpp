/*
  File: test_bst.cpp
  Author: Oliver Thompson
  Tests the BST class
*/

#include"test_bst.h"

CPPUNIT_TEST_SUITE_REGISTRATION(Test_bst);

Test_bst::Test_bst() : TEST_MAX(500)
{}

void Test_bst::test_default_constructor()
{
  BST<int> b;

  cout << endl << "TEST DEFAULT CONSTRUCTOR" << endl;
  cout << "checking that size is 0: ";
  CPPUNIT_ASSERT(b.size() == 0);
  cout << "PASSED" << endl;

  cout << "checking that front is null: ";
  CPPUNIT_ASSERT(b.empty() == true);
  cout << "PASSED" << endl;
}

void Test_bst::test_remove()
{
  BST<int> b;

  cout << endl << "TEST REMOVE" << endl;
  cout << "checking one item remove: ";
  b.insert(15);
  b.remove(15);
  CPPUNIT_ASSERT(b.empty() == true);
  cout << "PASSED" << endl;

  cout << "checking multiple removes: ";
  b.insert(15);
  b.insert(7);
  b.insert(30);
  b.insert(4);
  b.insert(9);
  b.insert(8);
  b.insert(25);
  b.insert(27);
  b.insert(42);
  b.insert(38);

  b.remove(4);
  b.remove(30);
  b.remove(15);
  CPPUNIT_ASSERT(b.size() == 7);
  CPPUNIT_ASSERT(b.search(15) == false);
  cout << "PASSED" << endl;
}

void Test_bst::test_insert()
{
  BST<int> b;

  cout << "TEST INSERT" << endl;
  cout << "checking one insert: ";
  b.insert(53);
  CPPUNIT_ASSERT(b.size() == 1);
  CPPUNIT_ASSERT(b.search(53) == true);
  cout << "PASSED" << endl;

  cout << "checking multiple inserts: ";
  b.insert(23);
  b.insert(42);
  b.insert(12);
  b.insert(15);
  b.insert(13);
  b.insert(7);
  b.insert(9);
  b.insert(75);
  b.insert(63);
  b.insert(54);
  b.insert(79);
  b.insert(77);

  CPPUNIT_ASSERT(b.size() == 13);
  CPPUNIT_ASSERT(b.search(75) == true);
  CPPUNIT_ASSERT(b.search(63) == true);
  CPPUNIT_ASSERT(b.search(12) == true);
  CPPUNIT_ASSERT(b.search(7) == true);
  CPPUNIT_ASSERT(b.search(79) == true);
  CPPUNIT_ASSERT(b.search(54) == true);
  cout << "PASSED" << endl;
}
