#ifndef STACKSQUEUES_QUEUE_H
#define STACKSQUEUES_QUEUE_H

#include "LinkedList.h"

class Queue {
private:
    LinkedList list;

public:
    Queue();
    Queue(int data);
    void enqueue(int data);
    int dequeue();
    int peek() const;
    bool isEmpty() const;
    int getLength() const;
};


#endif //STACKSQUEUES_QUEUE_H
