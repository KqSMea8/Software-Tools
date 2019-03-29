//example_00.cc

#include "Example.h"
#include <cassert> // for assert()

  //////////////////////
  //for MySparseMatrix//
  //////////////////////

//for non const objects
//
double& MySparseMatrix::operator()(int row, int col)
{
  assert(col >= 0 && col < 10);
  assert(row >= 0 && row < 10);

  return data[row][col];
}

//for const objects
//
const double& MySparseMatrix::operator()(int row, int col) const
{
  assert(col >= 0 && col < 10);
  assert(row >= 0 && row < 10);

  return data[row][col];
}

//resets matrix
//
void MySparseMatrix::operator()()
{
    // reset all elements of the matrix to 0.0
  for (int row=0; row < 10; ++row)
    for (int col=0; col < 10; ++col)
      data[row][col] = 0.0;
}





// Inserts the given node to follow this node in the row list
void Node::InsertRowAfter( Node* node )
{

    // [go on, you do it]
}


// Inserts the given node to follow this node in the column list
void Node::InsertColAfter( Node* node )
{
    // [go on, you do it]
}
