#include <iostream>
#include <stack>

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        std::stack<TreeNode*> right_stk, left_stk;

        // If there is only one node, it is symmetric
        // Additionally, if either side is null, it is not symmetrical
        if (root->right == nullptr && root->left == nullptr) {
            return true;
        } else if (root->right == nullptr || root->left == nullptr) {
            return false;
        }

        right_stk.push(root->right);
        left_stk.push(root->left);

        while (!right_stk.empty() && !left_stk.empty()) {
            TreeNode* node_right = right_stk.top();
            TreeNode* node_left = left_stk.top();
            right_stk.pop();
            left_stk.pop();

            if (node_right == nullptr && node_left == nullptr) continue;
            if (node_right == nullptr || node_left == nullptr) return false;
            if (node_right->val != node_left->val) return false;

            // Push right and left children of both nodes onto the stacks
            right_stk.push(node_right->right);
            left_stk.push(node_left->left);
            right_stk.push(node_right->left);
            left_stk.push(node_left->right);
        }

        return right_stk.empty() && left_stk.empty();
    }
};
