/*
 * linked_list.h
 * Define a class for a linked list
 */

/*
 * class Node
 */
class Node {

private:
	char* data;
	Node* next;
public:
	Node();
	void setData(char* aData);
	void setNext(Node* aNext);
	char* getData();
	Node* getNext();
};

/*
 * class List
 */
class List {

private:
	Node* head;
public:
	List();
	void print();
	void append(char* data);
	void deleteData(char* data);
};

