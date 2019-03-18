#include <iostream>
#include "mytest.h"
//#include "mytest_00.cc"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char** argv)
{

  int m=1;
  //rename class
  //
  MyTest mt;
  //prints out NAME from class function name()
  //
  fprintf(stdout, "%s\n", mt.name());
  //call set_debug
  //
  fprintf(stdout, "%d\n", mt.set_debug(m));
  
  return 0;


}
