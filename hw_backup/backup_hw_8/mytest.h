#ifndef MYTEST_H
#define MYTEST_H
#include <stdio.h>
#include <string>
#include <stdlib.h>

class MyTest
{
private:
  void reset();


public:
  int num;
  enum debug_level{FULL=3, PARTIAL=2, BRIEF=1, NONE=0};
  static const char* NAME;  
  MyTest();
  MyTest(int num);
  const char* name();
  //void set_debug(int size, const char* input);
  int set_debug(int num);
};

#endif
