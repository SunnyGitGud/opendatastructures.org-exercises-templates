/*
    QUESTION:
    Design and implement an SList method `secondLast()` that returns the value 
    of the second-to-last element in the list.

    RULES:
    - Do NOT use the `n` member variable that tracks the list size.
    - The list is a singly linked list (only `next` pointers, no `prev`).
    - Traverse the list to find the second-to-last node.
    - If the list has fewer than 2 elements, throw an exception.

    HINT:
    - The last node has `next == nullptr`.
    - The second-to-last node's `next` points to the last node.
    - Think about what loop condition would make `current` stop 
      at the second-to-last node.
*/

#include <iostream>
#include <stdexcept>

template<typename T>
class Node {
public:
    T x;
    Node *next;

    Node(T data) : x(data), next(nullptr) {}
};

template<typename T>
class Slist {
private:
    Node<T> *head;
    int n;

public:
    Slist() : head(nullptr), n(0) {}

    void addLast(T data) {
        Node<T>* node = new Node<T>(data);
        if (!head) {
            head = node;
        } else {
            Node<T>* current = head;
            // TODO: Traverse to last node and add new node
        }
        n++;
    }

    T secondLast() {
        // TODO: Handle cases where list has fewer than 2 elements

        // TODO: Traverse until current is second-to-last node

        // TODO: Return the value
    }
};

