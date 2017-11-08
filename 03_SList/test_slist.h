/*
  File: test_slist.h
  Author: Oliver Thompson
  Tests the SList class
*/
#ifndef TEST_SLIST_H
#define TEST_SLIST_H

#include<cppunit/extensions/HelperMacros.h>
#include<cppunit/config/SourcePrefix.h>
#include<stdexcept>
using std::out_of_range;
#include<iostream>
using std::cout;
using std::endl;

#include"slist.h"
class Test_slist : public CPPUNIT_NS::TestFixture
{
 public:
  Test_slist();

 private:
  CPPUNIT_TEST_SUITE(Test_slist);
  CPPUNIT_TEST(test_default_constructor);
  CPPUNIT_TEST(test_copy_constructor);
  CPPUNIT_TEST(test_push_front);
  CPPUNIT_TEST(test_pop_front);
  CPPUNIT_TEST(test_remove);
  CPPUNIT_TEST(test_assignment_operator);
  CPPUNIT_TEST_SUITE_END();
  unsigned int TEST_MAX;

 protected:
  void test_default_constructor();
  void test_copy_constructor();
  void test_push_front();
  void test_pop_front();
  void test_remove();
  void test_assignment_operator();
};

#endif



