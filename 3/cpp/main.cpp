#include <iostream>
#include <string>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        // Handle the empty string case
        if (s.empty()) return 0;

        // Initialize variables
        int result = 0, left = 0;
        std::string current_substr = "";

        // Traverse the string
        for (int right = 0; right < s.size(); ++right) {
            // If the character is already in the current substring, move the left pointer
            size_t pos = current_substr.find(s[right]);
            if (pos != std::string::npos) {
                // Move the left pointer to right after the first occurrence of the duplicate
                left += pos + 1;
                // Remove all characters up to the duplicate
                current_substr = current_substr.substr(pos + 1);
            }

            // Add the current character to the substring
            current_substr += s[right];

            // Update the result with the maximum window size found so far
            result = std::max(result, (int)current_substr.size());
        }

        return result;
    }
};

int main() {
    Solution sol;

    // Test case 1: "abcabcbb"
    int result1 = sol.lengthOfLongestSubstring("abcabcbb");
    std::cout << "Test 1: " << result1 << std::endl;

    // Test case 1: "bbbbb"
    int result2 = sol.lengthOfLongestSubstring("bbbbb");
    std::cout << "Test 2: " << result2 << std::endl;

    // Test case 1: "pwwkew"
    int result3 = sol.lengthOfLongestSubstring("pwwkew");
    std::cout << "Test 3: " << result3 << std::endl;

    return 0;
}
