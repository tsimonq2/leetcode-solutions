#include <iostream>
#include <stack>
#include <utility>

class Solution {
public:
    int minDepth(TreeNode* root) {
        // None check
        if (root == nullptr) { return 0; }

        // Create a stack to use for nodes with depths
        std::stack<std::pair<TreeNode*, int>> stack;
        stack.push({root, 1});
        int min_depth = INT_MAX;

        while (!stack.empty()) {
            std::pair<TreeNode*, int> node = stack.top();
            stack.pop();

            // We are at a final depth if there are no additional right or left elements
            if (node.first->right == nullptr && node.first->left == nullptr) {
                if (node.second < min_depth) {
                    min_depth = node.second;
                }
            }

            // If right or left elements exist, add them to the stack
            if (node.first->right != nullptr) {
                stack.push({node.first->right, node.second + 1});
            }
            if (node.first->left != nullptr) {
                stack.push({node.first->left, node.second + 1});
            }
        }

        return min_depth;
    }
};

int main() {
    Solution sol;

    // Test case X: Y
    RETURN_TYPE resultX = sol.FUNCTION_NAME(Y);
    std::cout << "Test X: " << resultX << std::endl;

    return 0;
}
