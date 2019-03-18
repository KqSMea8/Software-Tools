#ifndef MYTEST_H
#define MYTEST_H

//including these libraries
//
#include <stdio.h>
#include <string>
#include <stdlib.h>

class MyTest
{
private:
  void reset();

  //compute functions
  //
  int compute_1();
  int compute_2();
  int compute_3();
  
public:
  //classes
  //
  MyTest(){};

  //class destructor
  //
  ~MyTest(){};

  //variables & ENUMS
  //
  enum debug_level{FULL=3, PARTIAL=2, BRIEF=1, NONE=0};
  debug_level options;
  enum ALGORITHM {one=1, two=2, three=3};
  static const char* NAME;  

  //methods
  //
  //method that returns function name
  //
  const char* name(){return NAME;};

  //method that sets debug level
  //
  int set_debug(int level);

  void debug(FILE* arg, int set_level);

  int compute( ALGORITHM value);
};

#endif
