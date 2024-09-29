#!/usr/bin/env python3

class Solution:
    def hasPathSum(self, root: TreeNode, targetSum: int) -> bool:
        if root is None:
            return False

        # Initialize a stack, which stores a node and its sum so far
        stack = [(root, root.val)]

        while stack:
            node, current_sum = stack.pop()

            # If this is a leaf, check the sum against targetSum
            if node.left is None and node.right is None and current_sum == targetSum:
                return True

            # Add the right child to the stack if it exists
            if node.right is not None:
                stack.append((node.right, current_sum + node.right.val))

            # Add the left child to the stack if it exists
            if node.left is not None:
                stack.append((node.left, current_sum + node.left.val))

        # No path matched the target sum
        return False
