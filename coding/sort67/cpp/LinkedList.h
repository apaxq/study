#ifndef STUDY_LINKEDLIST_H
#define STUDY_LINKEDLIST_H

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    bool insertBefore(Node* prior, Node* target, Node* newNode);
    bool insertAfter(Node* target, Node* newNode);
    Node* head;

public:
    LinkedList();
    bool insert(int integer);
    void print() const;
    int sum();
    void printReverse();
};

#endif //STUDY_LINKEDLIST_H