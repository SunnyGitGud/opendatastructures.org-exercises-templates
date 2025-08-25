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

    bool isPalindrome() {
        if (n <= 1) return true;  // single element or empty list is trivially palindrome

        Node* left = head;
        Node* right = tail;

        for (int i = 0; i < n / 2; i++) {
            if (left->data != right->data) return false;
            left = left->next;
            right = right->prev;
        }
        return true;
    }

    void printList() {
        Node* cur = head;
        while (cur) {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }
};

int main() {
    DLList<int> dll;
    dll.addLast(1);
    dll.addLast(2);
    dll.addLast(3);
    dll.addLast(2);
    dll.addLast(1);

    dll.printList();

    if (dll.isPalindrome())
        cout << "The list is a palindrome\n";
    else
        cout << "The list is NOT a palindrome\n";

    return 0;
}

