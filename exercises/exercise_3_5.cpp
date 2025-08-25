/*
Exercise: Implement checkSize() in Linked Lists

Both SLList (singly linked list) and DLList (doubly linked list) store an integer n
representing how many nodes they *think* they have.

Your task:
1. Walk through the list and count the actual number of nodes.
2. Compare this count to n.
3. If they don’t match, throw std::runtime_error.
4. For the doubly linked list, also verify that each node’s prev pointer is consistent.

The method returns nothing — it only throws an exception when something is wrong.
*/

// ================= Code Skeleton =================






#include <iostream>
#include <stdexcept>

// ================= Singly Linked List =================
class SLList {
    struct Node {
        int data;
        Node* next;
    };
    Node* head;
    int n; // stored size

public:
    void checkSize();
};

// ================= Doubly Linked List =================
class DLList {
    struct Node {
        int data;
        Node* prev;
        Node* next;
    };
    Node* head;
    Node* tail;
    int n; // stored size

public:
    void checkSize();
};

// ================= Implementations =================

// For SLList
void SLList::checkSize() {
    // TODO:
    // 1. Traverse from head with next pointers
    // 2. Count nodes
    // 3. Compare with n
    // 4. Throw std::runtime_error if mismatch
}

// For DLList
void DLList::checkSize() {
    // TODO:
    // 1. Traverse from head with next pointers
    // 2. Ensure prev pointers are consistent
    // 3. Count nodes
    // 4. Compare with n
    // 5. Throw std::runtime_error if mismatch
}

// ================= Main for Testing =================
int main() {
    SLList s;
    DLList d;

    try {
        s.checkSize();   
    } catch (const std::exception& e) {
        std::cout << "[SLList] " << e.what() << "\n";
    }

    try {
        d.checkSize();   
    } catch (const std::exception& e) {
        std::cout << "[DLList] " << e.what() << "\n";
    }

    return 0;
}

