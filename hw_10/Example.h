//Example.h
#ifndef EXAMPLE_H
#define EXAMPLE_H

#include <iostream>
using namespace std;


class MySparseMatrix
{
private:
    //create array 1M by 1M
    //

public:
    //setup array
    //
  double data[9][9];

    //constructor
    //
    MySparseMatrix()
    {
        // Set all elements of the matrix to 0.0
        //
        for (int row=0; row < 10; ++row)
            for (int col=0; col < 10; ++col)
                data[row][col] = 0.0;
    }

    //for non const objects
    //
    double& operator()(int row, int col);

    // for const objects
    //
    const double& operator()(int row, int col) const;
    void operator()();

};

// Node class
class Node {

public:
  Node(int i, int j, int val);
  void InsertRowAfter( Node* node );
  void InsertColAfter( Node* node );

  int iValue, jValue;  // Row and column index, 1-based
  float value;         // Element value
  Node *rowPtr;        // Next element in this row (sorted by jValue)
  Node *colPtr;        // Next element in this column (sorted by iValue)
};

// List class
class List {
  Node *head;
public:
  List() { head = NULL; };
  void Print();
  void Append(char* data);
  void Delete(char* data);
};
/*
Node::Node( int i, int j, int val )
    : iValue(i)
    , jValue(j)
    , value(val)
    , rowPtr(NULL)
    , colPtr(NULL)
{}
*/


#endif
