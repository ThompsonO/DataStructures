/*
  File: main.cpp
  Author: Oliver Thompson
  Tests classes
*/

#include<cppunit/extensions/TestFactoryRegistry.h>
#include<cppunit/ui/text/TestRunner.h>

int main()
{
  CppUnit::TextUi::TestRunner runner;
  CppUnit::TestFactoryRegistry& registry = CppUnit::TestFactoryRegistry::getRegistry();
  runner.addTest(registry.makeTest());
  return runner.run("", false) ? 0 : 1;
}

