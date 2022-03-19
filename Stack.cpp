#include "Stack.h"
#include "LinkedList.h"
#include <iostream>
#include <stack>
#include <string>

LinkedList item; // Instance variable
ListNode* head = nullptr;
// Default Constructor
Stack::Stack() {} 

//  Parameter constructor that takes an int parameter for data and places it in the stack
Stack::Stack(int data) {
	head = new ListNode(data);
}  

// Create a new node, then assign the nodes data with the item then prepending the node
void Stack::push(int data) {
	ListNode *newNode = new ListNode(data); // Create the new node
	newNode->setNext(head);
	head = newNode;
	
	list.prepend(data); // Insert the data at the head node
}

// Assign a local variable with head node's data then removing the head node
int Stack::pop() {
	ListNode* newNode = head; // Assign newNode to the head
	if (head == nullptr) { // If the head node equals null the stack is empty
		std::cout << "Stack is empty" << std::endl;
		return -1;
	}
	else { // If the head node doesnt equal null
		ListNode* newNode = head; 
		head = head->getNext(); // Head is assigned head which access getNext() which returns next

		list.removeFront(); // Removes the front node
	}
}

// Returns the item at the top of the stack
int Stack::peek() const {

	return head->getData();
}

// If head is equal to nullptr then isEmpty() returns true otherwise isEmpty() returns false
bool Stack::isEmpty() const {
	if (head == nullptr) {
		std::cout << "Stack is empty" << std::endl;
		return true;
	}
	else {
		return false;
	}
}

// Output the size of the stack
int Stack::getLength() const {

	return list.getLength();
}
