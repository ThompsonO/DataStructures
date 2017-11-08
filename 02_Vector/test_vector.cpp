/*
  File: test_vector.cpp
  Author: Oliver Thompson
  Tests the vector class
*/
#include "test_vector.h"
#include "math.h"

CPPUNIT_TEST_SUITE_REGISTRATION(Test_vector);

Test_vector :: Test_vector() : TEST_MAX(5000)
{
}

void Test_vector :: test_default_constructor()
{
  Vector<int> v;

  cout << endl << "TEST DEFAULT CONSTRUCTOR" << endl;
  cout << "checking that size is 0: ";
  CPPUNIT_ASSERT(v.size() == 0);
  cout << "PASSED" << endl;

  cout << "checking that max_size is 1: ";
  CPPUNIT_ASSERT(v.max_size() == 1);
  cout << "PASSED" << endl;
}

void Test_vector :: test_push_back()
{
  Vector<int> v;

  cout << endl << "TEST PUSH BACK" << endl;
  cout << "checking one push: ";
  v.push_back(3);
  CPPUNIT_ASSERT(v[0] == 3);
  CPPUNIT_ASSERT(v.size() == 1);
  CPPUNIT_ASSERT(v.max_size() == 1);
  cout << "PASSED" << endl;

  cout << "checking push twice: ";
  v.push_back(1);
  CPPUNIT_ASSERT(v[0] == 3);
  CPPUNIT_ASSERT(v[1] == 1);
  CPPUNIT_ASSERT(v.size() == 2);
  CPPUNIT_ASSERT(v.max_size() == 2);
  cout << "PASSED" << endl;

  cout << "checking multiple pushes: ";
  for(int i = v.size(); i < TEST_MAX; i++)
  {
    v.push_back(i);
    CPPUNIT_ASSERT(v[i] == i);
    CPPUNIT_ASSERT(v.size() == i+1);
    CPPUNIT_ASSERT(v.max_size() == pow(2, floor(log(i)/log(2))+1));
  }
  cout << "PASSED" << endl;
}

void Test_vector :: test_clear()
{
  Vector<int> v;

  cout << endl << "TEST CLEAR" << endl;
  cout << "checking vector clear: ";
  for(int i = v.size(); i < TEST_MAX; i++)
  {
    v.push_back(i);
  }
  v.clear();
  CPPUNIT_ASSERT(v.size() == 0);
  CPPUNIT_ASSERT(v.max_size() == 1);
  cout << "PASSED" << endl;

  cout << "checking empty vector clear: ";
  v.clear();
  CPPUNIT_ASSERT(v.size() == 0);
  CPPUNIT_ASSERT(v.max_size() == 1);
  cout << "PASSED" << endl;
}

void Test_vector :: test_copy_constructor()
{
  Vector<int> v;

  cout << endl << "TEST COPY CONSTRUCTOR" << endl;
  cout << "checking copy from vector: ";

  for(int i = 0; i < TEST_MAX; i++)
  {
    v.push_back(i);
  }

  Vector<int> vv(v);

  for(int j = 0; j < TEST_MAX; j++)
  {
   CPPUNIT_ASSERT (vv[j] == v[j]);
  }
  cout << "PASSED" << endl;

  cout << "checking empty copy: ";
  v.clear();
  Vector<int> vvv(v);
  CPPUNIT_ASSERT(vvv.size() == v.size());
  CPPUNIT_ASSERT(vvv.size() == 0);
  CPPUNIT_ASSERT(vvv.max_size() == v.max_size());
  CPPUNIT_ASSERT(vvv.max_size() == 1);
  cout << "PASSED" << endl;
}

void Test_vector :: test_assignment_operator()
{
  Vector<int> v, vv, vvv;

  cout << endl << "TEST ASSIGNMENT OPERATOR" << endl;
  cout << "checking when empty: ";
  vv = v;
  CPPUNIT_ASSERT(vv.size() == 0);
  CPPUNIT_ASSERT(vv.max_size() == 1);
  cout << "PASSED" << endl;

  cout << "checking when full: ";
  for(int i = 0; i < TEST_MAX; i++)
  {
    v.push_back(i);
  }
  vvv = v;
  CPPUNIT_ASSERT(v.size() == vvv.size());
  CPPUNIT_ASSERT(v.max_size() == vvv.max_size());
  for(unsigned int i = 0; i < v.size(); i++)
  {
    CPPUNIT_ASSERT(v[i] == vvv[i]);
  }
  cout << "PASSED" << endl;
}

void Test_vector :: test_pop_back()
{
  Vector<int> v;

  cout << endl << "TEST POP BACK" << endl;
  cout << "checking one pop: ";
  v.push_back(24);
  v.pop_back();
  CPPUNIT_ASSERT(v.size() == 0);
  CPPUNIT_ASSERT(v.max_size() == 1);
  cout << "PASSED" << endl;

  cout << "checking multiple pops: ";
  for(int i = 0; i < TEST_MAX; i++)
  {
    v.push_back(i);
  }

  for(int j = TEST_MAX; j > 1; j--)
  {
    v.pop_back();
    CPPUNIT_ASSERT(v.size() == (j-1));

    CPPUNIT_ASSERT(v.max_size() <= (v.size()*4));
  }
  cout << "PASSED" << endl;

  cout << "checking empty pop: ";
  v.clear();
  v.pop_back();
  CPPUNIT_ASSERT(v.size() == 0);
  CPPUNIT_ASSERT(v.max_size() == 1);
  cout << "PASSED" << endl;
}

void Test_vector :: test_bracket_operator()
{
  Vector<int> v;

  cout << endl << "TEST BRACKET OPERATOR" << endl;
  cout << "checking write exception: ";
  try
  {
    v[1] = 50;
    CPPUNIT_ASSERT(false);
  }
  catch(out_of_range& e)
  {
    cout << "PASSED" << endl;
  }

  cout << "checking read exception: ";
  try
  {
    int test = v[1];
    CPPUNIT_ASSERT(false);
  }
  catch(out_of_range& e)
  {
    cout << "PASSED" << endl;
  }
}

