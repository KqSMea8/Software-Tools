#include <stdio.h>

int main()
{
  int max_items = 3;
  const char* name1 = "Mary";
  const char* name2 = "Joe";
  const char* name3 = "Suasn";
  //const char** array[max_items];
  const char** array[] = {&name1, &name2, &name3};

  fprintf(stdout, "array 1: %s\n", *array[0]);


  //fprintf(stdout, "%s\n", array);
return 0;
}
