#include <iostream>
#include <string>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        // Handle the edge case when needle is empty
        if (needle.empty()) {
            return 0;
        }

        // Store the last element of the haystack
        int haystack_size = haystack.size();
        // End index (index of the last element of the needle)
        int needle_size = needle.size();

        // Loop through haystack but only where the remaining substring length is >= needle_size
        for (int start_index = 0; start_index <= haystack_size - needle_size; start_index++) {
            // Compare the current substring of haystack to the needle
            if (haystack.substr(start_index, needle_size) == needle) {
                return start_index;
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;

    // Test case 1: "sadbutsad", "sad"
    int result1 = sol.strStr("sadbutsad", "sad");
    std::cout << "Test 1: " << result1 << std::endl;

    // Test case 3: "leetcode", "leeto"
    int result2 = sol.strStr("leetcode", "leeto");
    std::cout << "Test 2: " << result2 << std::endl;

    // Test case 3:
    int result3 = sol.strStr("a", "a");
    std::cout << "Test 3: " << result3 << std::endl;

    return 0;
}
