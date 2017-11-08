/*
  File: test_avl.h
  Author: Oliver Thompson
  Tests the AVL class
*/
#ifndef TEST_AVL_H
#define TEST_AVL_H

#include<cppunit/extensions/HelperMacros.h>
#include<cppunit/config/SourcePrefix.h>
#include"avl.h"

class Test_avl : public CPPUNIT_NS::TestFixture
{
 private:
  CPPUNIT_TEST_SUITE(Test_avl);
  CPPUNIT_TEST(test_default_constructor);
  CPPUNIT_TEST(test_insert_pospos);
  CPPUNIT_TEST(test_insert_posneg);
  CPPUNIT_TEST(test_insert_negpos);
  CPPUNIT_TEST(test_insert_negneg);
  CPPUNIT_TEST(test_remove);
  CPPUNIT_TEST_SUITE_END();

 protected:
  void test_default_constructor();
  void test_insert_pospos();
  void test_insert_posneg();
  void test_insert_negpos();
  void test_insert_negneg();
  void test_remove();
};

#endif

