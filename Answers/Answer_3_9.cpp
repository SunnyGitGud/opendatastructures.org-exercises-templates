

template<class T>
class DLList {
private:
  struct Node {
    T x;
    Node *prev;
    Node *next;
  };

  Node* dummy;
  int n;

  Node *getNode(int i) const {
    if (i <= n/2) {
      Node *p = dummy->next;
      for (int k = 0; k < i; ++k) p->next;
      return p;
    } else {
      Node *p = dummy;
      for (int k = 0; k < i; ++k) p = p->prev;
      return p;
    }
  }

public:
  DLList() : n(0) {
    dummy = new Node();
    dummy->next = dummy->prev = dummy;
  }
  
  DLList<T> truncate(int i) {
    if (i <= 0) {
      DLList<T> out;
      if (n == 0) return out; 
      out.dummy->next = dummy->next;
      out.dummy->prev = dummy->prev;
      out.dummy->next->prev = out.dummy;
      out.dummy->prev->next = out.dummy;
      out.n = n;  


      dummy->next = dummy->prev = dummy;
      n = 0;
      return out;
    }

    if (i >= n) {
      return DLList<T>(); 
    }

    Node *w = getNode(i);
    Node *p = w->prev;
    Node *old_tail = dummy->prev;

    DLList<T> out;

    out.dummy->next = w;
    w->prev = out.dummy;
    out.dummy->prev = old_tail;
    old_tail->next = out.dummy;
    out.n = n-i;

    return out;
  }
};
