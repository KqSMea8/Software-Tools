// file: lecture_12/example.cc
//
// a simple program to play around with data types, including
// pointers and arrays
//

// system include files
//
#include "example.h"

// function: main
//
// main program starts here
//
int main(int argc, char** argv) {

  // call a simple function
  //
  long foo = argc;
  fprintf(stdout, "the value of foo is %d\n", foo);
  float sum = convert_arg((long)foo);
  fprintf(stdout, "the new value of foo is %d\n", foo);

  float x[10][99];
  convert(x, N, M);
  

  // print something
  //
  fprintf(stdout, "the name of the program %s\n", argv[0]);
  fprintf(stdout, "the number of arguments is %10.0f\n", sum);

  // exit gracefully
  //
  return(0);
}
