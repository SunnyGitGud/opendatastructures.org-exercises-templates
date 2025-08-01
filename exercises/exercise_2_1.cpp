
/*
IMPLEMENTATION HINTS FOR EXERCISE 2.1:

1. resize() method:
   - Create new array with 2x capacity
   - Copy existing elements
   - Delete old array, update pointer

2. addAll_inefficient():
   - Use a simple loop calling add(i+j, c[j]) for each element
   - This is O(k*n) where k is elements to insert

3. addAll_efficient():
   - Calculate total elements to insert (k)
   - Ensure capacity: if (n + k >= capacity) resize until big enough
   - Single shift: move elements a[i..n-1] to a[i+k..n+k-1]
   - Copy all elements from container at once
   - Update n += k
   - This is O(k + n) instead of O(k*n)

KEY INSIGHT: Bulk operations should minimize the number of element shifts!
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cmath>
#include <functional>
#include <cassert>
#include <random>
#include <iomanip>
#include <stdexcept>

/*
=============================================================================
EXERCISE 2.1 - ARRAYSTACK WASTES MEMORY AFTER REMOVE() OPERATIONS
=============================================================================
*/

template<typename T>
class ArrayStack {
private:
    T* a;           // backing array
    int n;          // number of elements
    int capacity;   // current capacity of array
    
    void resize() {
        // TODO: Implement resize operation
        // Hint: typically double the capacity when growing
       
    }

public:
    ArrayStack() : n(0), capacity(1) {
        a = new T[capacity];
    }
    
    ~ArrayStack() {
        delete[] a;
    }
    
    // Copy constructor for testing
    ArrayStack(const ArrayStack& other) : n(other.n), capacity(other.capacity) {
        a = new T[capacity];
        for (int i = 0; i < n; i++) {
            a[i] = other.a[i];
        }
    }
    
    // Basic operations
    void add(int i, T x) {
        // TODO: Implement single element insertion
        if (i < 0 || i > n) throw std::out_of_range("Index out of bounds");
        if (n >= capacity) resize();
        
        // Shift elements to the right
        for (int j = n; j > i; j--) {
            a[j] = a[j-1];
        }
        
        a[i] = x;
        n++;
    }
    
    T get(int i) const {
        if (i < 0 || i >= n) throw std::out_of_range("Index out of bounds");
        return a[i];
    }
    
    int size() const {
        return n;
    }
    
    void print() const {
        std::cout << "[";
        for (int i = 0; i < n; i++) {
            std::cout << a[i];
            if (i < n-1) std::cout << ", ";
        }
        std::cout << "]" << std::endl;
    }
    
    // Exercise 2.1: Implement these two methods
    
    // Method 1: Inefficient implementation using repeated add() calls
    template<typename Container>
    void addAll_inefficient(int i, const Container& c) {
        // TODO: Implement using repeated calls to add(i, x)
        // This should demonstrate why this approach is slow
           }
    
    // Method 2: Efficient implementation 
    template<typename Container>
    void addAll_efficient(int i, const Container& c) {
        // TODO: Implement efficient version
        // Steps:
        // 1. Calculate how many elements to insert (k = c.size())
              
        // 3. Perform single shift operation to make space
              
        // 4. Copy all elements from container c at once
     
        
        // 5. Update n
       
    }
};

// Helper function to create test data for Exercise 2.1
std::vector<int> createTestData(int size) {
    std::vector<int> data;
    for (int i = 0; i < size; i++) {
        data.push_back(i * 10);
    }
    return data;
}


// Helper function to create test data
std::vector<int> createTestData(int size) {
    std::vector<int> data;
    for (int i = 0; i < size; i++) {
        data.push_back(i * 10);
    }
    return data;
}


class TestFramework {
private:
    int tests_passed = 0;
    int tests_failed = 0;
    
public:
    void assert_equal(int expected, int actual, const std::string& test_name) {
        if (expected == actual) {
            std::cout << "✓ " << test_name << " PASSED" << std::endl;
            tests_passed++;
        } else {
            std::cout << "✗ " << test_name << " FAILED: expected " << expected 
                      << ", got " << actual << std::endl;
            tests_failed++;
        }
    }
    
    void assert_true(bool condition, const std::string& test_name) {
        if (condition) {
            std::cout << "✓ " << test_name << " PASSED" << std::endl;
            tests_passed++;
        } else {
            std::cout << "✗ " << test_name << " FAILED" << std::endl;
            tests_failed++;
        }
    }
    
    void assert_throws(std::function<void()> func, const std::string& test_name) {
        try {
            func();
            std::cout << "✗ " << test_name << " FAILED: expected exception" << std::endl;
            tests_failed++;
        } catch (...) {
            std::cout << "✓ " << test_name << " PASSED" << std::endl;
            tests_passed++;
        }
    }
    
