/*
    EXERCISE:

    Implement the List operations `get(i)`, `set(i, x)`, `add(i, x)`, and `remove(i)`
    on a singly linked list class `SLList`.

    REQUIREMENTS:
    - Each operation should run in O(1 + i) time.
    - Use zero-based indexing for the list positions.
    - If index i is out of bounds, throw std::out_of_range.
    - The add(i, x) method inserts the element x at index i,
      shifting subsequent elements right.
    - The remove(i) method removes the element at index i,
      returning its value.
    - No additional data structures allowed.
    - You can maintain a size variable (e.g., `n`) if you want.

    HINTS:
    - Use a helper method that returns a pointer to the node at index i.
    - Handle the head node cases carefully (i == 0).
    - Traverse the list up to the node just before index i when inserting/removing.

*/

#include <stdexcept>

template<typename T>
class Node {
public:
    T x;
    Node* next;
    Node(T data) : x(data), next(nullptr) {}
};

template<typename T>
class SLList {
private:
    Node<T>* head;
    int n;

public:
    SLList() : head(nullptr), n(0) {}

    // Helper method: return pointer to node at index i
    Node<T>* getNode(int i) {
        if (i < 0 || i >= n) throw std::out_of_range("Index out of range");
        Node<T>* current = head;
        int idx = 0;
        while (idx < i) {
            current = current->next;
            idx++;
        }
        return current;
    }

    // TODO: implement these four methods:

    // Return value at index i
    T get(int i) {
        // Your code here
    }

    // Replace value at index i with x, return old value
    T set(int i, T x) {
        // Your code here
    }

    // Insert x at index i
    void add(int i, T x) {
        // Your code here
    }

    // Remove element at index i, return its value
    T remove(int i) {
        // Your code here
    }

    // (Optional) other methods, e.g. size()
    int size() {
        return n;
    }
};

