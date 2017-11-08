/*
  File: test_slist.cpp
  Author: Oliver Thompson
  Tests the SList class
*/
#include"test_slist.h"

CPPUNIT_TEST_SUITE_REGISTRATION(Test_slist);

Test_slist::Test_slist() : TEST_MAX(500)
{}

void Test_slist::test_default_constructor()
{
  SList<int> s;

  cout << endl << "TEST DEFAULT CONSTRUCTOR" << endl;
  cout << "checking that size is 0: ";
  CPPUNIT_ASSERT(s.size() == 0);
  cout << "PASSED" << endl;

  cout << "checking that front is null: ";
  CPPUNIT_ASSERT(s.empty() == true);
  CPPUNIT_ASSERT(s.begin() == s.end());
  cout << "PASSED" << endl;
}

void Test_slist::test_copy_constructor()
{
  SList<int> s;

  cout << endl << "TEST COPY CONSTRUCTOR" << endl;
  cout << "checking copy: ";
  for(int i = 0; i < TEST_MAX; i++)
  {
    s.push_front(i);
  }
  SList<int> t(s);
  for(int i = TEST_MAX; i > 0; i--)
  {
    CPPUNIT_ASSERT(s.front() == t.front());
    s.pop_front();
    t.pop_front();
  }
  cout << "PASSED" << endl;
}

void Test_slist::test_push_front()
{
  SList<int> s;

  cout << endl << "TEST PUSH FRONT" << endl;
  cout << "checking one push: ";
  s.push_front(15);
  CPPUNIT_ASSERT(s.size() == 1);
  CPPUNIT_ASSERT(s.front() == 15);
  cout << "PASSED" << endl;

  cout << "checking multiple pushes: ";
  for(int i = s.size(); i < TEST_MAX; i++)
  {
    s.push_front(i);
    CPPUNIT_ASSERT(s.size() == i+1);
    CPPUNIT_ASSERT(s.front() == i);
  }
  cout << "PASSED" << endl;
}

void Test_slist::test_pop_front()
{
  SList<int> s;

  cout << endl << "TEST POP FRONT" << endl;
  cout << "checking one pop: ";
  s.push_front(35);
  s.pop_front();
  CPPUNIT_ASSERT(s.size() == 0);
  CPPUNIT_ASSERT(s.empty() == true);
  cout << "PASSED" << endl;

  cout << "checking multiple pops: ";
  for(int i = s.size(); i < TEST_MAX; i++)
  {
    s.push_front(i);
  }
  for(int i = TEST_MAX; i > 0; i--)
  {
    s.pop_front();
    CPPUNIT_ASSERT(s.size() == i-1);
    if(s.empty() == false)
    {
      CPPUNIT_ASSERT(s.front() == i-2);
    }
  }
  cout << "PASSED" << endl;

  cout << "checking empty pop: ";
  s.clear();
  s.pop_front();
  CPPUNIT_ASSERT(s.empty() == true);
  cout << "PASSED" << endl;
}

void Test_slist::test_remove()
{
  SList<int> s;

  cout << endl << "TEST REMOVE" << endl;
  cout << "checking one item remove: ";
  s.push_front(15);
  s.remove(15);
  CPPUNIT_ASSERT(s.empty() == true);
  cout << "PASSED" << endl;

  cout << "checking multiple removes: ";
  s.push_front(15);
  s.push_front(7);
  s.push_front(15);
  s.push_front(7);
  s.push_front(15);
  s.remove(15);
  CPPUNIT_ASSERT(s.front() == 7);
  CPPUNIT_ASSERT(s.size() == 2);
  s.remove(7);
  CPPUNIT_ASSERT(s.empty() == true);
  cout << "PASSED" << endl;
}

void Test_slist::test_assignment_operator()
{
  SList<int> s, t;

  cout << endl << "TEST ASSIGNMENT OPERATOR" << endl;
  cout << "checking assignment: ";
  for(int i = 0; i < TEST_MAX; i++)
  {
    s.push_front(i);
  }
  t = s;
  SList<int>::Iterator sI, tI;
  for(sI = s.begin(), tI = t.begin(); sI != s.end(); sI++, tI++)
  {
    CPPUNIT_ASSERT(*sI == *tI);
  }
  cout << "PASSED" << endl;

  cout << "checking empty assignment: ";
  s.clear();
  t = s;
  CPPUNIT_ASSERT(s.size() == t.size());
  CPPUNIT_ASSERT(s.empty() == true);
  CPPUNIT_ASSERT(s.empty() == t.empty());
  cout << "PASSED" << endl;  
}

