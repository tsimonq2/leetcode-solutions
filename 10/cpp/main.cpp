#include <iostream>
#include <regex>
#include <string>

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        const std::regex r(p);
        return std::regex_match(s, r);
    }
};

int main() {
    Solution sol;

    // Test case 1: "aa", "a"
    bool result1 = sol.isMatch("aa", "a");
    std::cout << "Test 1: " << result1 << std::endl;

    return 0;
}
