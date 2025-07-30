# Array-Based Data Structures Exercise Guide

This project contains implementations and comprehensive tests for Chapter 2.7 exercises on array-based data structures. It includes 6 different exercises covering optimization, memory management, bidirectional growth, space efficiency, error handling, and resizing strategies.

## 🚀 Quick Start

### Prerequisites
- C++ compiler (g++, clang++, or MSVC)
- C++11 or later standard

### Compilation
```bash
g++ -std=c++11 -o array_exercises paste.txt
```

### Run Tests
```bash
./array_exercises
```

## 📁 Project Structure

```
arrayExtem.cpp
├── Exercise 2.1 - ArrayStack (Bulk Insertion Optimization)
├── Exercise 2.2 - MemoryEfficientArrayStack 
├── Exercise 2.3 - BidirectionalArrayStack
├── Exercise 2.4 - RootishArrayStack
├── Exercise 2.5 - RobustArrayStack
├── Exercise 2.6 - ConfigurableArrayStack
└── Comprehensive Test Suite
```

## 🔧 Current Status

### 🚧 Partially Implemented (TODO sections need completion)
- **Exercise 2.1**: ArrayStack with bulk insertion optimization
- **Exercise 2.2**: MemoryEfficientArrayStack
- **Exercise 2.3**: BidirectionalArrayStack  
- **Exercise 2.4**: RootishArrayStack
- **Exercise 2.5**: RobustArrayStack
- **Exercise 2.6**: ConfigurableArrayStack

## 🛠️ How to Complete the Exercises

### Step 1: Implement Each Exercise

#### Exercise 2.2 - Memory-Efficient Operations
**Goal**: Implement smart resizing and proper memory cleanup

**TODO sections to complete**:
```cpp
void resize() {
    // Implement shrinking when array is 1/4 full
    // Double capacity when growing
}

T remove(int i) {
    // Implement with proper bounds checking
    // Shift elements and clear last position
    // Trigger resize if memory utilization is low
}

void add(int i, T x) {
    // Implement with resize when needed
}
```

**Test**: Run `testExercise2_2()` to verify memory efficiency

#### Exercise 2.3 - Bidirectional Array Stack
**Goal**: Implement deque-like operations on a single array

**TODO sections to complete**:
```cpp
void resize() {
    // Copy elements to center of new array
    // Update front and back pointers
}

void pushFront(T x) {
    // Add element at front, resize if needed
}

void pushBack(T x) {
    // Add element at back, resize if needed  
}

T popFront() / T popBack() {
    // Remove and return elements from ends
}
```

**Test**: Run `testExercise2_3()` to verify bidirectional operations

#### Exercise 2.4 - RootishArrayStack
**Goal**: Achieve n + O(√n) space overhead using variable-sized blocks

**TODO sections to complete**:
```cpp
int i2b(int i) const {
    // Convert index to block number: ⌈√(2i+2)⌉ - 1
}

void grow() {
    // Add new block of size (blocks.size() + 1)
}

int get(int i) / void set(int i, int x) {
    // Find correct block and access element
}

void add(int i, int x) / int remove(int i) {
    // Insert/remove with block management
}
```

**Test**: Run `testExercise2_4()` to verify space efficiency

#### Exercise 2.5 - Robust Error Handling
**Goal**: Handle all edge cases gracefully

**TODO sections to complete**:
```cpp
void add(int i, T x) {
    // Check for null array, invalid indices
    // Initialize array if needed
}

T remove(int i) / T get(int i) const {
    // Comprehensive bounds checking
    // Handle empty/null arrays
}
```

**Test**: Run `testExercise2_5()` to verify error handling

#### Exercise 2.6 - Configurable Resizing
**Goal**: Compare different array growth strategies

**TODO sections to complete**:
```cpp
void resize() {
    // Implement all resize policies:
    // - DOUBLE: capacity *= 2
    // - GOLDEN_RATIO: capacity *= 1.618
    // - ADDITIVE: capacity += growth_factor
    // - CUSTOM: capacity *= growth_factor
}

PerformanceMetrics getMetrics() const {
    // Track resize count, memory usage, utilization
}
```

