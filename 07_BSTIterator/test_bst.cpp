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

void Test_bst::test_copy_constructor()
{
  cout <<"TEST COPY CONSTRUCTOR" << endl;
  cout <<"checking copy constructor: ";
  BST<int> b;

  b.insert(5);
  b.insert(3);
  b.insert(1);
  b.insert(2);
  b.insert(4);
  b.insert(8);
  b.insert(6);
  b.insert(7);
  b.insert(9);

  BST<int> c(b);
  BTPreorderIterator<int> pc = c.pre_begin(); 

  for(BTPreorderIterator<int> pb = b.pre_begin(); pb != b.pre_end(); pb++)
  {
    CPPUNIT_ASSERT(*pb == *pc);
    pc++;
  }

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
  CPPUNIT_ASSERT((b.pre_search(15)) == false);
  cout << "PASSED" << endl;
}

void Test_bst::test_insert()
{
  BST<int> b;

  cout << "TEST INSERT" << endl;
  cout << "checking one insert: ";
  b.insert(5);
  CPPUNIT_ASSERT(b.size() == 1);
  CPPUNIT_ASSERT(*(b.in_search(5)) == 5);
  cout << "PASSED" << endl;

  cout << "checking multiple inserts: ";
  b.insert(3);
  b.insert(1);
  b.insert(2);
  b.insert(4);
  b.insert(8);
  b.insert(6);
  b.insert(7);
  b.insert(9);

  CPPUNIT_ASSERT(b.size() == 9);

  for(int i = 0; i < b.size(); i++)
  {
    CPPUNIT_ASSERT(*(b.in_search(i+1)) == i+1);
  }
  cout << "PASSED" << endl;
}

void Test_bst::test_assignment_operator()
{
  cout <<"TEST ASSIGNMENT OPERATOR" << endl;
  cout <<"checking assignment operator: ";
  BST<int> b;

  b.insert(5);
  b.insert(3);
  b.insert(1);
  b.insert(2);
  b.insert(4);
  b.insert(8);
  b.insert(6);
  b.insert(7);
  b.insert(9);

  BST<int> c;
  c = b;
  BTPostorderIterator<int> pc = c.post_begin(); 

  for(BTPostorderIterator<int> pb = b.post_begin(); pb != b.post_end(); pb++)
  {
    CPPUNIT_ASSERT(*pb == *pc);
    pc++;
  }

  cout << "PASSED" << endl;
}
