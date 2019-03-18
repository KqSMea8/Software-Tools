#include <cstdio>
#include "f_header.h"
int main()
{
  float a=2;
  float b=1;
  float sin_1= add_sin(a, b);
  float sqrt_1= add_sqrt(a,b);
  fprintf(stdout, "hello world\n");
  fprintf(stdout, "sin sum is: %f\n", sin_1);
  fprintf(stdout, "sqrt sum is: %f\n", sqrt_1);
  return 0;
}