**Test**: Run `testExercise2_6()` to compare strategies

# Exercise Extraction Guide - Array Data Structures

This guide shows you how to extract individual exercises from the comprehensive array data structures test suite and run them separately.

## Quick Start

1. **Choose an exercise** (2.1 through 2.6)
2. **Copy the required components** from the main file
3. **Create a new C++ file** with the extracted code
4. **Compile and run** your specific exercise

## File Structure Overview

The main file contains:
- **Exercise Classes** - Core data structure implementations
- **Test Functions** - Comprehensive test suites for each exercise
- **TestFramework** - Utility class for running tests
- **Helper Functions** - Supporting code and utilities

## Step-by-Step Extraction Process

### Step 1: Create Base Template

Every extracted exercise needs these common components:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cmath>
#include <functional>
#include <cassert>
#include <random>
#include <iomanip>

// Always include the TestFramework class
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
```

### Step 2: Extract Specific Exercise Components

#### Exercise 2.1 - Bulk Insertion Optimization

**File: `exercise_2_1.cpp`**

Copy these sections:
1. `ArrayStack` class template (lines 20-120)
2. `createTestData` helper function
3. `testExercise2_1` function
4. Simple main function

**Implementation Tasks:**
- Complete the `resize()` method
- Implement `addAll_inefficient()` using repeated `add()` calls
- Implement `addAll_efficient()` with single array operations

**Compile and Run:**
```bash
g++ -std=c++17 -O2 exercise_2_1.cpp -o exercise_2_1
./exercise_2_1
```

#### Exercise 2.2 - Memory-Efficient Operations

**File: `exercise_2_2.cpp`**

Copy these sections:
1. `MemoryEfficientArrayStack` class template
2. `testExercise2_2` function
3. TestFramework and main function

**Implementation Tasks:**
- Implement smart `resize()` that shrinks when array is 1/4 full
- Implement `remove()` with proper memory cleanup
- Implement `add()` with resizing logic

**Key Focus:** Memory utilization tracking and automatic shrinking

#### Exercise 2.3 - Bidirectional Array Stack

**File: `exercise_2_3.cpp`**

Copy these sections:
1. `BidirectionalArrayStack` class template
2. `testExercise2_3` function
3. TestFramework and main function

**Implementation Tasks:**
- Implement `pushFront()` and `pushBack()`
- Implement `popFront()` and `popBack()`
- Implement `resize()` that centers elements in new array

**Key Focus:** Efficient operations at both ends of the array

#### Exercise 2.4 - RootishArrayStack Space Efficiency

**File: `exercise_2_4.cpp`**

Copy these sections:
1. `RootishArrayStack` class
2. `testExercise2_4` function
3. TestFramework and main function

**Implementation Tasks:**
- Implement `i2b()` for index-to-block conversion
- Implement `grow()` and `shrink()` for block management
- Implement all CRUD operations with block-based storage

**Key Focus:** Achieving O(√n) space overhead

#### Exercise 2.5 - Robust Error Handling

**File: `exercise_2_5.cpp`**

Copy these sections:
1. `RobustArrayStack` class template
2. `testExercise2_5` function
3. TestFramework and main function

**Implementation Tasks:**
- Add comprehensive bounds checking
- Handle null/uninitialized arrays gracefully
- Maintain state consistency after errors

**Key Focus:** Bulletproof error handling and edge cases

#### Exercise 2.6 - Resizing Strategy Comparison

**File: `exercise_2_6.cpp`**

Copy these sections:
1. `ResizePolicy` enum
2. `ConfigurableArrayStack` class template
3. `testExercise2_6` function
4. TestFramework and main function

**Implementation Tasks:**
- Implement different resizing strategies (double, golden ratio, additive)
- Add performance metrics collection
- Compare strategies across different workloads

**Key Focus:** Performance analysis and optimization trade-offs

## Example: Complete Exercise 2.1 Extraction

Here's what a complete extracted file looks like:

**exercise_2_1_complete.cpp:**
```cpp
#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>

