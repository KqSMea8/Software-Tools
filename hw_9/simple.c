#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  //Variables to temporarily store names
  //
  const char* name1 = "Mary";
  const char* name2 = "Joe";
  const char* name3 = "Susan";

  //create variable size of name and then stores it in memory
  //
  char* c1 = (char*)malloc(sizeof(name1));
  strcpy(c1, name1);

  char* c2 = (char*)malloc(sizeof(name2));
  strcpy(c2, name2);

  char* c3 = (char*)malloc(sizeof(name3));
  strcpy(c3, name3);

  //grabs the name from memory and stores it in array[]
  //
  char** array[] = {&c1, &c2, &c3};

  //prints out array values to confirm storage
  //
  fprintf(stdout, "array 1: %s\n", *array[0]);
  fprintf(stdout, "array 1: %s\n", *array[1]);
  fprintf(stdout, "array 1: %s\n", *array[2]);

  //frees up memory
  //
  free(&name1);
  free(&name2);
  free(&name3);

  //exits gracefully
  //
  return 0;
}
