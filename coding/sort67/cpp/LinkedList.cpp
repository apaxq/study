#include "LinkedList.h"
#include <iostream>
#include <ostream>

LinkedList::LinkedList() {
    head = nullptr;
}

bool LinkedList::insertBefore(Node* prior, Node* target, Node* newNode) {
    if (head == nullptr || target == nullptr) {
        std::cout << "List is empty or target node is invalid.\n";
        return false;
    }

    // If target is the head node, update head pointer
    if (head == target) {
        newNode->next = head;
        head = newNode;
        return true;
    }

    // Insert the new node between prior and 'targetNode'
    newNode->next = target;
    prior->next = newNode;
    return true;
}

bool LinkedList::insertAfter(Node *target, Node *newNode) {
    if (target == nullptr) {
        std::cout << "The given target node cannot be NULL.\n";
        return false;
    }

    newNode->next = target->next;
    target->next = newNode;
    return true;
}

bool LinkedList::insert(int integer) {
    // Check if it's the first item in a list
    if (head == nullptr) {
        head = new Node;
        head->data = integer;
        head->next = nullptr;
        return true;
    }

    // Create new node
    Node* newNode = new Node;
    newNode->data = integer;
    newNode->next = nullptr;

    // Temporary nodes to keep track of nodes while traversing list
    Node* current = head;
    Node* prior = head;

    // If current->next is not NULL, we have more than one item in the list
    if (current->next != nullptr) {
        while (current->next != nullptr) {
            // We keep looping until we find a value that is larger than the integer
            if (current->data < integer) {
                prior = current;
                current = current->next;
            } else {
                // Once we find it, we can place it in the list right before it
                return insertBefore(prior, current, newNode);
            }
        }

        // Last item in the array
        if (integer > current->data) {
            return insertAfter(current, newNode);
        }
        return insertBefore(prior, current, newNode);
    }

    // Only one item in the array (since current->next is Null)
    if (integer < current->data) {
        return insertBefore(prior, current, newNode);
    }
    return insertAfter(current, newNode);
}

void LinkedList::print() const {
    if (head == nullptr) {
        std::cout << "LinkedList is empty" << std::endl;
    }else {
        Node* current = head;

        std::cout << current->data;
        while (current->next != nullptr) {
            current = current->next;
            std::cout << ", " << current->data;
        }

        if (current->next == nullptr) {
            std::cout << std::endl;
        }
    }
}

int LinkedList::sum() {
    if (head == nullptr) {
        return 0;
    }

    Node* current = head;
    int sum = 0;

    while (current->next != nullptr) {
        sum = sum + current->data;
        current = current->next;
    }

    return sum + current->data;
}
