#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#include "Stack.h"
#include "Queue.h"

void reverseString(string message);
void separateEvenOdd(Queue startQueue, Queue& evenQueue, Queue& oddQueue);

int main() {

    string msg;
    cout << "Enter a message: " << endl;
    getline(cin, msg);

    cout << "msg: " << msg << endl;
    cout << "Reversed";
    reverseString(msg);
    cout << endl;

    Queue startQ;
    Queue evenQ;
    Queue oddQ;
    int num = 0;

    cout << "Integers in the start queue:" << endl;
    for (int i = 0; i < 10; ++i) {
        cin >> num;
        cout << num << " ";
        startQ.enqueue(num);
    }
    cout << endl;

    separateEvenOdd(startQ, evenQ, oddQ);

    cout << "Even numbers:" << endl;
    while (!evenQ.isEmpty()) {
        cout << evenQ.dequeue() << " ";
    }
    cout << endl;
    cout << "Odd numbers:" << endl;
    while (!oddQ.isEmpty()) {
        cout << oddQ.dequeue() << " ";
    }
    cout << endl;

    return 0;
}

// Declare a stack and use it to output the message in reverse. Use the stack class you made in step 1 
void reverseString(string message) {
    
    Stack stack;
    char msg[message.length()];

    for (int i = 0; i < sizeof(msg); i++) {
        msg[i] = message[i];
        stack.push(message[i]);
    }
    cout << endl;
    for (int i = stack.getLength(); i > 0; i--) {
        cout << char(stack.peek());
        stack.pop();
    }
    cout << endl;
}

void separateEvenOdd(Queue startQueue, Queue& evenQueue, Queue& oddQueue) {
    int size = startQueue.getLength();
    for (int i = 0; i < size; i++) {
        if (startQueue.peek() % 2 == 0) {
            evenQueue.enqueue(startQueue.dequeue());
        }
        else {
            oddQueue.enqueue(startQueue.dequeue());
        }
    }
}
