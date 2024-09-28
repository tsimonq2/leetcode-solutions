#include <iostream>
#include <cmath>

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) { return x; }

        // Start with an initial guess for i
        unsigned long long i = x;
        
        // Loop to compute the integer square root
        while (true) {
            // Compute the new approximation for y
            unsigned long long y = (i + x / i) / 2;

            // If the new approximation is greater than or equal to the current x, return x
            if (y >= i) {
                return static_cast<int>(i);
            }

            // Update x to the new value y
            i = y;
        }
    }
};

int main() {
    Solution sol;

    // Test case 1: 4
    int result1 = sol.mySqrt(4);
    std::cout << "Test 1: " << result1 << std::endl;

    // Test case 2: 8
    int result2 = sol.mySqrt(8);
    std::cout << "Test 2: " << result2 << std::endl;

    // Test case 3: 145
    int result3 = sol.mySqrt(145);
    std::cout << "Test 3: " << result3 << std::endl;

    return 0;
}
