#ifndef STACKSQUEUES_STACK_H
#define STACKSQUEUES_STACK_H

#include "LinkedList.h"

class Stack {
private:
    LinkedList list;

public:
    Stack();
    Stack(int data);
    void push(int data);
    int pop();
    int peek() const;
    bool isEmpty() const;
    int getLength() const;

};


#endif //STACKSQUEUES_STACK_H
