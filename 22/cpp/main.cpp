#include <iostream>
#include <numeric>
#include <stack>
#include <string>
#include <vector>

class Solution {
public:
    // Stack and result vector as member variables
    std::stack<std::string> stack;
    std::vector<std::string> result;

    std::vector<std::string> generateParenthesis(int n) {
        backtrack(n, 0, 0);  // Call the backtrack function
        return result;
    }

private:
    void backtrack(int n, int open, int closed) {
        if (open == n && closed == n) {
            // Pop elements from the stack and concatenate
            std::string to_append = "";
            std::stack<std::string> temp_stack = stack;  // Temporary copy of the stack
            while (!temp_stack.empty()) {
                to_append = temp_stack.top() + to_append;
                temp_stack.pop();
            }
            result.emplace_back(to_append);
            return;
        }

        if (open < n) {
            stack.push("(");
            backtrack(n, open + 1, closed);
            stack.pop();  // Backtrack, remove the last added element
        }

        if (closed < open) {
            stack.push(")");
            backtrack(n, open, closed + 1);
            stack.pop();  // Backtrack, remove the last added element
        }
    }
};

int main() {
    Solution sol;

    // Test case X: Y
    RETURN_TYPE resultX = sol.FUNCTION_NAME(Y);
    std::cout << "Test X: " << resultX << std::endl;

    return 0;
}
