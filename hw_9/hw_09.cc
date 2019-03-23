#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define total_strings 3


int main(int argc, char** argv) {

  // This will make the array
  //
  char** names;

  // This will make the the allocation of memory
  //
  names = (char**) malloc(total_strings*sizeof(char*));

  // This will allocate the individual string lengths
  //
  names[0] = (char*) malloc(strlen("Mary")+1*sizeof(char));
  names[1] = (char*) malloc(strlen("Joe")+1*sizeof(char));
  names[2] = (char*) malloc(strlen("Susan")+1*sizeof(char));

  // This will copy the strings to the memory locations
  //
  strcpy(names[0], "Mary");
  strcpy(names[1], "Joe");
  strcpy(names[2], "Susan");

  fprintf(stdout, "{" );

  // This will loop throug and print the array
  //
  for(int i = 0; i < total_strings; i++) {

    if ( i < 2) {
    fprintf(stdout, "\"%s\", ", names[i]);
    } else {
       fprintf(stdout, "\"%s\"", names[i]);
    }
  }


  fprintf(stdout, "}\n");
  // This will print out the name and the address of string
  //

  for(int i = 0; i < total_strings; i++) {


    fprintf(stdout, "%s: %d\n", names[i], &names[i]);

  }

  // will free all of the memory that was allocated
  //
  free(names[0]);
  free(names[1]);
  free(names[2]);
  free(names);
  return 0;
}
