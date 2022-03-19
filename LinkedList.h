#ifndef STACKSQUEUES_LINKEDLIST_H
#define STACKSQUEUES_LINKEDLIST_H

#include "ListNode.h"

class LinkedList {
private:
    ListNode* head;
    ListNode* tail;
    int size;

    void insertFirstNode(int data);

    // Insert newNode after the node the currNode is pointing to
    void insertNodeAfter(ListNode* currNode, ListNode* newNode);

    // Remove currNode from the list
    void removeNode(ListNode* prevNode, ListNode* currNode);

    ListNode* findNodeByPosition(int position) const;
    ListNode* findNodeByValue(int data);

    void printReverseRecursive(ListNode* node) const;

public:
    // Constructors
    LinkedList();
    LinkedList(int data);
    LinkedList(int array[], int size);

    // Copy constructor
    LinkedList(const LinkedList& rhs);

    // Destructor
    virtual ~LinkedList();

    // Overload assignment operator
    LinkedList operator=(const LinkedList& rhs);

    // Place node at end of list
    void append(int item);

    // Place node at the beginning of the list
    void prepend(int item);

    // Add a node with newItem after the node that contains curItem
    bool insertAfterItem(int curItem, int newItem);

    // Insert node with the value item after node at position
    // position 0-based index, use -1 to insert at front of the list
    bool insertAfterPosition(int item, int position);

    int remove(int item);         // remove first node with data T, return data T
    int removeAt(int position);   // remove node at position (0 based indexing)
    int removeFront();            // remove the head node
    int removeBack();             // remove the tail node

    // Search operations
    // Search for node with T data, if found return data otherwise throw exception
    int search(int item);
    // Search for node with T data, if found return true otherwise return false
    bool contains(int item);

    // Sort operations
    void sort(bool ascending = true);    // sort list in ascending or descending order

    // getter
    int get(int position) const;    // return int data at position

    // setter
    int set(int data, int position);

    // list methods
    void clear();       // remove all nodes from list, make the list empty
    bool isEmpty() const;     // return true if the list is empty
    int getLength() const;    // return the number of nodes in the list

    // support methods
    void print() const;           // print data from head to tail
    void printReverse() const;    // print data from tail to head
    int* toArray() const;         // convert list to an array of int
};

#endif //STACKSQUEUES_LINKEDLIST_H
