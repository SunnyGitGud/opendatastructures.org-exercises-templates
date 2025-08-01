#include <vector>
#include <iostream>
#include <stdexcept>
using namespace std;

/**
 * Optimized ArrayDeque Implementation
 * 
 * Key Optimization: Replace expensive % operator with bitwise &
 * 
 * Mathematical Identity: If n is a power of 2, then:
 * k % n = k & (n - 1)
 * 
 * Why this works:
 * - Powers of 2 in binary: 4=100, 8=1000, 16=10000
 * - (power_of_2 - 1) creates a mask: 3=011, 7=0111, 15=01111
 * - Bitwise & with this mask keeps only the lower bits
 * - This is equivalent to modulo operation but much faster
 */

template<typename T>
class ArrayDeque {
private:
    vector<T> data;
    int head;        // Index of first element
    int tail;        // Index where next element will be inserted
    int n;           // Number of elements
    int capacity;    // Always a power of 2
    int mask;        // capacity - 1 (used for bitwise modulo)

    /**
     * Find the next power of 2 >= x
     */
    int next_power_of_2(int x) {
        // TODO: Implement this function
        // HINT: Start with 1 and keep doubling until >= x
        // HINT: Or use bit manipulation tricks
        return 1; // placeholder
    }

    /**
     * Fast modulo using bitwise AND
     * Only works when capacity is power of 2
     */
    int fast_mod(int index) const {
        // TODO: Replace expensive % with bitwise &
        // HINT: return index & mask;
        return index % capacity; // Replace this line
    }

    /**
     * Resize array when it gets full
     * New capacity should be next power of 2
     */
    void resize() {
        int old_capacity = capacity;
        capacity = capacity * 2;  // Double the capacity (still power of 2)
        mask = capacity - 1;      // Update mask
        
        vector<T> new_data(capacity);
        
        // TODO: Copy elements from old array to new array
        // HINT: Copy elements in correct order starting from head
        // HINT: Use fast_mod for index calculations
        
        data = move(new_data);
        head = 0;
        tail = n;
    }

public:
    /**
     * Constructor - ensure capacity is always power of 2
     */
    ArrayDeque(int initial_capacity = 8) {
        // TODO: Initialize with next power of 2 >= initial_capacity
        // TODO: Set mask = capacity - 1
        // TODO: Initialize head, tail, n
    }

    /**
     * Add element to back of deque
     */
    void add_back(const T& x) {
        // TODO: Check if resize needed
        // TODO: Add element at tail position
        // TODO: Update tail using fast_mod
        // TODO: Increment n
    }

    /**
     * Add element to front of deque
     */
    void add_front(const T& x) {
        // TODO: Check if resize needed
        // TODO: Move head backwards using fast_mod
        // TODO: Add element at new head position
        // TODO: Increment n
    }

    /**
     * Remove element from back of deque
     */
    T remove_back() {
        if (n == 0) throw runtime_error("Empty deque");
        
        // TODO: Move tail backwards using fast_mod
        // TODO: Get element at tail position
        // TODO: Decrement n
        // TODO: Return element
        
        return T{}; // placeholder
    }

    /**
     * Remove element from front of deque
     */
    T remove_front() {
        if (n == 0) throw runtime_error("Empty deque");
        
        // TODO: Get element at head position
        // TODO: Move head forward using fast_mod
        // TODO: Decrement n
        // TODO: Return element
        
        return T{}; // placeholder
    }

    /**
     * Get element at index i (0-based from front)
     */
    T get(int i) const {
        if (i < 0 || i >= n) throw out_of_range("Index out of range");
        
        // TODO: Calculate actual array index using fast_mod
        // HINT: actual_index = fast_mod(head + i)
        
        return T{}; // placeholder
    }

    /**
     * Set element at index i
     */
    void set(int i, const T& x) {
        if (i < 0 || i >= n) throw out_of_range("Index out of range");
        
        // TODO: Calculate actual array index and set value
    }

    // Utility methods
    int size() const { return n; }
    bool empty() const { return n == 0; }

