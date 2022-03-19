#include <stdexcept>
#include <iostream>
#include <algorithm>

#include "LinkedList.h"

LinkedList::LinkedList() : head(nullptr), tail(nullptr), size(0) {}

LinkedList::LinkedList(int data) {
    insertFirstNode(data);
}

LinkedList::LinkedList(int* array, int size) : LinkedList() {
    for (int i = 0; i < size; ++i) {
        append(array[i]);
    }
}

LinkedList::LinkedList(const LinkedList& rhs) : LinkedList() {
    ListNode* currNode = rhs.head;
    while (currNode != nullptr) {
        append(currNode->getData());
        currNode = currNode->getNext();
    }
}

LinkedList LinkedList::operator=(const LinkedList& rhs) {
    ListNode* currNode = rhs.head;
    clear();
    while (currNode != nullptr) {
        append(currNode->getData());
        currNode = currNode->getNext();
    }
    return *this;
}

LinkedList::~LinkedList() {
    ListNode* curr;

    while (head != nullptr) {
        curr = head;
        head = head->getNext();
        curr->setNext(nullptr);
        delete curr;
    }
}

// private
void LinkedList::insertFirstNode(int data) {
    head = new ListNode(data);
    tail = head;
    size = 1;
}

//private
void LinkedList::insertNodeAfter(ListNode* currNode, ListNode* newNode) {
    if (currNode == tail) {
        tail->setNext(newNode);
        tail = newNode;
    }
    else {
        newNode->setNext(currNode->getNext());
        currNode->setNext(newNode);
    }
}

// private
ListNode* LinkedList::findNodeByPosition(int position) const {
    if (head == nullptr) {
        return nullptr;
    }
    ListNode* curr = head;
    for (int i = 0; curr != nullptr && i < position; ++i, curr = curr->getNext());

    return curr;
}

//private
ListNode* LinkedList::findNodeByValue(int data) {
    if (head == nullptr) {
        return nullptr;
    }
    ListNode* curr = head;
    for (curr = head; curr != nullptr && curr->getData() != data; curr = curr->getNext());
    return curr;
}

//private
void LinkedList::removeNode(ListNode* prevNode, ListNode* currNode) {
    if (currNode == head) {
        head = currNode->getNext();
    }
    else if (currNode == tail) {
        prevNode->setNext(nullptr);
        tail = prevNode;
    }
    else {
        prevNode->setNext(currNode->getNext());
    }
    currNode->setNext(nullptr);
    delete currNode;
    if (head == nullptr) {
        tail = nullptr;
    }
}

void LinkedList::append(int item) {
    if (size == 0) {
        insertFirstNode(item);
    }
    else {
        ListNode* curr = new ListNode(item);
        tail->setNext(curr);
        tail = curr;
        size++;
    }
}

void LinkedList::prepend(int item) {
    if (size == 0) {
        insertFirstNode(item);
    }
    else {
        ListNode* curr = new ListNode(item);
        curr->setNext(head);
        head = curr;
        size++;
    }
}

bool LinkedList::insertAfterItem(int currItem, int newItem) {
    ListNode* curr = head;
    for (; curr != nullptr && curr->getData() != currItem; curr = curr->getNext());
    if (curr != nullptr) {
        // we found currItem and curr points to it
        ListNode* temp = new ListNode(newItem);
        temp->setNext(curr->getNext()); // connect temp to the node after curr
        curr->setNext(temp);            // connect curr to the new node
        return true;
    }
    else {
        return false;
    }
}

// Insert node with the value item after node at position
// position 0-based index, use -1 to insert at front of the list
bool LinkedList::insertAfterPosition(int item, int position) {
    if (position < -1 || position > size - 1) {
        throw std::runtime_error("position is out of bounds");
    }
    if (position == -1) {
        prepend(item);
        return true;
    }
    ListNode* curr = head;
    ListNode* temp = new ListNode(item);
    for (int i = 0; curr != nullptr && i < position; curr = curr->getNext(), i++);
    // curr should be pointing to the node we are inserting after
    insertNodeAfter(curr, temp);
    size++;
    return true;
}

