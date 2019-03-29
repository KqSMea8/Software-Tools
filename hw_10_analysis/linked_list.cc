/*
 * linked_list.cc
 *
 */

#include <iostream>
#include "linked_list.h"
#include <string.h>

using namespace std;

/*
 * Implement Node Methods
 */

/*
 * Node constructor
 */
Node::Node(){
	this->data = nullptr;
	this->next = nullptr;
}

/*
 * Node::setData
 * Set the data payload to a provided char* - c style string
 */
void Node::setData(char* aData){
	// allocate a block of memory for the data being passed into the node
	//
	this->data = (char*) malloc(sizeof(aData));
	// copy the character string data being passed in
	//
	strncpy(this->data, aData, (sizeof(aData)/sizeof(char))+1);
}

/*
 * Node::setNext
 * Set the pointer to the next node in the linked list
 */
void Node::setNext(Node* aNext){
	this->next = aNext;
}

/*
 * Node::getData
 * Return the data payload held by the node
 */
char* Node::getData(){
	return this->data;
}

/*
 * Node::getNext
 * Return a pointer to the next node in the list
 */
Node* Node::getNext(){
	return this->next;
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
 * Print the contexts of the linked list
 */
void List::print(){

  // Temp pointer
  Node *tmp = head;

  // No nodes
  if ( tmp == NULL ) {
    cout << "EMPTY" << endl;
    return;
  }

  // One node in the list
  if ( tmp->getNext() == NULL ) {
    cout << tmp->getData();
    cout << " --> ";
    cout << "NULL" << endl;
  }
  else {
    // Parse and print the list
    do {
      cout << tmp->getData();
      cout << " --> ";
      tmp = tmp->getNext();
    }
    while ( tmp != NULL );

    cout << "NULL" << endl;
  }

}

/*
 * Append a node to the linked List
 */
void List::append(char* data){
  // Create a new node
  Node* newNode = new Node();
  newNode->setData(data);
  newNode->setNext(NULL);

  // Create a temp pointer
  Node *tmp = head;

  if ( tmp != NULL ) {
    // Nodes already present in the list
    // Parse to end of list
    while ( tmp->getNext() != NULL ) {
      tmp = tmp->getNext();
    }

    // Point the last node to the new node
    tmp->setNext(newNode);
  }
  else {
    // First node in the list
    head = newNode;
  }


}

/*
 * Delete a node in the list
 */
void List::deleteData(char* data){

  // Temp pointer
  Node *tmp = head;
  Node *prev = tmp;
  // No nodes
  if ( tmp == NULL ) {
    return;
  } else {
    // Parse the list provided 
    while ( tmp != NULL ){

      if(strncpy( tmp->getData(), data, (sizeof(data)/sizeof(char)) )){
        
        if(tmp == head){
          head = tmp->getNext();
          free(tmp);
        } else {
          prev = tmp;
          prev->setNext(tmp->getNext());
        }
        
        break;
      }

      // advance to the next node
      tmp = tmp->getNext();

    }

  }
  
}
