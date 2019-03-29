/*
 * example_00.cc
 * Implement classes in Example.h
 */ 

// Includes
#include "example.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Implement methods for the sparse matrix node
 */

// Constructor
//
SparseMatrixNode::SparseMatrixNode(int aX, int aY, int aVal){

    // Allocate memory for the coordinates
    this->xInd = (int *) malloc(sizeof(int));
    this->yInd = (int *) malloc(sizeof(int));
    this->value = (int *) malloc(sizeof(int));

    // Copy variables from memory
    memcpy(this->xInd, &aX, sizeof(int));
    memcpy(this->yInd, &aY, sizeof(int));
    memcpy(this->value, &aVal, sizeof(int));

}

// return X index
//
int SparseMatrixNode::getXInd(){
    return *(this->xInd);
}

// return Y index
//
int SparseMatrixNode::getYInd(){
    return *(this->yInd);
}

// return Matrix value
//
int SparseMatrixNode::getValue(){
    return *(this->value);
}

// Set the next node
//
void SparseMatrixNode::setNext(SparseMatrixNode* aNext){
    this->next = aNext;
}

// Get the next node
//
SparseMatrixNode* SparseMatrixNode::getNext(){
    return this->next;
}

// Destructor for the SparseMatrixNode
//
SparseMatrixNode::~SparseMatrixNode(){
    free(xInd);
    free(yInd);
    free(value);
}

/*
 * Implement methods for MySparseMatrix
 */

// Constructor
// 
MySparseMatrix::MySparseMatrix(int aCols, int aRows){
		
    // Allocate memory for the coordinates
    this->xColumns = (int *) malloc(sizeof(int));
    this->yRows = (int *) malloc(sizeof(int));

    // Copy variables from memory
    memcpy(this->xColumns, &aCols, sizeof(int));
    memcpy(this->yRows, &aRows, sizeof(int));

}

 // Overload the parentheses operator so that you can write a(1,1) = 27 for any index in the matrix. Bounds-checking must be performed.
 //
int* MySparseMatrix::operator() (int xCoord, int yCoord){

    // perform bounds checking
    // 
    if ( xCoord < *(this->xColumns) && yCoord < *(this->yRows) ){
        // check if the node exists
        
        SparseMatrixNode* tmp = getDefined(xCoord, yCoord);
        if(tmp != NULL){
            return (int*) &(tmp->getValue());
        }
        
    } else {
        return NULL;
    }

}

// Determine whether or not a coordinate is defined 
//
SparseMatrixNode* MySparseMatrix::getDefined(int aX, int aY){

    SparseMatrixNode* tmp = definedElements->getHead();
    if ( tmp == NULL ) {
        return NULL;
    }
    else {
        do {
            tmp = tmp->getNext();
            if ((tmp->getXInd()) == aX && (tmp->getYInd()) == aY){
                return tmp;
            }
        }
        while ( tmp != NULL );

	}

    return NULL;
}

// Overload the + operator
//
MySparseMatrix MySparseMatrix::operator+(const MySparseMatrix& aMatrix){

    // for all the defined elements in this matrix
//    for(int i = 0; i <=(this->definedElements->getNumElements() - 1); i++){
        
 //   }
	return aMatrix;

}

// Overload the = operator
//
MySparseMatrix MySparseMatrix::operator=(const MySparseMatrix& aMatrix){
    return aMatrix;
}

// Destructor for the MySparseMatrix
//
~MySparseMatix::MySparseMatrix(){

    // Free memory
    //
    free(xColumns);
    free(yRows);
    free(definedElements);

}

// Resize the matrix
//
void MySparseMatrix::resize(int newCols, int newRows){

    // remove all existing elements
    //

    *(this->xColumns) = newCols;
    *(this->yRows) =newRows;

    // clear all elements from the list
    //
    SparseMatrixNode* a = definedElements->getHead();
    SparseMatrixNode* b = definedElements->getHead()->getNext();
    while(a != NULL){
        a->~SparseMatrixNode();
        free(a);
        a = b;
        b = b->getNext();
    }

}



// Implement a sort for our linked list
//
void List::sort(){

    SparseMatrixNode* a;
    SparseMatrixNode* b;
    SparseMatrixNode* temp;

    //base case - Len is 0 or 1
    if ((this->head == NULL) || (this->head->getNext() == NULL)){
        return;
    }
    
    a = this->head;
    b = this->head->getNext();

    while(a != NULL && b != NULL){
        // traverse the linked list and sort in X
        //
        if(b->getXInd() > a->getXInd()){
            a->setNext(b->getNext());
            b->setNext(a);
        }
    }
}



// Print debug information to an output stream
//
void MySparseMatrix::debug(){
    // Temp pointer
    SparseMatrixNode *tmp = definedElements->head;

    // No nodes
    if ( tmp == NULL ) {
        fprintf(fstream, "EMPTY");
        return;
    }

    // One node in the list
    if ( tmp->getNext() == NULL ) {

        fprintf(stdout, "(%d, %d): %d \n --> NULL\n", tmp->getXInd(), tmp->getYInd(), tmp->getValue());

    }
    else {

        // Parse and print the list
        do {
            fprintf(stdout, "(%d, %d): %d \n --> ", tmp->getXInd(), tmp->getYInd(), tmp->getValue());
            tmp = tmp->getNext();
        }
        while ( tmp != NULL );
    
        fprintf(stdout, "NULL");

    
    }
}

/*
 * Implement List Methods
 */

/*
 * List constructor
 */
List::List(){
	this->head = nullptr;
}

/*
 * Append a node to the linked List
 */
void List::append(SparseMatrixNode* data){
  
  data->setNext(NULL);

  // Create a temp pointer
  SparseMatrixNode *tmp = head;

  if ( tmp != NULL ) {
    // Nodes already present in the list
    // Parse to end of list
    while ( tmp->getNext() != NULL ) {
      tmp = tmp->getNext();
    }

    // Point the last node to the new node
    tmp->setNext(data);
  }
  else {
    // First node in the list
    head = data;
  }

}

/*
 * Destructor for List
 */
List::~List(){
    
    // Temp pointer
    SparseMatrixNode *tmp = head;

    // No nodes
    if ( tmp == NULL ) {
        return;
    }

    // One node in the list
    if ( tmp->getNext() == NULL ) {
        tmp->~SparseMatrixNode();
        free(tmp);
    }
    else {
        // Parse and print the list
        do {
        	tmp->~SparseMatrixNode();
            free(tmp); // free the memory 
            tmp = tmp->getNext();  
        }
        while ( tmp != NULL );
    }	

	return;
	
}

// Get the head of the linked list
//
SparseMatrixNode* List::getHead(){
    return this->head;
}

/*
 * Delete a node in the list
 */
void List::deleteData(SparseMatrixNode* data){

    // Temp pointer
    SparseMatrixNode *tmp = head;
    SparseMatrixNode *prev = tmp;
    // No nodes
    if ( tmp == NULL ) {

        return;

    } else {

        // Parse the list provided 
        while ( tmp != NULL ){

            if(tmp == data){
    
                if(tmp == head){
                    head = tmp->getNext();
                    free(tmp);
                } else {
                    prev = tmp;
                    prev->setNext(tmp->getNext());
                }

                break;
            }
        }
    
        // advance to the next node
        tmp = tmp->getNext();

    }
	
}
