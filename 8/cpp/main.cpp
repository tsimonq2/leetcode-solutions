#include <iostream>

class Solution {
public:
    int myAtoi(string s) {
        int sign = 1;
        int offset = 0;
        int n = s.length();
        
        // Ignore leading whitespace characters
        while (offset < n && s[offset] == ' ') {
            offset++;
        }
        
        // Handle sign if present
        if (s[offset] == '-') {
            sign = -1;
            offset++;
        }
        else if (s[offset] == '+') {
            offset++;
        }

        // Initialize result
        long long result = 0;

        // Process numeric characters
        while (offset < n && s[offset] >= '0' && s[offset] <= '9') {
            result = result * 10 + (s[offset] - '0');

            // Check for overflow/underflow
            if (result * sign > INT_MAX) {
                return INT_MAX;
            }
            if (result * sign < INT_MIN) {
                return INT_MIN;
            }

            offset++;
        }

        // Return the final result with the correct sign
        return static_cast<int>(result * sign);
    }
};

int main() {
    Solution sol;

    // Test case X: Y
    RETURN_TYPE resultX = sol.FUNCTION_NAME(Y);
    std::cout << "Test X: " << resultX << std::endl;

    return 0;
}
