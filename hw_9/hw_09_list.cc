#include "hw_09_l.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

#define total_strings 3

int main(int argc, char** argv) {


  List list;

  FILE* fp;
  // char** names;


  char str1[255], str2[255], str3[255];

  // str1 = (char*) malloc(strlen("Mary") + 1*sizeof(char*));
  // str2 = (char*) malloc(strlen("Joe") + 1*sizeof(char*));  // str3 = (char*) malloc(strlen("Susan") + 1*sizeof(char*));


  fp = fopen("simple.txt", "r");

  if(fp == NULL) {
    fprintf( stdout, "The file returned NULL.... Please fix that");
  }

  fscanf(fp, "%s\n%s\n%s\n", str1, str2, str3);
  fprintf(stdout, "%s %s %s\n", str1, str2, str3);
  fclose(fp);

  list.Append(str1);
  list.Print();
  list.Append(str2);
  list.Print();
  list.Append(str3);
  list.Print();

  list.Delete(str3);
  list.Print();
  list.Delete(str2);
  list.Print();
  list.Delete(str1);
  list.Print();

  //  delete []str1;

  memset(str1,0,sizeof(str1));
  memset(str2,0,sizeof(str2));
  memset(str2,0,sizeof(str3));


  //free(names);
  return 0;
}
