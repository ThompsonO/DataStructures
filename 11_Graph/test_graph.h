/*
  Programmer: Oliver Thompson
  File: test_graph.h
  Tests Graphs
*/

#ifndef TEST_GRAPH_H
#define TEST_GRAPH_H

#include<cppunit/extensions/HelperMacros.h>
#include<cppunit/config/SourcePrefix.h>
#include"graph.h"

class Test_graph : public CPPUNIT_NS::TestFixture
{
 public:
  Test_graph();
 private:
  CPPUNIT_TEST_SUITE(Test_graph);
  CPPUNIT_TEST(test_quickest_path);
  CPPUNIT_TEST_SUITE_END();

 protected:
  void test_quickest_path();
};

#endif

