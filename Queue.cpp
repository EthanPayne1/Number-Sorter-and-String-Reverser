#include "Queue.h"
#include "LinkedList.h"
#include <queue>
#include <iostream>
#include <string>



LinkedList list;
ListNode* tail = nullptr;

Queue::Queue() {}

// Parameter Constructor takes int parameter for data and adds to the queue
Queue::Queue(int data) {
	
	list.append(data);
}

// Inserts data at the end of the queue
void Queue::enqueue(int data) {

	list.append(data);
}

// Returns and removes node at the front of the queue
int Queue::dequeue() {

	return list.removeFront();
}

int Queue::peek() const {

	return list.get(0);
}

bool Queue::isEmpty() const {

	return list.isEmpty();
}

int Queue::getLength() const {

	return list.getLength();
}


