#ifndef SIMPLE_H
#define SIMPLE_H

//including these libraries
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//node class
//
class Node
{
  //define
  //
  char* data;
  Node* next;
private:


//public methods
//
public:
  //constructor
  //
  Node() {};

  //sets data
  //
  void SetData(char* aData) { data = aData; };

  //sets next
  //
  void SetNext(Node* aNext) { next = aNext; };


  char* Data() { return data; };

  Node* Next() { return next; };


};

//linked list class
//
class List
{
  //node pointer
  //
  Node* head;

public:

  //constructor
  //
  List() { head = NULL; };

  void Print();
  void Append(char* data);
  void Delete(char* data);



};

#endif
