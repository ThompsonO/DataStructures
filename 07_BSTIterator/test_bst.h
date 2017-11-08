/*
  File: test_bst.h
  Author: Oliver Thompson
  Tests the BST class
*/

#ifndef TEST_BST_H
#define TEST_BST_H

#include<cppunit/extensions/HelperMacros.h>
#include<cppunit/config/SourcePrefix.h>
#include<stdexcept>
using std::out_of_range;
#include<iostream>
using std::cout;
using std::endl;

#include"bst.h"
class Test_bst : public CPPUNIT_NS::TestFixture
{
 public:
  Test_bst();

 private:
  CPPUNIT_TEST_SUITE(Test_bst);
  CPPUNIT_TEST(test_default_constructor);
  CPPUNIT_TEST(test_copy_constructor);
  CPPUNIT_TEST(test_remove);
  CPPUNIT_TEST(test_insert);
  CPPUNIT_TEST(test_assignment_operator);
  CPPUNIT_TEST_SUITE_END();
  unsigned int TEST_MAX;

 protected:
  void test_default_constructor();
  void test_copy_constructor();
  void test_remove();
  void test_insert();
  void test_assignment_operator();
};

#endif

