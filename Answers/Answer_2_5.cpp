#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

template<typename T>
class ArrayQueue {
private:
    vector<T> data;
    int head;    // Index of first element
    int tail;    // Index of next insertion point
    int n;       // Current number of elements
    int capacity;

  void resize(int new_capacity) {
    vector<T> new_data(new_capacity);

for (int i = 0; i < n; ++n){
      new_data[i] = data[(head + i) % capacity];
    }
    data = std::move(new_data);
    head = 0;
    tail = n;
    capacity = new_capacity;

  }

public:
    ArrayQueue(int cap = 10) : data(cap), head(0), tail(0), n(0), capacity(cap) {}
    
    void add(const T& x) {
    if (n == capacity) resize(capacity * 2);
    data[tail] = x;
    tail = (tail + 1) % capacity;
    ++n;
    }
    
    T remove() {
        if (n == 0) throw runtime_error("Empty queue");
        T rHead = data[head];
        head = (head + 1) % capacity;
        --n;
        // Your implementation here
        return rHead;
    }
    
   void rotate(int r) {
    if (n == 0) return;
    r = ((r % n) + n) % n;    
    if (r > n/2) {
       head = (head - r + capacity) % capacity;
       tail = (tail - r + capacity) % capacity;    
    }
   }
    
    // Helper methods
    T get(int i) const {
        if (i < 0 || i >= n) throw out_of_range("Index out of range");
       return data[(head + i) % capacity];
    }
    
    int size() const { return n; }
    bool empty() const { return n == 0; }
    
    void print() const {
        cout << "Queue: [";
        for (int i = 0; i < n; ++i) {
            cout << get(i);
            if (i < n-1) cout << ", ";
        }
        cout << "] (head=" << head << ", tail=" << tail << ")\n";
    }
};

template<typename T>
class DualArrayQueue {
private:
    vector<T> front;  // Elements to remove (in reverse order)
    vector<T> back;   // Elements to add (in normal order)

public:
    void add(const T& x) {
        back.push_back(x);
    }
    
    T remove() {
        if (empty()) throw runtime_error("Empty queue");
        
        if (front.empty()) {
            // Move elements from back to front
            while (!back.empty()) {
                front.push_back(back.back());
                back.pop_back();
            }
        }
        
        T result = front.back();
        front.pop_back();
        return result;
    }
    
   void rotate(int r) {
        int n = size();        
        if (n == 0) return;
        r = ((r % n) + n) % n;
        if ( r <= n - r) {
        for (int i = 0; i < r; ++i) {
        if (back.empty()) {
          while (!front.empty()) {
            back.push_back(front.back());
            front.pop_back();
          }
        }
          front.push_back(back.back());
           back.pop_back();
        }
    }        
        else {
        for(int i = 0; i < r; ++i) {
        if (front.empty()) {
          while (!back.empty()) {
            front.push_back(back.back());
            back.pop_back();
          
          }
        
        }
        back.push_back(front.back());
        front.pop_back();
      }
        }
       }
    
    // Helper methods
    int size() const { return front.size() + back.size(); }
    bool empty() const { return front.empty() && back.empty(); }
    
    void print() const {
        cout << "DualQueue: front=[";
        for (int i = front.size()-1; i >= 0; --i) {
            cout << front[i];
            if (i > 0) cout << ", ";
        }
        cout << "] back=[";
        for (int i = 0; i < back.size(); ++i) {
            cout << back[i];
            if (i < back.size()-1) cout << ", ";
        }
        cout << "]\n";
    }
};

// Test functions
void test_array_queue() {
    cout << "=== Testing ArrayQueue Rotation ===\n";
    
    ArrayQueue<int> q;
    
    // Add some elements
    for (int i = 1; i <= 6; ++i) {
        q.add(i);
    }
    
    cout << "Initial: ";
    q.print();
    
    // Test various rotations
    q.rotate(2);
    cout << "After rotate(2): ";
    q.print();
    
    q.rotate(-1);
    cout << "After rotate(-1): ";
    q.print();
    
    q.rotate(10);  // Should normalize to rotate(4)
    cout << "After rotate(10): ";
    q.print();
}

void test_dual_array_queue() {
    cout << "\n=== Testing DualArrayQueue Rotation ===\n";
    
    DualArrayQueue<int> q;
    
    // Add some elements
    for (int i = 1; i <= 6; ++i) {
        q.add(i);
    }
    
    cout << "Initial: ";
    q.print();
    
    // Test rotations
    q.rotate(2);
    cout << "After rotate(2): ";
    q.print();
    
    q.rotate(-3);
    cout << "After rotate(-3): ";
    q.print();
}

void test_performance() {
    cout << "\n=== Performance Test ===\n";
    
    ArrayQueue<int> q;
    for (int i = 0; i < 1000; ++i) {
        q.add(i);
    }
    
    // These should all be fast due to O(1 + min{r, n-r}) complexity
    cout << "Testing large rotations (should be fast)...\n";
    q.rotate(100);     // O(1 + 100)
    q.rotate(950);     // Should choose to go backwards: O(1 + 50)
    q.rotate(-100);    // O(1 + 100)
    
    cout << "Performance test completed\n";
}

int main() {
    test_array_queue();
    test_dual_array_queue();
    test_performance();
    return 0;
}
