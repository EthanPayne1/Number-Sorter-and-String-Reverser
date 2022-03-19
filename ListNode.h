#ifndef STACKSQUEUES_LISTNODE_H
#define STACKSQUEUES_LISTNODE_H

class ListNode {
private:
    int data;
    ListNode* next;
    ListNode* prev;

public:
    // Constructors
    ListNode(int data, ListNode* next, ListNode* prev);
    ListNode(int data, ListNode* next);
    ListNode(int data);

    virtual ~ListNode();

    int getData() const;
    void setData(int data);
    ListNode* getNext() const;
    void setNext(ListNode* next);
    ListNode* getPrev() const;
    void setPrev(ListNode* prev);
};

#endif //STACKSQUEUES_LISTNODE_H
