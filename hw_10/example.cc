//example.cc

#include "Example.h"
#include <iostream>

int main(void)
{
  //rename MySparseMatrix
  //
  MySparseMatrix matrix;

  //write data to array
  //
  //  matrix (1, 1) = 27;
  //matrix (2, 2) = 27;
  //matrix (9, 9) = 27;

  //read data out
  //
  std::cout << matrix(1, 1);
  std::cout << matrix(2, 2);
  std::cout << matrix(9, 9);

  //erase matrix
  //
  //  matrix(); // erase matrix


  //exit gracefully
  //
  return 0;
}
