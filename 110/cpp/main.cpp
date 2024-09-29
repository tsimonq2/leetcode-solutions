#include <iostream>
#include <stack>
#include <utility>

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        // None check
        if (root == nullptr) { return true; }

        // Stack stores nodes and a pair: <TreeNode*, depth>. We use -1 to indicate that a node's height needs to be computed.
        std::stack<std::pair<TreeNode*, int>> stack;
        std::stack<std::pair<TreeNode*, int>> height_stack;
        
        // Dictionary to store the height of each node
        std::unordered_map<TreeNode*, int> height_map;

        stack.push({root, -1});  // Push the root with -1 indicating it needs processing

        while (!stack.empty()) {
            std::pair<TreeNode*, int> node = stack.top();
            stack.pop();

            // If the node is nullptr, continue
            if (node.first == nullptr) {
                continue;
            }

            if (node.second == -1) {  // First visit to the node, push it back for later processing
                stack.push({node.first, 1});  // Push back with marker that it will need height calculation
                
                // First process the right subtree, then the left
                if (node.first->right != nullptr) {
                    stack.push({node.first->right, -1});
                }
                if (node.first->left != nullptr) {
                    stack.push({node.first->left, -1});
                }
            } else {  // Second visit to this node, compute the height and check for balance
                int left_height = height_map[node.first->left] ? height_map[node.first->left] : 0;
                int right_height = height_map[node.first->right] ? height_map[node.first->right] : 0;
                
                // Check if this node is balanced
                if (std::abs(left_height - right_height) > 1) {
                    return false;  // The tree is unbalanced
                }

                // Store the height of this node
                height_map[node.first] = std::max(left_height, right_height) + 1;
            }
        }

        return true;  // All nodes checked, tree is balanced
    }
};

int main() {
    Solution sol;

    // Test case X: Y
    RETURN_TYPE resultX = sol.FUNCTION_NAME(Y);
    std::cout << "Test X: " << resultX << std::endl;

    return 0;
}
