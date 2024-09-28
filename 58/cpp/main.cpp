#include <iostream>
#include <regex>
#include <string>

class Solution {
public:
    int lengthOfLastWord(std::string s) {
        // Reverse the string
        std::string reversed(s.rbegin(), s.rend());
        // Variable to store whether a space is found
        std::string::size_type n;

        // Remove leading whitespace
        reversed = std::regex_replace(reversed, std::regex("^ +"), "");

        n = reversed.find(" ");
        // Did not find a space, just return the size of the whole thing
        if (std::string::npos == n) {
            return reversed.size();
        } else {
            return n;
        }
    }
};

int main() {
    Solution sol;

    // Test case 1: "Hello World"
    int result1 = sol.lengthOfLastWord("Hello World");
    std::cout << "Test 1: " << result1 << std::endl;

    // Test case 2: "   fly me   to   the moon  "
    int result2 = sol.lengthOfLastWord("   fly me   to   the moon  ");
    std::cout << "Test 2: " << result2 << std::endl;

    // Test case 3: "luffy is still joyboy"
    int result3 = sol.lengthOfLastWord("luffy is still joyboy");
    std::cout << "Test 3: " << result3 << std::endl;

    return 0;
}
