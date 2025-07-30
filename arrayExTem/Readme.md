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