    void print_summary() {
        std::cout << "\n=== Test Summary ===" << std::endl;
        std::cout << "Passed: " << tests_passed << std::endl;
        std::cout << "Failed: " << tests_failed << std::endl;
        std::cout << "Total:  " << (tests_passed + tests_failed) << std::endl;
    }
};

void testExercise2_1() {
    std::cout << "\n=== Exercise 2.1: Bulk Insertion Optimization Tests ===" << std::endl;
    TestFramework tf;
    
    // Test 1: Basic functionality test
    {
        ArrayStack<int> stack;
        for (int i = 0; i < 5; i++) {
            stack.add(i, i * 2);
        }
        
        std::vector<int> testData = {100, 200, 300};
        
        // Test inefficient method
        ArrayStack<int> stack1 = stack;
        stack1.addAll_inefficient(2, testData);
        
        tf.assert_equal(8, stack1.size(), "Inefficient addAll - correct size");
        tf.assert_equal(0, stack1.get(0), "Inefficient addAll - element 0");
        tf.assert_equal(2, stack1.get(1), "Inefficient addAll - element 1");
        tf.assert_equal(100, stack1.get(2), "Inefficient addAll - inserted element 0");
        tf.assert_equal(200, stack1.get(3), "Inefficient addAll - inserted element 1");
        tf.assert_equal(300, stack1.get(4), "Inefficient addAll - inserted element 2");
        tf.assert_equal(4, stack1.get(5), "Inefficient addAll - shifted element");
        
        // Test efficient method
        ArrayStack<int> stack2 = stack;
        stack2.addAll_efficient(2, testData);
        
        tf.assert_equal(8, stack2.size(), "Efficient addAll - correct size");
        tf.assert_equal(0, stack2.get(0), "Efficient addAll - element 0");
        tf.assert_equal(2, stack2.get(1), "Efficient addAll - element 1");
        tf.assert_equal(100, stack2.get(2), "Efficient addAll - inserted element 0");
        tf.assert_equal(200, stack2.get(3), "Efficient addAll - inserted element 1");
        tf.assert_equal(300, stack2.get(4), "Efficient addAll - inserted element 2");
        tf.assert_equal(4, stack2.get(5), "Efficient addAll - shifted element");
    }
    
    // Test 2: Edge cases
    {
        ArrayStack<int> stack;
        std::vector<int> empty_data;
        
        // Insert empty collection
        stack.addAll_efficient(0, empty_data);
        tf.assert_equal(0, stack.size(), "Empty collection insertion");
        
        // Insert at beginning
        std::vector<int> front_data = {1, 2, 3};
        stack.addAll_efficient(0, front_data);
        tf.assert_equal(3, stack.size(), "Insert at beginning - size");
        tf.assert_equal(1, stack.get(0), "Insert at beginning - first element");
        
        // Insert at end
        std::vector<int> end_data = {4, 5};
        stack.addAll_efficient(stack.size(), end_data);
        tf.assert_equal(5, stack.size(), "Insert at end - size");
        tf.assert_equal(5, stack.get(4), "Insert at end - last element");
    }
    
    // Test 3: Performance comparison
    {
        std::cout << "\nPerformance Comparison:" << std::endl;
        std::vector<int> sizes = {100, 500, 1000};
        
        for (int size : sizes) {
            ArrayStack<int> s1, s2;
            
            // Pre-populate
            for (int i = 0; i < size/2; i++) {
                s1.add(i, i);
                s2.add(i, i);
            }
            
            std::vector<int> testData(size/4);
            std::iota(testData.begin(), testData.end(), 1000);
            
            // Time inefficient method
            auto start = std::chrono::high_resolution_clock::now();
            s1.addAll_inefficient(size/4, testData);
            auto end = std::chrono::high_resolution_clock::now();
            auto inefficient_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            
            // Time efficient method
            start = std::chrono::high_resolution_clock::now();
            s2.addAll_efficient(size/4, testData);
            end = std::chrono::high_resolution_clock::now();
            auto efficient_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            
            std::cout << "Size " << size << ": Inefficient=" << inefficient_time.count() 
                      << "μs, Efficient=" << efficient_time.count() << "μs";
            if (efficient_time.count() > 0) {
                double speedup = (double)inefficient_time.count() / efficient_time.count();
                std::cout << ", Speedup=" << std::fixed << std::setprecision(2) << speedup << "x";
            }
            std::cout << std::endl;
        }
    }
    
    // Test 4: Error handling
    {
        ArrayStack<int> stack;
        std::vector<int> data = {1, 2, 3};
        
        tf.assert_throws([&]() { stack.addAll_efficient(-1, data); }, 
                        "Negative index throws exception");
        tf.assert_throws([&]() { stack.addAll_efficient(1, data); }, 
                        "Index beyond size throws exception");
    }
}


int main() {
    std::cout << "=== Exercise 2.1: ArrayStack wastes memory after remove() operations ===" << std::endl;
    
    testExercise2_1();
    
    std::cout << "\n=== Exercise 2.1 Completed ===" << std::endl;
    return 0;
}
