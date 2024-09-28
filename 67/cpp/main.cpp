#include <iostream>
#include <algorithm>
#include <string>

class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        std::string result = "";
        int i = a.size() - 1, j = b.size() - 1;
        int carry = 0;

        // Traverse both strings from the end to the beginning
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            // Add bits from a and b, if available
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';

            // Compute the current bit and the carry
            result = std::to_string(sum % 2) + result;
            carry = sum / 2;
        }

        return result;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    std::string a1 = "11", b1 = "1";
    std::cout << "Result: " << sol.addBinary(a1, b1) << "\n";  // Expected: "100"
    
    // Test Case 2
    std::string a2 = "1010", b2 = "1011";
    std::cout << "Result: " << sol.addBinary(a2, b2) << "\n";  // Expected: "10101"
    
    // Additional Test Cases
    std::string a3 = "110", b3 = "11";
    std::cout << "Result: " << sol.addBinary(a3, b3) << "\n";  // Expected: "1001"

    std::string a4 = "1111", b4 = "1111";
    std::cout << "Result: " << sol.addBinary(a4, b4) << "\n";  // Expected: "11110"

    std::string a5 = "0", b5 = "101";
    std::cout << "Result: " << sol.addBinary(a5, b5) << "\n";  // Expected: "101"

    return 0;
}
