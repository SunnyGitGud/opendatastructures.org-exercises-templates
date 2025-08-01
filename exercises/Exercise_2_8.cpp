#include <vector>
#include <cmath>
#include <stdexcept>
#include <iostream>

template<typename T>
class RootishArrayQueue {
private:
    std::vector<std::vector<T>*> blocks;
    int n;
    int j;  // Index of first block
    
    // HINT: j represents the starting block offset
    // This allows efficient operations from both ends
    
public:
    RootishArrayQueue() : n(0), j(0) {
        // TODO: Initialize empty queue
    }
    
    ~RootishArrayQueue() {
        // TODO: Clean up allocated blocks
        for (auto* block : blocks) {
            delete block;
        }
    }

private:
    int blockSize(int i) {
        // HINT: Block i should have size i+1 in traditional rootish array
        // But consider how your indexing works with offset j
        // TODO: Return size of block i
        return 0;
    }
    
    std::pair<int, int> getLocation(int i) {
        // TODO: Find block and position for logical index i
        // Key insight: This should work efficiently from either end
        // Return pair<block_index, position_in_block>
        
        // HINT: You might search from front or back depending on min{i, n-i}
        if (i < n/2) {
            // Search from front
            // TODO: Implement forward search
        } else {
            // Search from back  
            // TODO: Implement backward search
        }
        
        return {0, 0}; // Placeholder
    }
    
    void grow() {
        // TODO: Add blocks when queue grows
        // HINT: Add blocks to both ends to maintain balance
    }
    
    void shrink() {
        // TODO: Remove empty blocks when queue shrinks
        // HINT: Maintain O(√n) space bound
    }

public:
    T get(int i) {
        // TODO: Get element at logical index i
        // Should run in O(1 + min{i, n-i}) time
        if (i < 0 || i >= n) {
            throw std::out_of_range("Index out of bounds");
        }
        
        auto [block_idx, pos] = getLocation(i);
        return (*blocks[block_idx])[pos];
    }
    
    void set(int i, const T& x) {
        // TODO: Set element at logical index i
        // Should run in O(1 + min{i, n-i}) time
        if (i < 0 || i >= n) {
            throw std::out_of_range("Index out of bounds");
        }
        
        auto [block_idx, pos] = getLocation(i);
        (*blocks[block_idx])[pos] = x;
    }
    
    void add(const T& x) {
        // TODO: Add element to back of queue
        // HINT: This should be O(1) amortized
        
        // Your implementation here
        n++;
    }
    
    T remove() {
        // TODO: Remove element from back of queue  
        // HINT: This should be O(1) amortized
        if (empty()) {
            throw std::runtime_error("Empty queue");
        }
        
        // Your implementation here
        n--;
        return T{};
    }
    
    void addFirst(const T& x) {
        // TODO: Add element to front of queue
        // HINT: This is where the offset j becomes important
        // You might need to add blocks to the front
        
        // Your implementation here
        n++;
    }
    
    T removeFirst() {
        // TODO: Remove element from front of queue
        // HINT: Update j appropriately, may need to remove front blocks
        if (empty()) {
            throw std::runtime_error("Empty queue");
        }
        
        // Your implementation here  
        n--;
        return T{};
    }
    
    bool empty() const {
        return n == 0;
    }
    
    size_t size() const {
        return n;
    }
    
    void printStructure() const {
        // TODO: Debug helper to visualize block structure
        std::cout << "Blocks: " << blocks.size() << ", n: " << n << ", j: " << j << std::endl;
        for (size_t i = 0; i < blocks.size(); ++i) {
            std::cout << "Block " << i << " (size " << blocks[i]->size() << "): ";
            for (const auto& elem : *blocks[i]) {
                std::cout << elem << " ";
            }
            std::cout << std::endl;
        }
    }
};

// Test function
void test() {
    RootishArrayQueue<int> raq;
    
    // Test basic operations
    std::cout << "Adding elements to back..." << std::endl;
    for (int i = 1; i <= 10; ++i) {
        raq.add(i);
    }
    
    std::cout << "Adding elements to front..." << std::endl;
    for (int i = -1; i >= -5; --i) {
        raq.addFirst(i);
    }
    
    raq.printStructure();
    
    std::cout << "Testing get/set operations..." << std::endl;
    for (int i = 0; i < raq.size(); ++i) {
        std::cout << "Element at " << i << ": " << raq.get(i) << std::endl;
    }
    
    std::cout << "Removing from both ends..." << std::endl;
    while (!raq.empty()) {
        if (raq.size() % 2 == 0) {
            std::cout << "Removed from front: " << raq.removeFirst() << std::endl;
        } else {
            std::cout << "Removed from back: " << raq.remove() << std::endl;
        }
    }
}

int main() {
    test();
    return 0;
}

/*
KEY IMPLEMENTATION HINTS:

1. SPACE COMPLEXITY O(√n):
   - Total blocks ≈ √n
   - Each block wastes at most O(√n) space
   - Use grow()/shrink() to maintain this bound

2. TIME COMPLEXITY O(1 + min{i, n-i}):
   - In getLocation(), choose to search from front or back
   - Front search: sum of block sizes from first block
   - Back search: sum of block sizes from last block
   - Choose path that gives min{i, n-i} blocks to traverse

3. FRONT OPERATIONS:
   - Use offset j to track first block index
   - May need negative block indices conceptually
   - addFirst() might require adding blocks before index 0

4. BALANCING:
   - Keep roughly equal capacity at front and back
   - This ensures min{i, n-i} stays small for most indices

5. BLOCK MANAGEMENT:
   - Block i has size roughly i+1
   - But adjust based on your offset strategy
   - grow() when blocks are full, shrink() when mostly empty
*/
