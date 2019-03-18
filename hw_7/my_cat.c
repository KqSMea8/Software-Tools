#include <stdio.h>
#include <stdlib.h>
#include <cstring>

int main(int argc, char* argv[])
{
  //variables
  //

  FILE *fp, *fp2;
  long lSize, lSize2;
  char * buffer, * buffer2;
  size_t result, result2;
  char line, line2;
  int count = 0000000;
  
  //if time permits, create sort function first
  //
  for ( int i = 0; i < argc; i++ )
    {
      //compare arguement with -help
      //
      if ( ! strcmp ( argv[i], "-help" ) )
	{
	  //printout help information
	  //
	  fprintf(stdout,  "name: my_cat\n");
	  fprintf(stdout, "synopsis: reads files from provided list and writes out data within\n");
	  fprintf(stdout, "descr: takes a folder from arguement that conatins locations of text files. ");
	  fprintf(stdout, "It can then open those text files, read the files line by line, and display the contents, ");
	  fprintf(stdout, "supports an option named '-help'.\n\n");
	  fprintf(stdout, "options:\n\t-help: display this help message\n\n");
	  fprintf(stdout, "arguments: standard tool arguements are passed to the tool\n\n");
	  fprintf(stdout, "man pages: none\n");
	  //end of if statement
	  //
	}
      
      //end of for loop
      //
    }
  //back to main
  //
  //loop through files to open and read
  //
  for ( int i = 1; i < argc; i++ )
    {
      fp = fopen(argv[i], "r");
      if (fp == NULL) {exit (1);}

      //Sets the position indicator associated with the stream to a new position.
      //
      fseek (fp, 0, SEEK_END);
      //Returns the current value of the position indicator of the stream.
      //
      lSize = ftell (fp);
      //Sets the position indicator associated with stream to the beginning of the file.
      //
      rewind (fp);
      // allocate memory to contain the whole file:
      //
      buffer = (char*) malloc (sizeof(char)*lSize);
      if (buffer == NULL) {fputs ("Memory error",stderr); exit (2);}
      // copy the file into the buffer:
      //
      result = fread (buffer,1,lSize,fp);
      if (result != lSize) {fputs ("Reading error",stderr); exit (3);}


      // the whole file is now loaded in the memory buffer. 
      //
      char * line = strtok(strdup(buffer), "\n");
      while(line != NULL)
	{	  
	  fp2 = fopen(line, "r");	  
	  if (fp2 == NULL) {
	    fprintf(stdout, "file is null\n");
	    exit (1);
	  }

	  //Sets the position indicator associated with the stream to a new position.
	  //
	  fseek (fp2, 0, SEEK_END);
	  //Returns the current value of the position indicator of the stream.
	  //
	  lSize2 = ftell (fp2);
	  //Sets the position indicator associated with stream to the beginning of the file.
	  //
	  rewind (fp2);
	  // allocate memory to contain the whole file:
	  //
	  buffer2 = (char*) malloc (sizeof(char)*lSize2);
	  if (buffer2 == NULL) {fputs ("Memory error",stderr); exit (4);}
	  // copy the file into the buffer:
	  //
	  result2 = fread (buffer2,1,lSize2,fp2);
	  if (result2 != lSize2) {fputs ("Reading error",stderr); exit (5);}


	  //printout text file
	  //
	  fprintf(stdout, "opening %s:\n", argv[i]);
	  fprintf(stdout, "******\n");
	  fprintf(stdout, "%d: %s\n", count, line);
	  fprintf(stdout, "%s\n", buffer2);
	  count = count +1;

	  //close file
	  //
	  fclose(fp2);
	  //free buffer memory space
	  //
	  free(buffer2);
	  //go to next line
	  //
	  line  = strtok(NULL, "\n");
	  //end of line loop
	  //
	  
	}
	  
      // terminate
      fclose (fp);
      free (buffer);
      //end of file read loop
      //
    }

  
  return 0;  
}
