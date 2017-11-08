/*
  Programmer: Oliver Thompson
  File: test_priority_queue.cpp
  Tests Priority Queues
*/

#include"test_priority_queue.h"
#include<iostream>
using namespace std;

CPPUNIT_TEST_SUITE_REGISTRATION(Test_priority_queue);

Test_priority_queue::Test_priority_queue() : TREE_SIZE(5000)
{
}

void Test_priority_queue::test_push()
{
  cout << "TEST PUSH" << endl;

  Priority_queue<int> p;
  for(int i=1; i <= 3000; i++)
  {
    p.push(i);
  }

  p.push(7000);

  for(int i=4999; i > 3000; i--)
  {
    p.push(i);
  }

  CPPUNIT_ASSERT(p.top() == 7000);
  CPPUNIT_ASSERT(p.size() == TREE_SIZE);

  cout<< "PASSED" << endl;
}

void Test_priority_queue::test_pop()
{
  cout << "TEST POP" << endl;

  Priority_queue<int> p;

  for(int i=1; i <= TREE_SIZE; i++)
  {
    p.push(i);
  }

  for(int i=0; i < 1000; i++)
  {
    p.pop();
  }

  CPPUNIT_ASSERT(p.top() == (TREE_SIZE - 1000));
  CPPUNIT_ASSERT(p.size() == (TREE_SIZE - 1000));

  cout << "PASSED" << endl;
}

void Test_priority_queue::test_copy()
{
  cout << "TEST COPY CONSTRUCTOR" << endl;

  Priority_queue<int> p;

  for(int i=0; i<TREE_SIZE; i++)
  {
    p.push(i);
  }

  Priority_queue<int> q(p);

  CPPUNIT_ASSERT(q.top() == p.top());
  CPPUNIT_ASSERT(q.size() == p.size());

  cout << "PASSED" << endl;
}

