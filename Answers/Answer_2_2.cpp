#include <cstdlib>
#include <vector>
#include <random>
#include <stdexcept>
#include <iostream>

template<typename T>
class RandomQueue {
private:
    std::vector<T> data;
    std::mt19937 rng;

public:
    RandomQueue() : rng(std::random_device{}()) {}

    void add(const T& element) {
        data.push_back(element);
    }

    T remove() {
        if (empty()) {
            throw std::runtime_error("Cannot remove from empty queue");
        }
        std::uniform_int_distribution<int> dist(0, data.size() - 1);
        int randomIndex = dist(rng);
        T result = data[randomIndex];

        if (randomIndex != data.size() - 1) {
            std::swap(data[randomIndex], data.back());
        }
        data.pop_back();
        return result;
    }

    bool empty() const {
        return data.empty();
    }

    size_t size() const {
        return data.size();
    }

    const T& peek() const {
        if (empty()) {
            throw std::runtime_error("Cannot peek at empty queue");
        }
        std::uniform_int_distribution<int> dist(0, data.size() - 1);
        int randomIndex = dist(rng);
        return data[randomIndex];
    }
};



// Example usage and test function
void testRandomQueue() {
    std::cout << "Testing RandomQueue...\n";
    
    RandomQueue<int> rq;
    
    // Test adding elements
    for (int i = 1; i <= 10; ++i) {
        rq.add(i);
        std::cout << "Added " << i << ", size: " << rq.size() << std::endl;
    }
    
    // Test removing elements randomly
    std::cout << "\nRemoving elements randomly:\n";
    while (!rq.empty()) {
        int removed = rq.remove();
        std::cout << "Removed: " << removed << ", remaining size: " << rq.size() << std::endl;
    }
    
    // Test edge cases
    try {
        rq.remove(); // Should throw exception
    } catch (const std::exception& e) {
        std::cout << "Expected exception: " << e.what() << std::endl;
    }
};

/**
 * COMPLEXITY ANALYSIS:
 * 
 * add(x): O(1) amortized
 * - std::vector::push_back() is O(1) amortized due to geometric growth
 * 
 * remove(): O(1) worst case
 * - Random index generation: O(1)
 * - Array access: O(1)
 * - Swap operation: O(1)
 * - pop_back(): O(1)
 * 
 * Space: O(n) where n is the number of elements
 */

/**
 * IMPLEMENTATION TIPS:
 * 
 * 1. The key insight is the "swap with last" technique:
 *    - Instead of shifting elements after removal (O(n))
 *    - Swap the random element with the last element
 *    - Remove the last element
 *    - This maintains all elements but changes their order (which is fine for a random queue)
 * 
 * 2. std::vector is perfect for this:
 *    - Provides O(1) random access
 *    - Handles dynamic resizing automatically
 *    - push_back() and pop_back() are O(1)
 * 
 * 3. For random number generation:
 *    - std::mt19937 is a good general-purpose generator
 *    - You can either keep a distribution object or create it as needed
 *    - For small ranges, modulo operation is acceptable
 * 
 * 4. Consider edge cases:
 *    - Empty queue operations
 *    - Single element queue
 *    - Large queues
 */

int main() {
    testRandomQueue();
    return 0;
}
