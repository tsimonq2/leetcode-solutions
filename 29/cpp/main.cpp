#include <cmath>
#include <iostream>
#include <limits>

#include <limits> // for INT_MAX and INT_MIN
#include <cmath>  // for abs()

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow case for INT_MIN / -1
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        // Handle special cases where divisor is 1 or -1
        if (divisor == 1) return dividend;
        if (divisor == -1) return -dividend;

        // Determine the sign of the result
        int sign = ((dividend > 0) == (divisor > 0)) ? 1 : -1;

        // Convert dividend and divisor to long long to avoid overflow during abs()
        long long abs_dividend = std::abs((long long)dividend);
        long long abs_divisor = std::abs((long long)divisor);

        long long result = 0;

        // Efficient division using bitwise shifting
        while (abs_dividend >= abs_divisor) {
            long long temp = abs_divisor;
            long long multiple = 1;

            // Find the largest double of the divisor that fits into the dividend
            while (abs_dividend >= (temp << 1) && (temp << 1) > 0) {
                temp <<= 1;
                multiple <<= 1;
            }

            // Subtract the largest multiple of divisor from the dividend
            abs_dividend -= temp;
            result += multiple;
        }

        // Apply the sign and ensure result fits in the 32-bit integer range
        result = sign * result;
        return result > INT_MAX ? INT_MAX : (result < INT_MIN ? INT_MIN : result);
    }
};

int main() {
    Solution sol;

    // Test case X: Y
    RETURN_TYPE resultX = sol.FUNCTION_NAME(Y);
    std::cout << "Test X: " << resultX << std::endl;

    return 0;
}
