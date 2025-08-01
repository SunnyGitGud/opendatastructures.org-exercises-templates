#include <vector>
#include <stdexcept>

/**
 * Treque (Triple-ended Queue) - A list implementation with:
 * - get(i) and set(i, x): O(1) 
 * - add(i, x) and remove(i): O(√n)
 * 
 * KEY INSIGHT: Use a "blocked" or "chunked" array structure
 * Think: Array of blocks, where each block is a small array
 */

template<typename T>
class Treque {
private:
    // HINT: You need a data structure that allows:
    // 1. O(1) random access within blocks
    // 2. O(√n) insertion/deletion by moving elements between blocks
    
    // What data structure should hold your blocks?
    // What should each block look like?
    // How big should each block be for optimal √n performance?

public:
    Treque() {
        // TODO: Initialize your blocked structure
        // HINT: What's the optimal block size for √n operations?
    }
    
    /**
     * Get element at index i - must be O(1)
     * HINT: Which block contains index i?
     * HINT: What's the offset within that block?
     */
    T get(int i) const {
        // TODO: Implement O(1) access
        // Think: How do you map global index to (block, local_index)?
        return T{};
    }
    
    /**
     * Set element at index i to value x - must be O(1)
     */
    void set(int i, const T& x) {
        // TODO: Implement O(1) assignment
        // Similar logic to get(), but assignment instead
    }
    
    /**
     * Add element x at index i - should be O(√n)
     * HINT: Find the right block, then shift elements
     * HINT: What happens when a block becomes too full?
     */
    void add(int i, const T& x) {
        // TODO: Implement O(√n) insertion
        // Key questions:
        // 1. Which block should contain the new element?
        // 2. How do you make space in that block?
        // 3. What if the block overflows?
    }
    
    /**
     * Remove element at index i - should be O(√n)
     * HINT: Find the right block, remove element, shift remaining
     * HINT: What happens when a block becomes too empty?
     */
    T remove(int i) {
        // TODO: Implement O(√n) removal
        // Key questions:
        // 1. Which block contains element i?
        // 2. How do you fill the gap after removal?
        // 3. What if the block becomes too small?
        return T{};
    }
    
    /**
     * Get current size
     */
    int size() const {
        // TODO: How do you track total size across all blocks?
        return 0;
    }
    
    bool empty() const {
        return size() == 0;
    }
};

#include <iostream>
#include <chrono>
#include <cassert>

// Test framework
void test_basic_operations() {
    std::cout << "Testing basic operations...\n";
    Treque<int> tq;
    
    // Test adding elements
    tq.add(0, 10);  // [10]
    tq.add(1, 20);  // [10, 20]
    tq.add(0, 5);   // [5, 10, 20]
    tq.add(2, 15);  // [5, 10, 15, 20]
    
    assert(tq.size() == 4);
    std::cout << "Size after additions: " << tq.size() << std::endl;
    
    // Test get operations
    std::cout << "Elements: ";
    for (int i = 0; i < tq.size(); ++i) {
        std::cout << tq.get(i) << " ";
    }
    std::cout << std::endl;
    
    // Test set operations
    tq.set(1, 100);
    std::cout << "After setting index 1 to 100: ";
    for (int i = 0; i < tq.size(); ++i) {
        std::cout << tq.get(i) << " ";
    }
    std::cout << std::endl;
    
    // Test remove operations
    int removed = tq.remove(2);
    std::cout << "Removed element: " << removed << std::endl;
    std::cout << "After removal: ";
    for (int i = 0; i < tq.size(); ++i) {
        std::cout << tq.get(i) << " ";
    }
    std::cout << std::endl;
}

void test_edge_cases() {
    std::cout << "\nTesting edge cases...\n";
    Treque<std::string> tq;
    
    // Test empty treque
    assert(tq.empty());
    std::cout << "Empty treque test passed\n";
    
    // Test single element
    tq.add(0, "first");
    assert(tq.size() == 1);
    assert(tq.get(0) == "first");
    
    // Test front and back insertions
    tq.add(0, "new_first");  // Insert at front
    tq.add(tq.size(), "last"); // Insert at back
    
    std::cout << "After front/back insertions: ";
    for (int i = 0; i < tq.size(); ++i) {
        std::cout << tq.get(i) << " ";
    }
    std::cout << std::endl;
}

void test_performance() {
    std::cout << "\nTesting performance characteristics...\n";
    Treque<int> tq;
    
    const int n = 1000;
    
    // Time insertions
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < n; ++i) {
        tq.add(i / 2, i); // Insert in middle-ish positions
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Time for " << n << " insertions: " << duration.count() << " microseconds\n";
    
    // Time random access (should be very fast - O(1))
    start = std::chrono::high_resolution_clock::now();
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += tq.get(i % tq.size());
    }
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Time for " << n << " random accesses: " << duration.count() << " microseconds\n";
    std::cout << "Sum (to prevent optimization): " << sum << std::endl;
    
    // Test large dataset
    std::cout << "Final treque size: " << tq.size() << std::endl;
}

void test_correctness() {
    std::cout << "\nTesting correctness with larger dataset...\n";
    Treque<int> tq;
    
    // Build a sequence: 0, 1, 2, ..., 99
    for (int i = 0; i < 100; ++i) {
        tq.add(i, i);
    }
    
    // Verify sequence
    bool correct = true;
    for (int i = 0; i < 100; ++i) {
        if (tq.get(i) != i) {
            correct = false;
            break;
        }
    }
    std::cout << "Sequential insertion test: " << (correct ? "PASSED" : "FAILED") << std::endl;
    
    // Test modifications
    for (int i = 0; i < 50; ++i) {
        tq.set(i, i * 10);
    }
    
    // Verify modifications
    correct = true;
    for (int i = 0; i < 50; ++i) {
        if (tq.get(i) != i * 10) {
            correct = false;
            break;
        }
    }
    for (int i = 50; i < 100; ++i) {
        if (tq.get(i) != i) {
            correct = false;
            break;
        }
    }
    std::cout << "Set operation test: " << (correct ? "PASSED" : "FAILED") << std::endl;
}

int main() {
    std::cout << "=== Treque Implementation Tests ===\n";
    
    try {
        test_basic_operations();
        test_edge_cases();
        test_correctness();
        test_performance();
        
        std::cout << "\n=== All Tests Completed ===\n";
        
    } catch (const std::exception& e) {
        std::cerr << "Test failed with exception: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
