#include <iostream>
#include <stack>

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        std::stack<TreeNode*> p_stk, q_stk;

        p_stk.push(p);
        q_stk.push(q);

        while (!p_stk.empty() && !q_stk.empty()) {
            TreeNode* node_p = p_stk.top();
            TreeNode* node_q = q_stk.top();
            p_stk.pop();
            q_stk.pop();

            if (node_p == nullptr && node_q == nullptr) continue;
            if (node_p == nullptr || node_q == nullptr) return false;
            if (node_p->val != node_q->val) return false;

            // Push right and left children of both nodes onto the stacks
            p_stk.push(node_p->right);
            q_stk.push(node_q->right);
            p_stk.push(node_p->left);
            q_stk.push(node_q->left);
        }

        return p_stk.empty() && q_stk.empty();
    }
};
