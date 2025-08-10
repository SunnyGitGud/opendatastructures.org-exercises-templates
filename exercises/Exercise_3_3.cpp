/*
    QUESTION:
    Design and implement an SLList method `reverse()` that reverses the order 
    of elements in the SLList.

    REQUIREMENTS:
    - The method should run in O(n) time, where n is the number of nodes.
    - Do NOT use recursion.
    - Do NOT use any secondary data structures (arrays, stacks, etc.).
    - Do NOT create any new nodes.
    - You should rearrange the existing nodes by changing their `next` pointers.

    HINT:
    - You will need to keep track of three pointers as you iterate through the list:
      previous, current, and next.
    - At each step, reverse the `next` pointer of the current node.
    - Update the head pointer after reversal.
*/

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

public:
    SLList() : head(nullptr) {}

    // Adds to the end of the list
    void addLast(T data) {
        Node<T>* node = new Node<T>(data);
        if (!head) {
            head = node;
            return;
        }
        Node<T>* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = node;
    }

    void reverse() {
        // TODO: Implement reversal here
    }
};
