/*
Write a DLList method isPalindrome() that returns true if the list is a palindrome,
i.e., the element at position i is equal to the element at position n-i-1 
for all i ∈ {0, …, n-1}. 
Your code should run in O(n) time.
*/

#include <iostream>
using namespace std;

template <typename T>
class DLList {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node(T val) : data(val), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int n;

public:
    DLList() : head(nullptr), tail(nullptr), n(0) {}

    // Add value to the end of the list
    void addLast(T value) {
        Node* u = new Node(value);
        if (n == 0) {
            head = tail = u;
        } else {
            tail->next = u;
            u->prev = tail;
            tail = u;
        }
        n++;
    }

    // Print the list for debugging
    void printList() {
        Node* cur = head;
        while (cur) {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    // TODO: Implement this
    bool isPalindrome() {
        // Hint:
        // 1. If n <= 1, return true
        // 2. Use two pointers: left = head, right = tail
        // 3. Compare left->data and right->data while moving inward
        // 4. If mismatch found, return false
        // 5. Otherwise, return true
        return false; // placeholder
    }
};

// Example usage
int main() {
    DLList<int> dll;
    dll.addLast(1);
    dll.addLast(2);
    dll.addLast(3);
    dll.addLast(2);
    dll.addLast(1);

    dll.printList();

    if (dll.isPalindrome()) {
        cout << "The list is a palindrome\n";
    } else {
        cout << "The list is NOT a palindrome\n";
    }

    return 0;
}

