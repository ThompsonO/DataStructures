/*
  File: test_queue.cpp
  Author: Oliver Thompson
  Tests the Queue class
*/
#include"test_queue.h"

CPPUNIT_TEST_SUITE_REGISTRATION(Test_queue);

Test_queue::Test_queue() : TEST_MAX(500)
{}

void Test_queue::test_default_constructor()
{
  Queue<int> q;

  cout << endl << "TEST DEFAULT CONSTRUCTOR" << endl;
  cout << "checking that size is 0: ";
  CPPUNIT_ASSERT(q.size() == 0);
  cout << "PASSED" << endl;

  cout << "checking that front is null: ";
  CPPUNIT_ASSERT(q.empty() == true);
  cout << "PASSED" << endl;
}

void Test_queue::test_copy_constructor()
{
  Queue<int> q;

  cout << endl << "TEST COPY CONSTRUCTOR" << endl;
  cout << "checking copy: ";
  for(int i = 0; i < TEST_MAX; i++)
  {
    q.push(i);
  }
  Queue<int> t(q);
  for(int i = TEST_MAX; i > 1; i--)
  {
    CPPUNIT_ASSERT(q.front() == t.front());
    q.pop();
    t.pop();
  }
  cout << "PASSED" << endl;
}

void Test_queue::test_push()
{
  Queue<int> q;

  cout << endl << "TEST PUSH" << endl;
  cout << "checking one push: ";
  q.push(15);
  CPPUNIT_ASSERT(q.size() == 1);
  CPPUNIT_ASSERT(q.back() == 15);
  cout << "PASSED" << endl;

  cout << "checking multiple pushes: ";
  for(int i = q.size(); i < TEST_MAX; i++)
  {
    q.push(i);
    CPPUNIT_ASSERT(q.size() == i+1);
    CPPUNIT_ASSERT(q.back() == i);
  }
  cout << "PASSED" << endl;
}

void Test_queue::test_pop()
{
  Queue<int> q;

  cout << endl << "TEST POP" << endl;
  cout << "checking one pop: ";
  q.push(35);
  q.pop();
  CPPUNIT_ASSERT(q.size() == 0);
  CPPUNIT_ASSERT(q.empty() == true);
  cout << "PASSED" << endl;

  cout << "checking multiple pops: ";
  for(int i = q.size(); i < TEST_MAX; i++)
  {
    q.push(i);
  }
  for(int i = 0; i < TEST_MAX; i++)
  {
    q.pop();
    CPPUNIT_ASSERT(q.size() == (TEST_MAX-1-i));
    if(q.empty() == false)
    {
      CPPUNIT_ASSERT(q.front() == (i+1));
    }
  }
  cout << "PASSED" << endl;

  cout << "checking empty pop: ";
  q.clear();
  q.pop();
  CPPUNIT_ASSERT(q.empty() == true);
  cout << "PASSED" << endl;
}

