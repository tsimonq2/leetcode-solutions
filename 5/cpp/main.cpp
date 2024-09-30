#include <algorithm>
#include <iostream>
#include <string>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        // Edge case: If the string is empty, return an empty string
        if (s.empty()) return "";

        // Variables to track the start index and the maximum length of the palindrome
        int start = 0, max_len = 1;

        // Loop over each character in the string as a possible center
        for (int i = 0; i < s.size(); i++) {
            // Check for odd-length palindrome centered at s[i]
            // Set the initial left and right pointers at the same index (i)
            int left = i, right = i;
            // Expand while characters on both sides are equal and within bounds
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                // Update the maximum length and starting index if we find a longer palindrome
                if (right - left + 1 > max_len) {
                    start = left;
                    max_len = right - left + 1;
                }
                // Move pointers outward to check for a larger palindrome
                left--;
                right++;
            }

            // Check for even-length palindrome centered between s[i] and s[i+1]
            // Set left pointer at i and right pointer at i+1
            left = i, right = i + 1;
            // Expand while characters on both sides are equal and within bounds
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                // Update the maximum length and starting index if we find a longer palindrome
                if (right - left + 1 > max_len) {
                    start = left;
                    max_len = right - left + 1;
                }
                // Move pointers outward to check for a larger palindrome
                left--;
                right++;
            }
        }

        // Return the longest palindrome substring by extracting the relevant portion of the string
        return s.substr(start, max_len);
    }
};

int main() {
    Solution sol;

    // Test case 1: "babad"
    std::string result1 = sol.longestPalindrome("babad");
    std::cout << "Test 1: " << result1 << std::endl;
    // Test case 1: "cbbd"
    std::string result2 = sol.longestPalindrome("cbbd");
    std::cout << "Test 2: " << result2 << std::endl;

    return 0;
}