    /**
     * Debug method to show internal state
     */
    void debug_print() const {
        cout << "Capacity: " << capacity << " (power of 2: " << 
                ((capacity & (capacity - 1)) == 0 ? "yes" : "no") << ")\n";
        cout << "Mask: " << mask << " (binary: ";
        for (int i = 7; i >= 0; --i) {
            cout << ((mask >> i) & 1);
        }
        cout << ")\n";
        cout << "Head: " << head << ", Tail: " << tail << ", Size: " << n << "\n";
        cout << "Data: [";
        for (int i = 0; i < capacity; ++i) {
            if (i == head) cout << "H";
            if (i == tail) cout << "T";
            cout << data[i];
            if (i < capacity - 1) cout << ", ";
        }
        cout << "]\n";
        cout << "Logical view: [";
        for (int i = 0; i < n; ++i) {
            cout << get(i);
            if (i < n - 1) cout << ", ";
        }
        cout << "]\n\n";
    }
};

/**
 * Helper functions to understand the optimization
 */
void demonstrate_bitwise_modulo() {
    cout << "=== Demonstrating Bitwise Modulo Optimization ===\n";
    
    int powers_of_2[] = {4, 8, 16, 32};
    
    for (int capacity : powers_of_2) {
        int mask = capacity - 1;
        cout << "Capacity: " << capacity << ", Mask: " << mask << "\n";
        
        cout << "Testing equivalence k % " << capacity << " == k & " << mask << ":\n";
        for (int k = 0; k < capacity * 2; ++k) {
            int mod_result = k % capacity;
            int bitwise_result = k & mask;
            cout << "k=" << k << ": " << mod_result << " vs " << bitwise_result;
            if (mod_result == bitwise_result) {
                cout << " ✓\n";
            } else {
                cout << " ✗\n";
            }
        }
        cout << "\n";
    }
}

void test_arraydeque() {
    cout << "=== Testing Optimized ArrayDeque ===\n";
    
    ArrayDeque<int> deque(5);  // Will round up to power of 2
    deque.debug_print();
    
    // Test adding to back
    cout << "Adding elements to back...\n";
    for (int i = 1; i <= 6; ++i) {
        deque.add_back(i);
        cout << "Added " << i << ": ";
        deque.debug_print();
    }
    
    // Test adding to front
    cout << "Adding elements to front...\n";
    for (int i = 10; i <= 12; ++i) {
        deque.add_front(i);
        cout << "Added " << i << " to front: ";
        deque.debug_print();
    }
    
    // Test removing
    cout << "Removing from front and back...\n";
    cout << "Removed from front: " << deque.remove_front() << "\n";
    deque.debug_print();
    
    cout << "Removed from back: " << deque.remove_back() << "\n";
    deque.debug_print();
}

void performance_comparison() {
    cout << "=== Performance Note ===\n";
    cout << "Bitwise AND (&) is typically much faster than modulo (%) because:\n";
    cout << "1. Modulo requires division, which is expensive\n";
    cout << "2. Bitwise AND is a single CPU instruction\n";
    cout << "3. Modern CPUs can execute multiple bitwise operations per cycle\n";
    cout << "\nThis optimization is especially important in:\n";
    cout << "- High-performance computing\n";
    cout << "- Real-time systems\n";
    cout << "- Systems with limited computational power\n\n";
}

/**
 * IMPLEMENTATION HINTS:
 * 
 * 1. next_power_of_2(x):
 *    Method 1: int result = 1; while (result < x) result *= 2; return result;
 *    Method 2: Use bit manipulation tricks
 * 
 * 2. fast_mod(index):
 *    Simply: return index & mask;
 * 
 * 3. For resize():
 *    - Copy elements in order from old array to new array
 *    - Use two loops or one loop with proper index calculation
 * 
 * 4. For add/remove operations:
 *    - Always use fast_mod instead of % when updating head/tail
 *    - Remember: (head - 1) might be negative, handle with: fast_mod(head - 1 + capacity)
 * 
 * 5. Key insight for negative indices:
 *    Since bitwise & only works with positive numbers, for (head - 1):
 *    Use: fast_mod(head - 1 + capacity) instead of fast_mod(head - 1)
 */

int main() {
    demonstrate_bitwise_modulo();
    test_arraydeque();
    performance_comparison();
    return 0;
}