int LinkedList::remove(int item) {
    if (size == 0) {
        throw std::runtime_error("Cannot remove from empty list");
    }
    ListNode* curr = head;
    ListNode* prev = nullptr;
    // Iterate through list, look for item at curr
    while (curr != nullptr) {
        if (curr->getData() == item) {
            int itemDeleted = curr->getData();
            removeNode(prev, curr);
            size--;
            return itemDeleted;
        }
        prev = curr;
        curr = curr->getNext();
    }
    throw std::runtime_error("Item was not in list to remove");
}

int LinkedList::removeAt(int position) {
    if (size == 0) {
        throw std::runtime_error("Cannot remove item from empty list");
    }
    if (position < 0 || position >= size) {
        throw std::runtime_error("position must be between 0 and size - 1");
    }
    ListNode* curr = head;
    ListNode* prev = nullptr;
    for (int i = 0; i < position; ++i) {
        prev = curr;
        curr = curr->getNext();
    }
    int itemDeleted = curr->getData();
    removeNode(prev, curr);
    size--;
    return itemDeleted;
}

int LinkedList::removeFront() {
    return removeAt(0);
}

int LinkedList::removeBack() {
    return removeAt(size - 1);
}

int LinkedList::search(int item) {
    if (size == 0) {
        throw std::runtime_error("Cannot search item in empty list");
    }
    ListNode* curr = findNodeByValue(item);
    if (curr == nullptr) {
        throw std::runtime_error("Item not found in list");
    }
    return curr->getData();
}

bool LinkedList::contains(int item) {
    ListNode* curr = findNodeByValue(item);
    if (curr == nullptr) {
        return false;
    }
    return true;
}


int LinkedList::get(int position) const {
    if (size == 0) {
        throw std::runtime_error("Cannot get item from empty list");
    }
    if (position < 0 || position >= size) {
        throw std::runtime_error("position must be between 0 and size - 1");
    }
    ListNode* curr = findNodeByPosition(position);
    if (curr == nullptr) {
        throw std::runtime_error("Unexpected error");
    }
    return curr->getData();
}

int LinkedList::set(int data, int position) {
    if (size == 0) {
        throw std::runtime_error("Cannot get item from empty list");
    }
    if (position < 0 || position >= size) {
        throw std::runtime_error("position must be between 0 and size - 1");
    }
    ListNode* curr = findNodeByPosition(position);
    if (curr == nullptr) {
        throw std::runtime_error("Unexpected error");
    }
    int oldValue = curr->getData();
    curr->setData(data);
    return oldValue;
}

void LinkedList::clear() {
    ListNode* curr;

    while (head != nullptr) {
        curr = head;
        head = head->getNext();
        curr->setNext(nullptr);
        delete curr;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}

bool LinkedList::isEmpty() const {
    return size == 0;
}

int LinkedList::getLength() const {
    return size;
}

void LinkedList::print() const {
    ListNode* curr = head;
    if (curr != nullptr) {
        std::cout << curr->getData();
        curr = curr->getNext();
    }
    while (curr != nullptr) {
        std::cout << " -> " << curr->getData();
        curr = curr->getNext();
    }
}

void LinkedList::printReverse() const {
    printReverseRecursive(head);
}

// private
void LinkedList::printReverseRecursive(ListNode* node) const {
    if (node != nullptr) {
        printReverseRecursive(node->getNext());
    }
    if (node != nullptr) {
        std::cout << node->getData();
        if (node != head) {
            std::cout << " -> ";
        }
    }

}

int* LinkedList::toArray() const {
    int* array = new int[size];
    ListNode* curr = head;
    for (int i = 0; curr != nullptr && i < size; ++i, curr = curr->getNext()) {
        array[i] = curr->getData();
    }
    return array;
}

void LinkedList::sort(bool ascending) {
    int* array = toArray();
    if (ascending) {
        std::sort(array, array + size);
    }
    else {
        std::sort(array, array + size, std::greater<int>());
    }
    int oldSize = size;
    clear();
    for (int i = 0; i < oldSize; ++i) {
        append(array[i]);
    }
}
