#include <stack>
#include <string>

class Solution {
public:
    int longestValidParentheses(std::string s) {
        // Stack to store indices of parentheses
        std::stack<int> stack;
        int max_length = 0;
        int last_invalid = -1;  // Tracks the index of the last invalid closing parenthesis

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                // Push the index of every '(' onto the stack
                stack.push(i);
            } else {
                // For each ')', pop if there's a matching '('
                if (!stack.empty()) {
                    stack.pop();  // Pop the last '('
                    if (stack.empty()) {
                        // If stack is empty, calculate the valid substring length
                        max_length = std::max(max_length, i - last_invalid);
                    } else {
                        // Otherwise, calculate from the top element of the stack
                        max_length = std::max(max_length, i - stack.top());
                    }
                } else {
                    // If stack is empty, update the last invalid index
                    last_invalid = i;
                }
            }
        }
        return max_length;
    }
};
