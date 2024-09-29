#!/usr/bin/env python3

class Solution:
    def minDepth(self, root: TreeNode) -> int:
        # None check
        if root is None:
            return 0

        # Create a stack to use for nodes with depths
        stack = [(root, 1)]  # Stack stores (node, current_depth)
        min_depth = float('inf')

        while stack:
            node, current_depth = stack.pop()

            # If we reach a leaf node, update the minimum depth
            if node.left is None and node.right is None:
                min_depth = min(min_depth, current_depth)

            # Push right and left children onto the stack if they exist
            if node.right:
                stack.append((node.right, current_depth + 1))
            if node.left:
                stack.append((node.left, current_depth + 1))

        return min_depth
