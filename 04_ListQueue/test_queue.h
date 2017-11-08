/*
  File: test_queue.h
  Author: Oliver Thompson
  Tests the Queue class
*/
#ifndef TEST_LIST_H
#define TEST_LIST_H

#include<cppunit/extensions/HelperMacros.h>
#include<cppunit/config/SourcePrefix.h>
#include<stdexcept>
using std::out_of_range;
#include<iostream>
using std::cout;
using std::endl;

#include"queue.h"
class Test_queue : public CPPUNIT_NS::TestFixture
{
 public:
  Test_queue();

 private:
  CPPUNIT_TEST_SUITE(Test_queue);
  CPPUNIT_TEST(test_default_constructor);
  CPPUNIT_TEST(test_copy_constructor);
  CPPUNIT_TEST(test_push);
  CPPUNIT_TEST(test_pop);
  CPPUNIT_TEST_SUITE_END();
  unsigned int TEST_MAX;

 protected:
  void test_default_constructor();
  void test_copy_constructor();
  void test_push();
  void test_pop();
};

#endif

