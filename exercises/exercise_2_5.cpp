#include <vector>
#include <iostream>
using namespace std;

/**
 * Queue Rotation Problem:
 * Implement rotate(r) for ArrayQueue and DualArrayQueue
 * that runs in O(1 + min{r, n-r}) time
 * 
 * Key Insight: Instead of moving elements, adjust the indices!
 * - ArrayQueue: Move the head/tail pointers
 * - DualArrayQueue: Move elements between front/back arrays efficiently
 */

/**
 * ArrayQueue with rotation support
 * Uses circular buffer with head/tail pointers
 */
template<typename T>
class ArrayQueue {
private:
    vector<T> data;
    int head;    // Index of first element
    int tail;    // Index of next insertion point
    int n;       // Current number of elements
    int capacity;

public:
    ArrayQueue(int cap = 10) : data(cap), head(0), tail(0), n(0), capacity(cap) {}
    
    void add(const T& x) {
        // TODO: Add element at tail
        // HINT: Use modular arithmetic for circular buffer
        // HINT: Handle resizing when full
    }
    
    T remove() {
        // TODO: Remove element from head
        // HINT: Use modular arithmetic
        if (n == 0) throw runtime_error("Empty queue");
        
        // Your implementation here
        return T{};
    }
    
    /**
     * MAIN CHALLENGE: Rotate in O(1 + min{r, n-r}) time
     * 
     * Key insight: Don't move elements, just adjust head pointer!
     * - Positive r: move head forward by r positions
     * - Negative r: move head backward by |r| positions
     * - Choose direction that requires fewer moves
     */
    void rotate(int r) {
        if (n == 0) return;
        
        // TODO: Normalize r to range [0, n)
        // HINT: r = ((r % n) + n) % n;
        
        // TODO: Choose optimal direction
        // HINT: If r > n/2, it's better to go the other way
        // HINT: Going right by r is same as going left by (n-r)
        
        // TODO: Adjust head pointer
        // HINT: new_head = (head + r) % capacity
        
        // Your implementation here
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

/**
 * DualArrayQueue with rotation support
 * Uses two stacks: front (for removing) and back (for adding)
 */
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
    
    /**
     * CHALLENGE: Implement rotate(r) in O(1 + min{r, n-r}) time
     * 
     * This is trickier than ArrayQueue because elements are split
     * between two arrays. You need to move elements efficiently.
     * 
     * Strategy:
     * 1. Choose direction (forward/backward) that moves fewer elements
     * 2. Move exactly min{r, n-r} elements between front/back arrays
     */
    void rotate(int r) {
        int n = size();
        if (n == 0) return;
        
        // TODO: Normalize r
        
        // TODO: Determine optimal strategy
        // Option 1: Move r elements from front to back
        // Option 2: Move (n-r) elements from back to front
        
        // TODO: Choose the option that moves fewer elements
        // HINT: This is where you get O(1 + min{r, n-r}) complexity
        
        // Your implementation here
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
