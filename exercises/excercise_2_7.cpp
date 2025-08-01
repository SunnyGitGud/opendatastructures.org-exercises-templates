#include <vector>
#include <iostream>
#include <chrono>
#include <algorithm>
#include <stdexcept>
using namespace std;
using namespace std::chrono;

/**
 * ConsecutiveArrayDeque - No modular arithmetic variant
 * 
 * Key Ideas:
 * 1. Data stored consecutively in array: [unused][data_block][unused]
 * 2. No circular buffer - linear layout only
 * 3. When data hits array boundaries, rebuild to center the data
 * 4. Smart rebuild strategy ensures amortized O(1) performance
 * 
 * Layout: [----][data data data data][----]
 *              ^head            ^tail
 */

template<typename T>
class ConsecutiveArrayDeque {
private:
    vector<T> data;
    int head;        // Index of first element
    int tail;        // Index after last element
    int capacity;    // Total array size
    
    /**
     * CRITICAL: The rebuild operation
     * 
     * Goal: Position data so it can't run off either end for n/2 operations
     * Strategy: Center the data with equal buffer space on both sides
     */
    void rebuild() {
        int n = size();
        if (n == 0) {
            head = capacity / 2;
            tail = head;
            return;
        }
        
        // TODO: Implement smart rebuild strategy
        // HINT: Calculate new_head to center the data
        // HINT: new_head should leave room for n/2 operations on each side
        // HINT: Copy data block to new position
        
        // Strategy: Place data in center of array
        int new_head = (capacity - n) / 2;
        
        // TODO: Copy the consecutive data block
        // HINT: Source: data[head] to data[tail-1]
        // HINT: Destination: data[new_head] to data[new_head + n - 1]
        // HINT: Use memmove or std::copy for efficiency
        
        head = new_head;
        tail = new_head + n;
    }
    
    /**
     * Resize array when needed (double capacity)
     */
    void resize() {
        int old_capacity = capacity;
        capacity = capacity * 2;
        
        vector<T> new_data(capacity);
        
        // TODO: Copy existing data to new array
        // HINT: Simply copy the consecutive block
        // HINT: Don't need to change head/tail relative positions
        
        data = move(new_data);
        
        // Rebuild to center data in larger array
        rebuild();
    }

public:
    ConsecutiveArrayDeque(int initial_capacity = 16) 
        : data(initial_capacity), capacity(initial_capacity) {
        // TODO: Initialize head and tail to center of array
        head = capacity / 2;
        tail = head;
    }
    
    /**
     * Add element to back
     * No modular arithmetic - just increment tail
     */
    void add_back(const T& x) {
        // TODO: Check if tail would go beyond array bounds
        if (tail >= capacity) {
            // TODO: Decide whether to resize or rebuild
            // HINT: If array is full, resize. Otherwise, rebuild.
        }
        
        // TODO: Add element and increment tail
        data[tail] = x;
        tail++;
    }
    
    /**
     * Add element to front
     * No modular arithmetic - just decrement head
     */
    void add_front(const T& x) {
        // TODO: Check if head would go below 0
        if (head <= 0) {
            // TODO: Decide whether to resize or rebuild
        }
        
        // TODO: Decrement head and add element
        head--;
        data[head] = x;
    }
    
    /**
     * Remove from back
     */
    T remove_back() {
        if (empty()) throw runtime_error("Empty deque");
        
        // TODO: Decrement tail and return element
        tail--;
        return data[tail];
    }
    
    /**
     * Remove from front
     */
    T remove_front() {
        if (empty()) throw runtime_error("Empty deque");
        
        // TODO: Get element and increment head
        T result = data[head];
        head++;
        return result;
    }
    
    /**
     * Get element at index i (0-based from front)
     * Pure array access - no modular arithmetic!
     */
    T get(int i) const {
        if (i < 0 || i >= size()) throw out_of_range("Index out of range");
        
        // TODO: Simple array access
        // HINT: Element i is at position head + i
        return data[head + i];
    }
    
    /**
     * Set element at index i
     */
    void set(int i, const T& x) {
        if (i < 0 || i >= size()) throw out_of_range("Index out of range");
        
        // TODO: Simple array access
        data[head + i] = x;
    }
    
    // Utility methods
    int size() const { return tail - head; }
    bool empty() const { return head == tail; }
    
    /**
     * Get buffer space on each side (for analysis)
     */
    int left_buffer() const { return head; }
    int right_buffer() const { return capacity - tail; }
    
    void debug_print() const {
        cout << "Capacity: " << capacity << ", Size: " << size() << "\n";
        cout << "Head: " << head << ", Tail: " << tail << "\n";
        cout << "Left buffer: " << left_buffer() << ", Right buffer: " << right_buffer() << "\n";
        cout << "Data layout: [";
        for (int i = 0; i < capacity; ++i) {
            if (i == head) cout << "|";
            if (i >= head && i < tail) {
                cout << data[i];
            } else {
                cout << "_";
            }
            if (i == tail - 1) cout << "|";
            if (i < capacity - 1) cout << " ";
        }
        cout << "]\n\n";
    }
};

