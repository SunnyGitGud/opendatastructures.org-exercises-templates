#include <vector>
#include <iostream>
#include <algorithm>

/**
 * Array Rotation Problem:
 * Implement rotate(a, r) that moves element a[i] to position (i+r) mod a.length
 * 
 * Examples:
 * - rotate([1,2,3,4,5], 2) → [4,5,1,2,3]
 * - rotate([1,2,3,4,5], -1) → [2,3,4,5,1]
 * 
 * Key Insights:
 * 1. Positive r rotates RIGHT (elements move to higher indices)
 * 2. Negative r rotates LEFT (elements move to lower indices)
 * 3. Multiple approaches: naive copy, reversal trick, or cyclic swaps
 */

template<typename T>
class ArrayRotator {
public:
    /**
     * Method 1: Simple approach using extra space
     * Time: O(n), Space: O(n)
     */
    static void rotate_simple(std::vector<T>& a, int r) {
        if (a.empty()) return;
        
        int n = a.size();
        // TODO: Handle negative rotations and rotations > n
        // HINT: Normalize r to be in range [0, n)
        
        // TODO: Create temporary array and copy elements to new positions
        // HINT: Element at position i goes to position (i + r) % n
    }
    
    /**
     * Method 2: Reversal approach - no extra space!
     * Time: O(n), Space: O(1)
     * 
     * Key insight: To rotate right by r positions:
     * 1. Reverse entire array
     * 2. Reverse first r elements
     * 3. Reverse remaining n-r elements
     */
    static void rotate_reversal(std::vector<T>& a, int r) {
        if (a.empty()) return;
        
        int n = a.size();
        // TODO: Normalize r
        
        // TODO: Apply the three reversals
        // HINT: Use std::reverse(a.begin() + start, a.begin() + end)
        // or implement your own reverse helper
    }
    
    /**
     * Method 3: Cyclic replacement approach
     * Time: O(n), Space: O(1)
     * 
     * Follow cycles: start at position 0, move element to its destination,
     * then move the displaced element to its destination, etc.
     */
    static void rotate_cyclic(std::vector<T>& a, int r) {
        if (a.empty()) return;
        
        int n = a.size();
        // TODO: Normalize r
        
        // TODO: Handle cycles
        // HINT: You might need gcd(n, r) cycles
        // HINT: Each cycle starts at a different position
    }
    
private:
    // Helper function to normalize rotation amount
    static int normalize_rotation(int r, int n) {
        // TODO: Convert any r to equivalent r in range [0, n)
        // HINT: Handle negative numbers properly
        return 0; // placeholder
    }
    
    // Helper function for Method 2
    static void reverse_range(std::vector<T>& a, int start, int end) {
        // TODO: Reverse elements from index start to end-1
    }
    
    // Helper function for Method 3 - calculate GCD
    static int gcd(int a, int b) {
        // TODO: Implement greatest common divisor
        return 0; // placeholder
    }
};

// Edge case test
void test_edge_cases() {
    std::cout << "\nTesting edge cases...\n";

    std::vector<int> empty;
    ArrayRotator<int>::rotate_simple(empty, 5);
    std::cout << "Empty array test passed\n";

    std::vector<int> single = {42};
    ArrayRotator<int>::rotate_simple(single, 3);
    std::cout << "Single element after rotation: " << single[0] << "\n";

    std::vector<int> test = {1, 2, 3, 4, 5};
    ArrayRotator<int>::rotate_simple(test, -1);
    std::cout << "After rotate(-1): ";
    for (int x : test) std::cout << x << " ";
    std::cout << "\n";

    test = {1, 2, 3, 4, 5};
    ArrayRotator<int>::rotate_simple(test, 7);
    std::cout << "After rotate(7): ";
    for (int x : test) std::cout << x << " ";
    std::cout << "\n";
}

// Main test function
void test_rotate() {
    std::cout << "Testing Array Rotation...\n";

    std::vector<int> original = {1, 2, 3, 4, 5};

    {
        auto a = original;
        std::cout << "Original: ";
        for (int x : a) std::cout << x << " ";
        std::cout << "\n";

        ArrayRotator<int>::rotate_simple(a, 2);
        std::cout << "After rotate_simple(a, 2): ";
        for (int x : a) std::cout << x << " ";
        std::cout << "\n";
    }

    {
        auto a = original;
        ArrayRotator<int>::rotate_reversal(a, 2);
        std::cout << "After rotate_reversal(a, 2): ";
        for (int x : a) std::cout << x << " ";
        std::cout << "\n";
    }

    {
        auto a = original;
        ArrayRotator<int>::rotate_cyclic(a, 2);
        std::cout << "After rotate_cyclic(a, 2): ";
        for (int x : a) std::cout << x << " ";
        std::cout << "\n";
    }

    test_edge_cases();
}

int main() {
    test_rotate();
    return 0;
}
