#include <iostream>
#include <stack>
#include <utility>

class Solution {
public:
    int maxDepth(TreeNode* root) {
        // Stores a node and its depth
        std::stack<std::pair<TreeNode*, int>> stack;
        stack.push({root, 1});

        // Stores the current max depth
        int current_max_depth = 0;

        while (!stack.empty()) {
            // Get the top item from the stack
            std::pair<TreeNode*, int> node = stack.top();
            stack.pop();

            // If the node is null, continue
            if (node.first == nullptr) { continue; }

            // If this depth is greater than the max depth, bump the variable
            if (node.second > current_max_depth) {
                current_max_depth = node.second;
            }

            // Add its left and right elements to the stack, incrementing the depth
            std::pair<TreeNode*, int> right = {node.first->right, node.second + 1};
            std::pair<TreeNode*, int> left = {node.first->left, node.second + 1};
            stack.push(right);
            stack.push(left);
        }

        // Return the max depth
        return current_max_depth;
    }
};

int main() {
    Solution sol;

    // Test case X: Y
    RETURN_TYPE resultX = sol.FUNCTION_NAME(Y);
    std::cout << "Test X: " << resultX << std::endl;

    return 0;
}
