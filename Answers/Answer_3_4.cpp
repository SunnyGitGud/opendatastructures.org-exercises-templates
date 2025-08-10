


#include <stdexcept>
template<typename T>
class Node {
  T x;
  Node *next;

  Node(T data) {
    x = data;
    next = nullptr;
  }
};

template<typename T>
class Slist {
private:
  Node<T> *head;
  int n;

public:
  Slist() {
  head = nullptr;
  n = 0;
  }
  
  void addLast(T data) {
    Node<T> *node = new Node<T>(data);
    if(!head) {
      head = node;
    } else {
      Node<T> *current = head;
      while (current->next) {
       current =  current->next; 
      }
      current->next = node;
    }
    n++;
  }

  Node<T> *get(int i){
    if (i < 0) {
      throw std::out_of_range("out_of_range");
    }
    Node<T> *current = head;
    int idx = 0;

    while (current != nullptr && idx < i) {
      current = current->next;
      idx++;
    }

    if (current==nullptr) {
      throw std::out_of_range("out_of_range"); 
    }

    return current;
  }

  T set(int i, T x) {
    Node<T> *current = get(i);
    T oldValue = current->x;
    current->x= x;
    return current;
  }

  void add(int i, T x) {
    if (i < 0) throw std::out_of_range("Index out of range");
    Node<T> newNode = new Node<T>(x);
    
    if (i == 0) {
      newNode->next = head;
      head = newNode;
      n++;
      return; 
    }
    
    Node<T> *prev = get(i - 1);
    newNode->next = prev->next;
    prev->next = newNode;
    n++;
  }
  
  T remove(int i) {
    if (i < 0) throw std::out_of_range("Index out of range");

    if (i==0) {
      Node<T> *toRemove = head;
      T value = toRemove->x;
      head = head->next;
      delete toRemove;
      n--;
      return value;
    }
    Node<T> *prev = get(i - 1);
    Node<T> *toRemove = prev->next;
    T value = toRemove->x;
    prev->next = toRemove->next;
    delete toRemove;
    n--;
    return value;
  }
  
};
