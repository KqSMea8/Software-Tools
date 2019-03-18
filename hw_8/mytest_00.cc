//mytest_00.cc
//

#include "mytest.h"


const char* MyTest::NAME = "MyTest";
////////////////////
//member functions//
////////////////////


int MyTest::set_debug(int level)
{
 switch(level)
   {
   case MyTest::FULL:
     return 3;
     break;
   case MyTest::PARTIAL:
     return 2;
     break;
   case MyTest::BRIEF:
     return 1;
     break;
   case MyTest::NONE:
     return 0;
     break;
   }
 return 0;
   
}

//display debug info
//
void MyTest::debug(FILE* arg, int set_level)
{
  switch(set_level)
    {
    case 0:
      fprintf(stdout, "this is debug output for none\n");
      break;
      
    case 1:
      fprintf(stdout, "this is debug output for Brief\n");
      break;

    case 2:
      fprintf(stdout, "this is debug output for Partial\n");
      break;

    case 3:
      fprintf(stdout, "this is debug output for Full\n");
      break;
            
    }
}

//atkes algorithm enum and compares it to call compute_ functions
//
int MyTest::compute( ALGORITHM value)
{

  switch(value)
    {
    case 1:
      return(compute_1());
      break;
    case 2:
      return(compute_2());
      break;
    case 3:
      return(compute_3());
      break;
    }

}

//next three are compute functions that return their own number
//
int MyTest::compute_1()
{
  return 1;
}

int MyTest::compute_2()
{
  return 2;
}

int MyTest::compute_3()
{
  return 3;
}

//I'll be honest, I didn't use any variables that could be reset to my knowledge
//
void MyTest::reset(void)
{

}



