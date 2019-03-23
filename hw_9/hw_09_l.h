#include <iostream>

using namespace std;

// Node class
class Node {
  char* data;
  Node* next;

public:
  Node() {};
  void SetData(char* aData) { data = aData; };
  void SetNext(Node* aNext) { next = aNext; };
  char* Data() { return data; };
  Node* Next() { return next; };
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

/**
 * Print the contents of the list
 */
void List::Print() {

  // Temp pointer
  Node *tmp = head;

  // No nodes
  if ( tmp == NULL ) {
    cout << "EMPTY" << endl;
    return;
  }

  // One node in the list
  if ( tmp->Next() == NULL ) {
    cout << tmp->Data();
    cout << " --> ";
    cout << "NULL" << endl;
  }
  else {
    // Parse and print the list
    do {
      cout << tmp->Data();
      cout << " --> ";
      tmp = tmp->Next();
    }
    while ( tmp != NULL );

    cout << "NULL" << endl;
  }
}

/**
 * Append a node to the linked list
 */
void List::Append(char* data) {

  // Create a new node
  Node* newNode = new Node();
  newNode->SetData(data);
  newNode->SetNext(NULL);

  // Create a temp pointer
  Node *tmp = head;

  if ( tmp != NULL ) {
    // Nodes already present in the list
    // Parse to end of list
    while ( tmp->Next() != NULL ) {
      tmp = tmp->Next();
    }

    // Point the last node to the new node
    tmp->SetNext(newNode);
  }
  else {
    // First node in the list
    head = newNode;
  }
}

/**
 * Delete a node from the list
 */
void List::Delete(char* data) {

  // Create a temp pointer
  Node *tmp = head;

  // No nodes
  if ( tmp == NULL )
    return;

  // Last node of the list
  if ( tmp->Next() == NULL ) {
    delete tmp;
    head = NULL;
  }
  else {
    // Parse thru the nodes
    Node *prev;
    do {
      if ( tmp->Data() == data ) break;
      prev = tmp;
      tmp = tmp->Next();
    } while ( tmp != NULL );

    // Adjust the pointers
    prev->SetNext(tmp->Next());

    // Delete the current node
    delete tmp;
  }
}
