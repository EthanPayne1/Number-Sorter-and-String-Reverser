#include "ListNode.h"

ListNode::ListNode(int data, ListNode* next, ListNode* prev) : 
	data(data), next(next), prev(prev) {}

ListNode::ListNode(int data, ListNode* next) : 
	ListNode(data, next, nullptr) {}

ListNode::ListNode(int data) : 
	ListNode(data, nullptr, nullptr) {}

ListNode::~ListNode() {
	if (next != nullptr) {
		delete next;
	}
	if (prev != nullptr) {
		delete prev;
	}
}

int ListNode::getData() const {
	return data;
}

void ListNode::setData(int data) {
	this->data = data;
}

ListNode* ListNode::getNext() const {
	return next;
}

void ListNode::setNext(ListNode* next) {
	this->next = next;
}

ListNode* ListNode::getPrev() const {
	return prev;
}

void ListNode::setPrev(ListNode* prev) {
	this->prev = prev;
}
