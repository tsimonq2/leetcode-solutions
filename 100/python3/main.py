#!/usr/bin/env python3

class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        p_stk, q_stk = [p], [q]

        while p_stk and q_stk:
            node_p = p_stk.pop()
            node_q = q_stk.pop()

            if not node_p and not node_q:
                continue

            if (not node_p or not node_q) or (node_p.val != node_q.val):
                return False

            p_stk.append(node_p.right)
            q_stk.append(node_q.right)
            p_stk.append(node_p.left)
            q_stk.append(node_q.left)

        return not p_stk and not q_stk
