//classes for simple program
//
//include header
//
#include "simple.h"

//prints values in list
//
void List::Print()
{
  //create node pointer
  //
  Node* temp = head;

  //if no nodes
  //
  if(temp->Next() == NULL)
  {
    fprintf(stdout, "No Nodes\n");
    return;
  }
  //if Nodes
  //
  if(temp->Next() == NULL)
  {
    fprintf(stdout, "%s:", temp->Data());
    fprintf(stdout, "NULL");
  }
  else
  {
    //if more than one
    //
    do
      {
        
        fprintf(stdout, "%s\n", temp->Data());

      }while(temp->Next() != NULL);
    fprintf(stdout, "NULL");
  }
}
