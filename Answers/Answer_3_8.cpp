
#include <iostream>
template<typename T>
class Dllist {
private:
  struct Node {
    T data;
    Node *next;
    Node *prev;

    Node(T val) : data(val), next(nullptr), prev(nullptr) {}
  };

  Node *head;
  Node *tail;
  int n;

public:
  Dllist() : head(nullptr), tail(nullptr), n(0) {}

  void addLast(T value) {
    Node *u = new Node(value);
    if(n==0) {
      head = tail = u;
    } else {
    tail->next = u;
      u->prev = tail;
      tail = u;
    };
    n++;
  };
  void printList() {
  Node* cur = head;
  while (cur) {
    std::cout << cur->data << "";
      cur = cur->next;
    }
  }

  void rotate(int r) {
    if(n == 0) return;
    r = ((r % n) + n) % n;
    if(r == 0)return;
    
    Node *newHead;

    if (r <= n/2) {
     newHead = head;
     for (int i = 0; i < r; i++) {
        newHead = newHead->next;
      }
    } else {
    newHead = tail;
      for(int i = 0; i < (n - r); i++) {
        newHead= newHead->prev;
      }
    }
    Node *newTail = newHead->prev;
    
    tail->next = head;
    head->prev = tail;

    head = newHead;
    tail = newHead;
    head->prev = nullptr;
    tail->next = nullptr;

  }
};

int main() {
    Dllist<int> dll;
    dll.addLast(1);
    dll.addLast(2);
    dll.addLast(3);
    dll.addLast(4);
    dll.addLast(5);

    std::cout << "Original: ";
    dll.printList();

    dll.rotate(2); // After rotation: [3,4,5,1,2]
    std::cout << "After rotate(2): ";
    dll.printList();

    dll.rotate(-1); // Rotate backwards by 1 → [2,3,4,5,1]
    std::cout << "After rotate(-1): ";
    dll.printList();

    return 0;
}
