/*
  Programmer: Oliver Thompson
  File: test_set.h
  Tests the Set class
*/
#ifndef TEST_SET_H
#define TEST_SET_H
#include<cppunit/extensions/HelperMacros.h>
#include<cppunit/config/SourcePrefix.h>
#include"set.h"

class Test_set : public CPPUNIT_NS::TestFixture
{
 public:
  Test_set();
  
 private:
  CPPUNIT_TEST_SUITE(Test_set);
  CPPUNIT_TEST(test_default_constructor);
  CPPUNIT_TEST(test_union);
  CPPUNIT_TEST(test_intersection);
  CPPUNIT_TEST(test_difference);
  CPPUNIT_TEST_SUITE_END();
  unsigned int TEST_MAXX;

 protected:
  void test_default_constructor();
  void test_union();
  void test_intersection();
  void test_difference();
};

#endif

