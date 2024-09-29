#include <iostream>
#include <stack>
#include <utility>

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) { return false; }

        // Initialize a stack, which stores a node and its sum so far
        std::stack<std::pair<TreeNode*, int>> stack;
        stack.push({root, root->val});

        while(!stack.empty()) {
            std::pair<TreeNode*, int> node = stack.top();
            stack.pop();

            // If this is a leaf, check the sum against targetSum
            if (node.first->right == nullptr && node.first->left == nullptr) {
                if (node.second == targetSum) { return true; }
            }

            if (node.first->right != nullptr) {
                stack.push({node.first->right, node.first->right->val + node.second});
            }
            if (node.first->left != nullptr) {
                stack.push({node.first->left, node.first->left->val + node.second});
            }
        }

        // No matches found
        return false;
    }
};

int main() {
    Solution sol;

    // Test case X: Y
    RETURN_TYPE resultX = sol.FUNCTION_NAME(Y);
    std::cout << "Test X: " << resultX << std::endl;

    return 0;
}
