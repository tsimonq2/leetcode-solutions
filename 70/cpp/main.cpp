#include <iostream>
#include <cmath>

class Solution {
public:
    int climbStairs(int n) {
        // Use Binet's Formula to find the correct term of the sequence
        double sqrt5 = std::sqrt(5);
        // Shift it to the right by two elements
        int i = n + 1;
        
        // Calculate the golden ratio (phi) and its conjugate (psi)
        double phi = (1 + sqrt5) / 2;
        double psi = (1 - sqrt5) / 2;

        // Compute phi^i (phi raised to the power of i)
        double phi_power_i = std::pow(phi, i);

        // Compute psi^i (psi raised to the power of i)
        double psi_power_i = std::pow(psi, i);

        // Compute the difference between phi^i and psi^i
        double result_double = (phi_power_i - psi_power_i) / sqrt5;

        // Round the result to the nearest integer using 0.5 for rounding
        // Adding 0.5 ensures proper rounding instead of truncation
        return static_cast<int>(result_double + 0.5);
    }
};

int main() {
    Solution sol;

    // Test case 1: 2
    int result1 = sol.climbStairs(2);
    std::cout << "Test 1: " << result1 << std::endl;

    // Test case 2: 3
    int result2 = sol.climbStairs(3);
    std::cout << "Test 2: " << result2 << std::endl;

    // Test case 3: 5
    int result3 = sol.climbStairs(5);
    std::cout << "Test 3: " << result3 << std::endl;

    return 0;
}