/**
 * Traditional circular ArrayDeque for comparison
 */
template<typename T>
class CircularArrayDeque {
private:
    vector<T> data;
    int head, tail, n, capacity;
    
    int mod(int x) const {
        return ((x % capacity) + capacity) % capacity;
    }
    
    void resize() {
        vector<T> new_data(capacity * 2);
        for (int i = 0; i < n; ++i) {
            new_data[i] = data[mod(head + i)];
        }
        data = move(new_data);
        capacity *= 2;
        head = 0;
        tail = n;
    }
    
public:
    CircularArrayDeque(int cap = 16) : data(cap), head(0), tail(0), n(0), capacity(cap) {}
    
    void add_back(const T& x) {
        if (n == capacity) resize();
        data[tail] = x;
        tail = mod(tail + 1);
        n++;
    }
    
    void add_front(const T& x) {
        if (n == capacity) resize();
        head = mod(head - 1);
        data[head] = x;
        n++;
    }
    
    T remove_back() {
        if (n == 0) throw runtime_error("Empty deque");
        tail = mod(tail - 1);
        n--;
        return data[tail];
    }
    
    T remove_front() {
        if (n == 0) throw runtime_error("Empty deque");
        T result = data[head];
        head = mod(head + 1);
        n--;
        return result;
    }
    
    T get(int i) const {
        if (i < 0 || i >= n) throw out_of_range("Index out of range");
        return data[mod(head + i)];
    }
    
    int size() const { return n; }
    bool empty() const { return n == 0; }
};

// Performance testing
void performance_test() {
    cout << "=== Performance Comparison ===\n";
    
    const int operations = 1000000;
    
    // Test ConsecutiveArrayDeque
    {
        ConsecutiveArrayDeque<int> deque;
        auto start = high_resolution_clock::now();
        
        for (int i = 0; i < operations; ++i) {
            if (i % 4 == 0) deque.add_back(i);
            else if (i % 4 == 1) deque.add_front(i);
            else if (i % 4 == 2 && !deque.empty()) deque.remove_back();
            else if (!deque.empty()) deque.remove_front();
        }
        
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        cout << "ConsecutiveArrayDeque: " << duration.count() << " microseconds\n";
        cout << "Final size: " << deque.size() << "\n";
    }
    
    // Test CircularArrayDeque
    {
        CircularArrayDeque<int> deque;
        auto start = high_resolution_clock::now();
        
        for (int i = 0; i < operations; ++i) {
            if (i % 4 == 0) deque.add_back(i);
            else if (i % 4 == 1) deque.add_front(i);
            else if (i % 4 == 2 && !deque.empty()) deque.remove_back();
            else if (!deque.empty()) deque.remove_front();
        }
        
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        cout << "CircularArrayDeque: " << duration.count() << " microseconds\n";
        cout << "Final size: " << deque.size() << "\n";
    }
}

void test_consecutive_deque() {
    cout << "=== Testing ConsecutiveArrayDeque ===\n";
    
    ConsecutiveArrayDeque<int> deque(8);
    
    cout << "Initial state:\n";
    deque.debug_print();
    
    // Add elements to back
    cout << "Adding to back: 1, 2, 3\n";
    deque.add_back(1);
    deque.add_back(2);
    deque.add_back(3);
    deque.debug_print();
    
    // Add elements to front
    cout << "Adding to front: 10, 20\n";
    deque.add_front(10);
    deque.add_front(20);
    deque.debug_print();
    
    // Force rebuild by filling up one side
    cout << "Adding more to back to trigger rebuild:\n";
    for (int i = 4; i <= 8; ++i) {
        deque.add_back(i);
        cout << "Added " << i << ":\n";
        deque.debug_print();
    }
    
    // Test access
    cout << "Element at index 2: " << deque.get(2) << "\n";
    cout << "Setting index 2 to 99\n";
    deque.set(2, 99);
    cout << "Element at index 2: " << deque.get(2) << "\n";
}

/**
 * IMPLEMENTATION HINTS:
 * 
 * 1. rebuild() strategy:
 *    - Calculate: new_head = (capacity - size()) / 2
 *    - This centers the data with equal buffer on both sides
 *    - Copy consecutive block from [head, tail) to [new_head, new_head + size())
 * 
 * 2. When to rebuild vs resize:
 *    - If size() == capacity: resize (array is full)
 *    - Otherwise: rebuild (just hit boundary, but array has space)
 * 
 * 3. Optimization with std::copy:
 *    - Use: std::copy(data.begin() + head, data.begin() + tail, new_position)
 *    - Or: memmove for POD types
 * 
 * 4. Amortized analysis:
 *    - After rebuild, data is centered
 *    - Can perform size()/2 operations before hitting boundary again
 *    - Each element moved at most twice per rebuild cycle
 *    - Amortized O(1) per operation
 * 
 * 5. Performance advantages:
 *    - No modular arithmetic (faster on some architectures)
 *    - Better cache locality (consecutive memory access)
 *    - Simpler index calculations
 */

int main() {
    test_consecutive_deque();
    performance_test();
    return 0;
}