// [Include TestFramework class here]

// [Include complete ArrayStack class here]

// [Include createTestData function here]

// [Include testExercise2_1 function here]

int main() {
    std::cout << "=== Exercise 2.1: Bulk Insertion Optimization ===" << std::endl;
    testExercise2_1();
    return 0;
}
```

## Compilation Instructions

### Basic Compilation
```bash
g++ -std=c++17 -Wall -O2 exercise_X_Y.cpp -o exercise_X_Y
```

### Debug Version
```bash
g++ -std=c++17 -Wall -g -DDEBUG exercise_X_Y.cpp -o exercise_X_Y_debug
```

### With Performance Profiling
```bash
g++ -std=c++17 -Wall -O2 -pg exercise_X_Y.cpp -o exercise_X_Y_profile
```

## Tips for Implementation

### 1. Start with TODO Comments
Each exercise has `// TODO:` comments indicating what needs to be implemented. Use these as your implementation checklist.

### 2. Run Tests Incrementally
Implement one method at a time and run the tests to see which ones pass. This helps isolate issues.

### 3. Use the Test Output
The test framework provides detailed output about what's expected vs. actual. Use this to debug your implementations.

### 4. Performance Testing
For exercises with performance components (2.1, 2.6), run multiple times and average the results for more reliable measurements.

### 5. Memory Testing
For memory-related exercises (2.2, 2.4), consider using tools like Valgrind:
```bash
valgrind --leak-check=full ./exercise_2_2
```

## Common Issues and Solutions

### Compilation Errors
- **Missing includes:** Make sure you have all necessary headers
- **Template errors:** Check that template syntax is correct
- **Linking errors:** Ensure all referenced functions are defined

### Runtime Errors
- **Segmentation faults:** Usually indicate array bounds violations
- **Memory leaks:** Check that every `new` has a corresponding `delete`
- **Infinite loops:** Often in resize or traversal logic

### Test Failures
- **Off-by-one errors:** Common in index calculations
- **Edge cases:** Empty arrays, single elements, boundary conditions
- **Performance issues:** Algorithm complexity problems

## Exercise Dependencies

- **2.1:** Standalone (basic ArrayStack)
- **2.2:** Builds on 2.1 concepts
- **2.3:** Standalone (different array usage pattern)
- **2.4:** Standalone (completely different approach)
- **2.5:** Can build on any previous exercise
- **2.6:** Builds on 2.1 concepts with additional metrics

## Next Steps

1. **Choose your exercise** based on learning goals
2. **Extract the code** following this guide
3. **Implement the TODO sections** step by step
4. **Run the tests** and iterate until they pass
5. **Experiment** with different approaches and optimizations

Each exercise teaches different aspects of array-based data structures, from basic operations to advanced optimization techniques. Take your time with each one to fully understand the concepts before moving on.

## Learning Objectives Summary

| Exercise | Focus Area | Key Skills |
|----------|------------|------------|
| 2.1 | Bulk Operations | Algorithm optimization, performance analysis |
| 2.2 | Memory Management | Resource cleanup, memory efficiency |
| 2.3 | Bidirectional Growth | Advanced indexing, deque operations |
| 2.4 | Space Efficiency | Mathematical optimization, block structures |
| 2.5 | Error Handling | Robust programming, edge case management |
| 2.6 | Performance Tuning | Strategy comparison, benchmarking |



## 🧪 Understanding the Tests

### Test Framework Features
- **Assertion macros**: `assert_equal()`, `assert_true()`, `assert_throws()`
- **Performance timing**: Microsecond precision benchmarks
- **Edge case testing**: Boundary conditions, error scenarios
- **Memory analysis**: Utilization tracking, capacity monitoring

