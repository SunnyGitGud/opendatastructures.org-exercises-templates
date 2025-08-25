#include <stdexcept>
template<typename T>
class Dllist {
  struct Node { 
    T data;
    Node *next;
    Node *prev;

    Node(T d) : data(d), next(nullptr), prev(nullptr) {}
  };

  Node* head;
  Node* tail;
  int n;

public:
  Dllist() : head(nullptr), tail(nullptr), n(0) {}

  void addBefore(Node* w, T& value){
    Node *u = new Node(value);
    u->prev = w->prev;
    u->next = w;
    if (w->prev) {
      w->next->next = u;
    } else {
      head = u;
    }
    w->prev = u;
    n++;
  }
}; 
