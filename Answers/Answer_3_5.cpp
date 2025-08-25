
#include <stdexcept>
#include <iostream>

template<typename T>
class Sllist {
private:
   struct Node {
    T data;
    Node* next;
    Node(const T& d, Node* n = nullptr) : data(d), next(n) {};
  };

  Node* head;
  int n;
  
public:
  Sllist() : head(nullptr), n(0) {}

  void checksize() {
    int count = 0;
    for (Node *p = head; p != nullptr; p = p->next){
      ++count;
    } 
    
    if (count != n) {
      throw std::runtime_error("size missmatch"); 
    };
  }
};

template<typename T>
class Dllist {
private:
  struct Node {
    T data;
    Node* prev;
    Node* next;
    Node(const T& d, Node* p = nullptr, Node* n = nullptr) 
        : data(d), prev(p), next(n) {}
  };

  Node* head;
  Node* tail;
  int n;

public:
  Dllist() : head(nullptr), tail(nullptr), n(0) {}

  void checkSize() {
    int count = 0;
    Node* prevs = nullptr;
    for (Node *p = head; p  != nullptr; p = p-> next) {
      if (p->prev != prevs) {
        throw std::runtime_error("Broken link"); 
      }
      prevs = p;
      ++count;
      if (count != n) {
        throw std::runtime_error("size missmatch"); 
      }
    }
  }
};