### Test Categories

#### Functionality Tests
- Basic operations (add, remove, get)
- Edge cases (empty arrays, boundary indices)
- Data integrity verification

#### Performance Tests
- Time complexity analysis
- Memory usage patterns
- Scalability with different data sizes

#### Stress Tests
- Random operation sequences
- Large dataset handling
- Mixed workload scenarios

### Reading Test Output
```
✓ Test Name PASSED
✗ Test Name FAILED: expected X, got Y

Performance Comparison:
Size 1000: Inefficient=1250μs, Efficient=45μs, Speedup=27.78x

=== Test Summary ===
Passed: 45
Failed: 3
Total:  48
```

## 🎯 Learning Objectives

### Exercise 2.1 - Bulk Operations
- **Complexity Analysis**: O(k²) vs O(k) for bulk insertion
- **Performance Impact**: Real-world timing differences
- **Algorithm Design**: Single shift vs multiple shifts

### Exercise 2.2 - Memory Management
- **Space Utilization**: When to shrink arrays
- **Memory Leaks**: Clearing unused positions
- **Dynamic Sizing**: Growth and shrinkage policies

### Exercise 2.3 - Bidirectional Growth
- **Deque Operations**: Efficient front/back access
- **Array Management**: Centering elements during resize
- **Pointer Arithmetic**: Managing front/back indices

### Exercise 2.4 - Space Efficiency
- **Asymptotic Analysis**: Achieving n + O(√n) overhead
- **Block Structures**: Variable-sized memory blocks
- **Index Mapping**: Converting linear to hierarchical indices

### Exercise 2.5 - Error Handling
- **Defensive Programming**: Validating all inputs
- **State Consistency**: Maintaining invariants after errors
- **Resource Safety**: Proper cleanup on exceptions
:
### Exercise 2.6 - Algorithm Comparison
- **Trade-off Analysis**: Memory vs resize frequency
- **Empirical Testing**: Measuring real performance
- **Strategy Selection**: Choosing optimal policies

## 🚨 Common Pitfalls

1. **Memory Leaks**: Not clearing unused array positions
2. **Index Errors**: Off-by-one in boundary calculations
3. **Resize Logic**: Incorrect capacity calculations
4. **Exception Safety**: Leaving objects in invalid states
5. **Performance**: Unnecessary operations in tight loops

## 📊 Expected Performance

### Time Complexity Goals
| Operation | ArrayStack | BidirectionalStack | RootishArrayStack |
|-----------|------------|-------------------|-------------------|
| get(i)    | O(1)       | O(1)              | O(1)              |
| set(i,x)  | O(1)       | O(1)              | O(1)              |
| add(i,x)  | O(n-i)     | O(min(i,n-i))     | O(n-i)            |
| remove(i) | O(n-i)     | O(min(i,n-i))     | O(n-i)            |

### Space Complexity Goals
| Data Structure | Space Overhead |
|----------------|----------------|
| ArrayStack     | O(n)          |
| RootishArrayStack | O(√n)      |

## 🔍 Debugging Tips

1. **Print Array State**: Use the `print()` methods to visualize data
2. **Step Through Tests**: Run individual test functions
3. **Check Invariants**: Verify size, capacity relationships
4. **Trace Operations**: Add debug output in critical sections
5. **Memory Tools**: Use valgrind or similar for leak detection

## 📚 Additional Resources

- **Algorithm Analysis**: Big-O notation and amortized analysis
- **Memory Management**: Dynamic allocation best practices  
- **Exception Safety**: RAII and strong exception guarantee
- **Performance Testing**: Benchmarking methodologies
- **Data Structure Design**: Trade-offs and optimization strategies

## 🤝 Contributing

To extend this project:
1. Add new test cases in the respective test functions
2. Implement additional resize policies
3. Add visualization/profiling tools
4. Create performance comparison charts
5. Add support for different data types

---

**Happy coding! 🚀** Complete the TODO sections and watch your test results improve!
