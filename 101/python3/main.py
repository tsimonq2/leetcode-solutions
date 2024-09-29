#!/usr/bin/env python3

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        # If there is only one node, it is symmetric
        # Additionally, if either side is null, it is not symmetrical
        if not root.right and not root.left:
            return True
        if not root.right or not root.left:
            return False

        right_stk, left_stk = [root.right], [root.left]

        while right_stk and left_stk:
            right_node = right_stk.pop()
            left_node = left_stk.pop()

            if not right_node and not left_node:
                continue

            if (not right_node or not left_node) or (right_node.val != left_node.val):
                return False

            right_stk.append(right_node.right)
            left_stk.append(left_node.left)
            right_stk.append(right_node.left)
            left_stk.append(left_node.right)

        return not right_stk and not left_stk
