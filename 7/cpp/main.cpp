#include <iostream>
#include <limits>

class Solution {
public:
    int reverse(int x) {
        int new_value = 0;

        // 32-bit signed integer limits
        const int MIN_INT = std::numeric_limits<int>::min();
        const int MAX_INT = std::numeric_limits<int>::max();

        // Handle the special case where x is MIN_INT (-2147483648)
        if (x == MIN_INT) {
            return 0;
        }

        // If x is negative, convert it to positive then revert it back later
        bool negative = (x < 0);
        if (negative) {
            x = -x;  // Safe to negate since we already checked for MIN_INT
        }

        while (x > 0) {
            // Check for overflow before multiplying by 10
            if (new_value > (MAX_INT / 10) || (new_value == MAX_INT / 10 && x % 10 > MAX_INT % 10)) {
                return 0;  // Return 0 if the reverse exceeds 32-bit bounds
            }
            new_value = (new_value * 10) + (x % 10);
            x /= 10;
        }

        if (negative) {
            new_value = -new_value;
        }

        return new_value;
    }
};

int main() {
    Solution sol;

    // Test case 1: 123
    int result1 = sol.reverse(123);
    std::cout << "Test 1: " << result1 << std::endl;

    // Test case 1: -123
    int result2 = sol.reverse(-123);
    std::cout << "Test 2: " << result2 << std::endl;

    return 0;
}
