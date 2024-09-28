#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        std::string common_prefix = "";

        // Iterate over the first element
        for (char c : strs.front()) {
            std::string original_common_prefix = common_prefix;
            common_prefix += c;
            for (std::string str : strs) {
                if (!str.starts_with(common_prefix)) {
                    return original_common_prefix;
                }
            }
        }

        // Return the common_prefix anyway
        return common_prefix;
    }
};

int main() {
    Solution sol;

    // Test case 1: ["flower","flow","flight"]
    std::vector<std::string> strs1 = {"flower", "flow", "flight"};
    std::string result1 = sol.longestCommonPrefix(strs1);
    std::cout << "Test 1: " << result1 << std::endl; // Output: "fl"

    // Test case 2: ["dog","racecar","car"]
    std::vector<std::string> strs2 = {"dog", "racecar", "car"};
    std::string result2 = sol.longestCommonPrefix(strs2);
    std::cout << "Test 2: " << result2 << std::endl; // Output: ""

    return 0;
}
