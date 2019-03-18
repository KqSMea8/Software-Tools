#include "mytest.h"
#include <string>

// default constructor
//
MyTest::MyTest()
{
  const char* name();
}

//constructor
//
MyTest::MyTest(int input):num(input)
{
  //defninitions for class
  //
  const char* name();
  int set_debug(int input);

}


////////////////////
//member functions//
////////////////////

//return name of class
//
const char* MyTest::name()
{
  //defines NAME
  //
  const char* NAME = "MyTest";

  //returns name of class
  //
  return NAME;

}

int MyTest::set_debug(int input)
{

  //  fprintf(stdout, "%d\n", input);
  return input;
}
/*
void mytest::debug(void)
{


}

void mytest::compute(void)
{


}

void mytest::reset(void)

{

}
*/


