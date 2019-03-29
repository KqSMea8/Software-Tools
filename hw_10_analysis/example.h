/*
 * Example.h 
 * Alex Wroblewski
 * Implementation of the Sparse Matrix
 */

#ifndef EXAMPLE_H
#define EXAMPLE_H

/*
 * Includes
 */

/*
 * Class sparseMatrixNode
 * A node for the sparse matrix
 */
class SparseMatrixNode {

private:

    // Indicies that the node exists at
    int* xInd; 
    int* yInd;

    // The value at given coordinates
    int* value;

    // The next node with defined coordinates;
    //
    SparseMatrixNode* next;

public:
    
    // Constructor for the SparseMatrixNode
    //
	SparseMatrixNode(int aX, int aY, int aVal);

    // Getters
    int getXInd();
    int getYInd();
    int getValue();

    // Set the next node
    void setNext(SparseMatrixNode* aNext);

    // Get the next node
    SparseMatrixNode* getNext();
    
    // Destructor for the SparseMatrixNode
    //
    ~SparseMatrixNode();

};


/*
 * class List
 */
class List {

private:

    // The head of the linked list
    //
	SparseMatrixNode* head;

    // Number of defined elements in the linked list 
    //
    int* numElements;

public:
  
    // Constructor of the linked list
    //
	List();

    // Destructor of the Linked List
    //
    ~List();
 
    // Print the Linked List
    //
	void print();

    // Get the head of the linked list
    //
    SparseMatrixNode* getHead();

    // Get the number of elements in the linked list
    //
    int getNumElements();

    // Sort the linked list
    //
    void sort();

    // Append data to the linked list
    //
	void append(SparseMatrixNode* data);

    // Delete data from the linked list
    //
	void deleteData(SparseMatrixNode* data);

};


/*
 * class MySparseMatrix
 */
class MySparseMatrix {

private:
    
    // Columns of the matrix
    //
    int* xColumns; 

    // Rows of the matrix
    //
    int* yRows;
	
	// Defined elements of the matrix are stored in a linked list
	//
	List* definedElements;


public:

    // MySparseMatrix Constructor
	//
	MySparseMatrix(int aCols, int aRows);
    MySparseMatrix();
    
    // implement a destructor that cleans up memory properly
	//
    ~MySparseMatrix();

    // Determine whether or not a coordinate is defined 
    //
    SparseMatrixNode* getDefined(int aX, int aY);

    // Implement a resize function that creates a matrix of a particular dimension with all zero elements.
	//
    void resize(int newCols, int newRows);

    // Overload the parentheses operator so that you can write a(1,1) = 27 for any index in the matrix. Bounds-checking must be performed.
	//
    int*  operator() (int xCoord, int yCoord);

    // Overload the +  operator so that I can write a = b + c  and have the matrices added to together.
	//
    MySparseMatrix operator+ (const MySparseMatrix& aMatrix);

	// Overload the = operator so that I can write a=b
	//
    MySparseMatrix operator= (const MySparseMatrix& aMatrix);

	// Create a debug method that dumps the contents of the matrix to stdout by printing all nonzero values (the indices of the value and its value)
	// 
    void debug();

};
#endif
