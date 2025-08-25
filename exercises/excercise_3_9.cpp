/*
------------------------------------------------------------
Exercise: Implement truncate(i) for a doubly-linked list

A DLList stores n elements indexed 0,1,...,n-1.

Write a method truncate(i) that:
 - Cuts the list into two parts at position i.
 - After calling truncate(i), the original list should only
   contain elements 0,...,i-1 (size = i).
 - The method should return a new DLList containing the
   elements i,...,n-1.
 - If i <= 0, then all elements move to the returned list and
   the current list becomes empty.
 - If i >= n, then nothing is moved and the returned list is empty.

Requirements:
 - Your method must run in O(min{i, n-i}) time.
 - Use pointer manipulation (no copying values).
 - Remember to handle edge cases.

Examples:
   [a,b,c,d,e].truncate(2) =>
       this: [a,b]
       return: [c,d,e]

   [a,b,c].truncate(0) =>
       this: []
       return: [a,b,c]

   [a,b,c].truncate(3) =>
       this: [a,b,c]
       return: []
------------------------------------------------------------
*/

template <class T>
class DLList {
private:
    struct Node {
        T x;
        Node* prev;
        Node* next;
    };

    Node* dummy; // sentinel node
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
    DLList<T> truncate(int i) {
        // TODO: write your code here
    }
};

