// file: lecture_12/example_00.cc
//
// a simple function that doesn't do much
//

// system include files
//
#include "example.h"

// function: convert_arg
//
// arguments:
//  long nargs: the number of arguments
//
// return: a float containing the value of the argument
//
float convert_arg(long nargs) {

  nargs = 27;
  
  // exit gracefully
  //
  return (float)nargs;
}
