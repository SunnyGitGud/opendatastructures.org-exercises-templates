/*
Implement a method rotate(r) that "rotates" a DLList so that list item i becomes
list item (i + r) mod n. This method should run in O(1 + min{r, n-r}) time 
and should not modify any nodes in the list.
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

    void printList() {
        Node* cur = head;
        while (cur) {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    // TODO: Implement this
    void rotate(int r) {
        if (n == 0 || n == 1) return;  // nothing to rotate
        r = ((r % n) + n) % n;         // normalize r to [0, n-1]
        if (r == 0) return;            // no rotation needed

        // Hint:
        // - If r is small, move forward from head r steps
        // - If n-r is smaller, move backward from tail (n-r) steps
        // - The node you land on becomes the new head
        // - Update head and tail accordingly without reallocating nodes
    }
};

// Example usage
int main() {
    DLList<int> dll;
    dll.addLast(1);
    dll.addLast(2);
    dll.addLast(3);
    dll.addLast(4);
    dll.addLast(5);

    cout << "Original: ";
    dll.printList();

    dll.rotate(2); // After rotation: [3,4,5,1,2]

    cout << "After rotate(2): ";
    dll.printList();

    return 0;
}

