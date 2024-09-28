#include <iostream>
#include <stack>
#include <string>

class Solution {
public:
    bool isValid(const std::string& s) {
        std::stack<char> stack;
        for (char c : s) {
            // Push opening brackets onto the stack
            if (c == '(' || c == '{' || c == '[') {
                stack.push(c);
            } else {
                // Mismatch or unmatched closing bracket
                if (stack.empty() || 
                   (c == ')' && stack.top() != '(') || 
                   (c == ']' && stack.top() != '[') || 
                   (c == '}' && stack.top() != '{')) {
                    return false;
                }
                // Pop the matching opening bracket
                stack.pop();
            }
        }
        // Valid if no opening brackets remain
        return stack.empty();
    }
};

int main() {
    Solution sol;

    // Test case 1: "()" -> true
    bool result1 = sol.isValid("()");
    std::cout << "Test 1: " << result1 << std::endl;

    // Test case 2: "()[]{}" -> true
    bool result2 = sol.isValid("()[]{}");
    std::cout << "Test 2: " << result2 << std::endl;

    // Test case 3: "(]" -> true
    bool result3 = sol.isValid("(]");
    std::cout << "Test 3: " << result3 << std::endl;

    // Test case 4: "([])" -> true
    bool result4 = sol.isValid("([])");
    std::cout << "Test 4: " << result4 << std::endl;

    return 0;
}
