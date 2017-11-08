/*
  File: test_avl.cpp
  Author: Oliver Thompson
  Tests the AVL class
*/
#include<cstdlib>
#include<ctime>
#include<iostream>

using std::cout;
using std::endl;

#include"test_avl.h"

CPPUNIT_TEST_SUITE_REGISTRATION(Test_avl);

void Test_avl::test_default_constructor()
{
  cout << "TEST DEFAULT CONSTRUCTOR" << endl;

  AVL<int> a;
  CPPUNIT_ASSERT(a.empty() == true);
  CPPUNIT_ASSERT(a.size() == 0);

  cout << "PASSED" << endl;
}

void Test_avl::test_insert_pospos()
{
  cout << "TEST INSERT POSPOS" << endl;

  AVL<int> a;
  int answer[] = {8, 4, 2, 1, 3, 6, 5, 7, 12, 10, 9, 11, 14, 13, 15};

  for(int i=1; i <=15; i++)
  {
    a.insert(i);
  }

  int j = 0;
  for(BTPreorderIterator<int> i = a.pre_begin(); i != a.pre_end(); i++, j++)
  {
    CPPUNIT_ASSERT(*i == answer[j]);
  }

  cout << "PASSED" << endl;
}

void Test_avl::test_insert_posneg()
{
  cout << "TEST INSERT POSNEG" << endl;

  AVL<int> a;
  int answer[] = {8, 4, 2, 1, 3, 6, 5, 7, 12, 10, 9, 11, 14, 13, 15};

  a.insert(1);
  a.insert(3);
  a.insert(2);
  a.insert(5);
  a.insert(4);
  a.insert(7);
  a.insert(6);
  a.insert(9);
  a.insert(8);
  a.insert(11);
  a.insert(10);
  a.insert(13);
  a.insert(12);
  a.insert(15);
  a.insert(14);

  int j = 0;
  for(BTPreorderIterator<int> i = a.pre_begin(); i != a.pre_end(); i++, j++)
  {
    CPPUNIT_ASSERT(*i == answer[j]);
  }

  cout << "PASSED" << endl;
}

void Test_avl::test_insert_negpos()
{
  cout << "TEST INSERT NEGPOS" << endl;

  AVL<int> a;
  int answer[] = {8, 4, 2, 1, 3, 6, 5, 7, 12, 10, 9, 11, 14, 13, 15};

  a.insert(15);
  a.insert(13);
  a.insert(14);
  a.insert(11);
  a.insert(12);
  a.insert(9);
  a.insert(10);
  a.insert(7);
  a.insert(8);
  a.insert(5);
  a.insert(6);
  a.insert(3);
  a.insert(4);
  a.insert(1);
  a.insert(2);

  int j = 0;
  for(BTPreorderIterator<int> i = a.pre_begin(); i != a.pre_end(); i++, j++)
  {
    CPPUNIT_ASSERT(*i == answer[j]);
  }

  cout << "PASSED" << endl;
}

void Test_avl::test_insert_negneg()
{
  cout << "TEST INSERT NEGNEG" << endl;

  AVL<int> a;
  int answer[] = {8, 4, 2, 1, 3, 6, 5, 7, 12, 10, 9, 11, 14, 13, 15};

  for(int i=15; i <=1; i--)
  {
    a.insert(i);
  }

  int j = 0;
  for(BTPreorderIterator<int> i = a.pre_begin(); i != a.pre_end(); i++, j++)
  {
    CPPUNIT_ASSERT(*i == answer[j]);
  }

  cout << "PASSED" << endl;
}

void Test_avl::test_remove()
{
  cout << "TEST REMOVE" << endl;

  AVL<int> a;
  int answer[] = {8, 2, 1, 6, 5, 7, 12, 10, 9, 14, 15};

  for(int i=1; i <=15; i++)
  {
    a.insert(i);
  }

  a.remove(4);
  a.remove(3);
  a.remove(11);
  a.remove(13);

  int j = 0;
  for(BTPreorderIterator<int> i = a.pre_begin(); i != a.pre_end(); i++, j++)
  {
   
    CPPUNIT_ASSERT(*i == answer[j]);
  }

  cout << "PASSED" << endl;
}

