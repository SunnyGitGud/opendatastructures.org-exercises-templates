/*
Exercise: Implement addBefore(w) in a Doubly Linked List (DLList)

Write a method addBefore(w, value) that creates a new node u and inserts it
immediately before node w in the doubly linked list.
*/

#include <iostream>
#include <stdexcept>

class DLList {
    struct Node {
        int data;
        Node* prev;
        Node* next;
        Node(int d) : data(d), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int n;

public:
    DLList() : head(nullptr), tail(nullptr), n(0) {}

    void addBefore(Node* w, int value);

    // helper to add at end (so we can test addBefore)
    Node* pushBack(int value) {
        Node* u = new Node(value);
        if (!head) {
            head = tail = u;
        } else {
            tail->next = u;
            u->prev = tail;
            tail = u;
        }
        n++;
        return u;
    }

    void printList() {
        for (Node* p = head; p; p = p->next) {
            std::cout << p->data << " ";
        }
        std::cout << "\n";
    }

    Node* getHead() { return head; }
    Node* getTail() { return tail; }
};

void DLList::addBefore(Node* w, int value) {
    // TODO: Implement addBefore(w) in a Doubly Linked List (DLList)
                          
}

int main() {
    DLList d;

    auto a = d.pushBack(10);
    auto b = d.pushBack(20);
    auto c = d.pushBack(30);

    std::cout << "Before:\n";
    d.printList();

    // insert before node b
    d.addBefore(b, 15);

    std::cout << "After inserting 15 before 20:\n";
    d.printList();

    // insert before head
    d.addBefore(a, 5);

    std::cout << "After inserting 5 before 10:\n";
    d.printList();

    return 0;
}
