#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
        // If x is negative, return false
        if (x < 0) { return false; }

        // Store the original value for later comparison
        int original = x;
        // Initialize the reversed number
        long reversed_number = 0;

        while (x > 0) {
            reversed_number = (reversed_number * 10) + (x % 10);
            x = x / 10;
        }

        return original == reversed_number;
    }
};

int main() {
    Solution sol;

    // Test case 1: 121
    bool result1 = sol.isPalindrome(121);
    std::cout << "Test 1: " << result1 << std::endl;
    // Test case 2: -121
    bool result2 = sol.isPalindrome(-121);
    std::cout << "Test 2: " << result2 << std::endl;
    // Test case 3: 10
    bool result3 = sol.isPalindrome(10);
    std::cout << "Test 3: " << result3 << std::endl;
    // Test case 4: 10
    bool result4 = sol.isPalindrome(1234567899);
    std::cout << "Test 4: " << result4 << std::endl;

    return 0;
}
