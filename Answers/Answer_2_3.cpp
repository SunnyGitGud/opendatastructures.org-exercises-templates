#include <algorithm>
#include <cmath>
#include <vector>
#include <stdexcept>



template<typename T>
class Treque {
private:
  std::vector<std::vector<T>> blocks;
  int block_size;
  int total_size;
  
  void rebuild_blocks() {
    int n = total_size;
    int optimal_block_size = std::max(16, static_cast<int>(std::sqrt(n)));
    std::vector<T> flat;
    for (auto& blk : blocks){
      flat.insert(flat.end(), blk.begin(), blk.end());
    }
    blocks.clear();
    block_size = optimal_block_size;
    for (int i = 0; i < n; i+= block_size) {
      blocks.emplace_back(flat.begin() + i, flat.begin() + std::min(n, i + block_size));
    }
  }

public:
  Treque() : block_size(16), total_size(0) {};
  
 
  T get(int i) const {
    if (i < 0 || i >= total_size) throw std::out_of_range("index out of range");
    int idx = i;
    for (const auto& blk : blocks) {
      if (idx < blk.size()) return blk[idx];
      idx -= blk.size();
    }
    throw std::logic_error("failed to locate index");
  }
  
  void set(int i, const T& x) {
    if (i < 0 || i >= total_size) throw std::out_of_range("index out of range");
    for (auto& blk : blocks) {
      if(i < blk.size()) {
        blk[i] = x;
        return;
      }
      i -= blk.size();
    } 
    throw std::logic_error("Failed to locate index for set");
  }
  
  void add(int i, const T& x) {
    if (i < 0 || i > total_size) throw std::out_of_range("index out of range");
    for (auto& blk : blocks) {
      if(i < blk.size()) {
       blk.insert(blk.begin() + i, x);      
        ++total_size;
        if(blk.size() > 2 * block_size) rebuild_blocks();
        return;
      }
      i -= blk.size();
    }
     blocks.emplace_back(1, x);
    ++total_size;
  }
  
  
  T remove(int i) {
    if (i < 0 || i >= total_size) throw std::out_of_range("index out of range");
    for (auto& blk : blocks) {
      if(i< blk.size()) {
         T val = blk[i];
        blk.erase(blk.begin() + i);
        --total_size;
        return val;
      }
      i -= blk.size();
    }
    throw std::logic_error("Failed to locate index for removal");
  }
  
  int size() const {
   return total_size;
  }
  
  bool empty() const {
        return total_size == 0;
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
