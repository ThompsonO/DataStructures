/*
  Programmer: Oliver Thompson
  File: test_set.cpp
  Tests the Set class
*/
#include<cstdlib>
#include<ctime>
#include<iostream>
using std::cout;
using std::endl;
#include"test_set.h"

CPPUNIT_TEST_SUITE_REGISTRATION(Test_set);

Test_set::Test_set() : TEST_MAXX(500)
{
}

void Test_set::test_default_constructor()
{
  cout << "TEST DEFAULT CONSTRUCTOR" << endl;
  Set<int> s;
  CPPUNIT_ASSERT(s.size() == 0);
  cout << "PASSED" << endl;
}

void Test_set::test_union()
{
  cout << "TEST UNION" << endl;
  Set<int> s, t, u;

  int sa[] = {1,2,3,4,5,6,7,8,9};
  int ta[] = {6,7,8,9,10,11,12,13,14};
  int ua[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14};

  for(int i=0; i<9; i++)
  {
    s.insert(sa[i]);
    t.insert(ta[i]);
  }

  u = s + t;

  BTInorderIterator<int> i = u.begin();
  for(int j=0; j<u.size(); i++,j++)
  {
    CPPUNIT_ASSERT(ua[j] == *i);
  }

  cout << "PASSED" << endl;
}

void Test_set::test_intersection()
{
  cout << "TEST UNION" << endl;
  Set<int> s, t, u;

  int sa[] = {1,2,3,4,5,6,7,8,9};
  int ta[] = {6,7,8,9,10,11,12,13,14};
  int ua[] = {6,7,8,9};

  for(int i=0; i<9; i++)
  {
    s.insert(sa[i]);
    t.insert(ta[i]);
  }

  u = s * t;

  BTInorderIterator<int> i = u.begin();
  for(int j=0; j<u.size(); i++,j++)
  {
    CPPUNIT_ASSERT(ua[j] == *i);
  }

  cout << "PASSED" << endl;
}

void Test_set::test_difference()
{
  cout << "TEST UNION" << endl;
  Set<int> s, t, u;

  int sa[] = {1,2,3,4,5,6,7,8,9};
  int ta[] = {6,7,8,9,10,11,12,13,14};
  int ua[] = {1,2,3,4,5};

  for(int i=0; i<9; i++)
  {
    s.insert(sa[i]);
    t.insert(ta[i]);
  }

  u = s - t;

  BTInorderIterator<int> i = u.begin();
  for(int j=0; j<u.size(); i++,j++)
  {
    CPPUNIT_ASSERT(ua[j] == *i);
  }

  cout << "PASSED" << endl;
}

