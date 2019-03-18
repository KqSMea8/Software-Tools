#include <iostream>
#include "mytest.h"
//#include "mytest_00.cc"
#include <stdlib.h>
#include <stdio.h>
#include <cstring>

int main(int argc, char** argv)
{
  //add into class later on if time permits but main variables here
  //
  int level_set;
  int compute_set;
  
  //rename class
  //
  MyTest mt;
  
  //prints out NAME from class function name()
  //
  fprintf(stdout, "Class name: %s\n", mt.name());

  //check for debug option and if full options are present
  //
  if ( strcmp(argv[1], "-debug") == 0 && argc > 2)
    {
      if( strcmp(argv[2], "FULL") == 0 || strcmp(argv[2], "full") == 0)
	{
	  level_set = mt.set_debug(3);
	  compute_set = mt.compute(mt.three);
	}
      
      else if(strcmp(argv[2], "PARTIAL") == 0 || strcmp(argv[2], "partial") == 0)
	{
	  level_set = mt.set_debug(2);
	  compute_set = mt.compute(mt.two);
	}

      else if(strcmp(argv[2], "BRIEF") == 0 || strcmp(argv[2], "brief") == 0)
	{
	  level_set = mt.set_debug(1);
	  compute_set = mt.compute(mt.one);
	}

      else if(strcmp(argv[2], "NONE") == 0 || strcmp(argv[2], "none") == 0)
	{
	  level_set = mt.set_debug(0);
	}
      
      else
	{
	  fprintf(stdout, "Pass in full, partial, brief, or none\n");
	}

      //print debug level
      //
      printf("Debug Level is: %d\n", level_set);

      //prints out debug info
      //
      mt.debug(stdout, level_set);
      printf("this is Compute: %d\n", compute_set);
    }


  
  return 0;
      
}
