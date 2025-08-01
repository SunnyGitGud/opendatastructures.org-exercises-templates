#include <utility>
#include <vector>
#include <iostream>
#include <algorithm>

 
template<typename T>
class ArrayRotator {
public:
   static void rotate_simple(std::vector<T>& a, int r) {
        if (a.empty()) return;
        
        int n = a.size();
        r = normalize_rotation(r, n);
        std::vector<T> temp(n);
        for (int i = 0; i < n; i++){
        temp[(i + r) % n ] = a[i];
    }
    a = temp;
   }
    
   static void rotate_reversal(std::vector<T>& a, int r) {
        if (a.empty()) return;
        
        int n = a.size();
        r = normalize_rotation(r, n);
        
        reverse_range(a, 0, n);
        reverse_range(a, 0 , r);
        reverse_range(a, r, n);
   }
    
   static void rotate_cyclic(std::vector<T>& a, int r) {
        if (a.empty()) return;
        
        int n = a.size();
        
        r = normalize_rotation(r, n);
        int g = gcd(n, r);
        for (int start = 0; start < g; ++start) {

        T temp = a[start];
        int current = start;
        
        while (true) {
        int next = (current + r) % n;
       if (next == start) break; 
        a[current] = a[next];
          current = next;
        }
      a[current] = temp;
    }
   }
    
private:
    static int normalize_rotation(int r, int n) {
        r = ((r % n) + n) %n;
        return r; // placeholder
    }
    
    static void reverse_range(std::vector<T>& a, int start, int end) {
      while (start < end) {
      std::swap(a[start], a[end]);
      start++;
      end--;
      
      }
    }
    
    static int gcd(int a, int b) {
      while (b != 0) {
      int temp = b;
      b = a % b;
      a = temp;
      
      }
        return a; // placeholder
    }
};

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
