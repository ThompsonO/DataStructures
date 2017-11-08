/*
  File: test_list.cpp
  Author: Oliver Thompson
  Tests the List class
*/
#include"test_list.h"

CPPUNIT_TEST_SUITE_REGISTRATION(Test_list);

Test_list::Test_list() : TEST_MAX(500)
{}

void Test_list::test_default_constructor()
{
  List<int> l;

  cout << endl << "TEST DEFAULT CONSTRUCTOR" << endl;
  cout << "checking that size is 0: ";
  CPPUNIT_ASSERT(l.size() == 0);
  cout << "PASSED" << endl;

  cout << "checking that front is null: ";
  CPPUNIT_ASSERT(l.empty() == true);
  CPPUNIT_ASSERT(l.begin() == l.end());
  cout << "PASSED" << endl;
}

void Test_list::test_copy_constructor()
{
  List<int> l;

  cout << endl << "TEST COPY CONSTRUCTOR" << endl;
  cout << "checking copy: ";
  for(int i = 0; i < TEST_MAX; i++)
  {
    l.push_front(i);
  }
  List<int> t(l);
  for(int i = TEST_MAX; i > 1; i--)
  {
    CPPUNIT_ASSERT(l.front() == t.front());
    l.pop_front();
    t.pop_front();
  }
  cout << "PASSED" << endl;
}

void Test_list::test_push_front()
{
  List<int> l;

  cout << endl << "TEST PUSH FRONT" << endl;
  cout << "checking one push: ";
  l.push_front(15);
  CPPUNIT_ASSERT(l.size() == 1);
  CPPUNIT_ASSERT(l.front() == 15);
  CPPUNIT_ASSERT(l.back() == 15);
  cout << "PASSED" << endl;

  cout << "checking multiple pushes: ";
  for(int i = l.size(); i < TEST_MAX; i++)
  {
    l.push_front(i);
    CPPUNIT_ASSERT(l.size() == i+1);
    CPPUNIT_ASSERT(l.front() == i);
  }
  cout << "PASSED" << endl;
}

void Test_list::test_pop_front()
{
  List<int> l;

  cout << endl << "TEST POP FRONT" << endl;
  cout << "checking one pop: ";
  l.push_front(35);
  l.pop_front();
  CPPUNIT_ASSERT(l.size() == 0);
  CPPUNIT_ASSERT(l.empty() == true);
  cout << "PASSED" << endl;

  cout << "checking multiple pops: ";
  for(int i = l.size(); i < TEST_MAX; i++)
  {
    l.push_front(i);
  }
  for(int i = TEST_MAX; i > 0; i--)
  {
    l.pop_front();
    CPPUNIT_ASSERT(l.size() == i-1);
    if(l.empty() == false)
    {
      CPPUNIT_ASSERT(l.front() == i-2);
    }
  }
  cout << "PASSED" << endl;

  cout << "checking empty pop: ";
  l.clear();
  l.pop_front();
  CPPUNIT_ASSERT(l.empty() == true);
  cout << "PASSED" << endl;
}

void Test_list::test_push_back()
{
  List<int> l;

  cout << endl << "TEST PUSH BACK" << endl;
  cout << "checking one push: ";
  l.push_back(15);
  CPPUNIT_ASSERT(l.size() == 1);
  CPPUNIT_ASSERT(l.back() == 15);
  cout << "PASSED" << endl;

  cout << "checking multiple pushes: ";
  for(int i = l.size(); i < TEST_MAX; i++)
  {
    l.push_back(i);
    CPPUNIT_ASSERT(l.size() == i+1);
    CPPUNIT_ASSERT(l.back() == i);
  }
  cout << "PASSED" << endl;
}

void Test_list::test_pop_back()
{
  List<int> l;

  cout << endl << "TEST POP BACK" << endl;
  cout << "checking one pop: ";
  l.push_back(35);
  l.pop_back();
  CPPUNIT_ASSERT(l.size() == 0);
  CPPUNIT_ASSERT(l.empty() == true);
  cout << "PASSED" << endl;

  cout << "checking multiple pops: ";
  for(int i = l.size(); i < TEST_MAX; i++)
  {
    l.push_back(i);
  }
  for(int i = TEST_MAX; i > 0; i--)
  {
    l.pop_back();
    CPPUNIT_ASSERT(l.size() == i-1);
    if(l.empty() == false)
    {
      CPPUNIT_ASSERT(l.back() == i-2);
    }
  }
  cout << "PASSED" << endl;

  cout << "checking empty pop: ";
  l.clear();
  l.pop_back();
  CPPUNIT_ASSERT(l.empty() == true);
  cout << "PASSED" << endl;
}

void Test_list::test_remove()
{
  List<int> l;

  cout << endl << "TEST REMOVE" << endl;
  cout << "checking one item remove: ";
  l.push_front(15);
  l.remove(15);
  CPPUNIT_ASSERT(l.empty() == true);
  cout << "PASSED" << endl;

  cout << "checking multiple removes: ";
  l.push_front(15);
  l.push_front(7);
  l.push_front(15);
  l.push_front(7);
  l.push_front(15);
  l.remove(15);
  CPPUNIT_ASSERT(l.front() == 7);
  CPPUNIT_ASSERT(l.back() == 7);
  CPPUNIT_ASSERT(l.size() == 2);
  l.remove(7);
  CPPUNIT_ASSERT(l.empty() == true);
  cout << "PASSED" << endl;
}

void Test_list::test_assignment_operator()
{
  List<int> l, t;

  cout << endl << "TEST ASSIGNMENT OPERATOR" << endl;
  cout << "checking assignment: ";
  for(int i = 0; i < TEST_MAX; i++)
  {
    l.push_front(i);
  }
  t = l;
  List<int>::Iterator lI, tI;
  for(lI = l.begin(), tI = t.begin(); lI != l.end(); lI++, tI++)
  {
    CPPUNIT_ASSERT(*lI == *tI);
  }
  cout << "PASSED" << endl;

  cout << "checking empty assignment: ";
  l.clear();
  t = l;
  CPPUNIT_ASSERT(l.size() == t.size());
  CPPUNIT_ASSERT(l.empty() == true);
  CPPUNIT_ASSERT(l.empty() == t.empty());
  cout << "PASSED" << endl;
}

