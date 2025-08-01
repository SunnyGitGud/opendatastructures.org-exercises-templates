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
    RandomQueue() {
        // TODO: Initialize RNG
    }
    
    void add(const T& element) {
        // TODO: Add element to queue
    }
    
    T remove() {
        // TODO: Remove random element
        // Key insight: swap with last element, then remove last
        if (empty()) {
            throw std::runtime_error("Empty queue");
        }
        
        // Your implementation here
        return T{};
    }
    
    bool empty() const {
        // TODO: Check if empty
        return false;
    }
    
    size_t size() const {
        // TODO: Return size
        return 0;
    }
};

// Test function
void test() {
    RandomQueue<int> rq;
    
    // Add some elements
    for (int i = 1; i <= 5; ++i) {
        rq.add(i);
    }
    
    // Remove all elements
    while (!rq.empty()) {
        std::cout << "Removed: " << rq.remove() << std::endl;
    }
}
