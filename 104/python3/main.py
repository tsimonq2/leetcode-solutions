#!/usr/bin/env python3

class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        # Stores a node and its depth
        stack = []
        stack.append([root, 1])

        # Stores the current max depth
        current_max_depth = 0

        while stack:
            # Get the top item from the stack
            node = stack.pop()

            # If the node is null, continue
            if not node[0]:
                continue

            # If this depth is greater than the max depth, bump the variable
            if (node[1] > current_max_depth):
                current_max_depth = node[1]

            # Add its left and right elements to the stack, incrementing the depth
            right = [node[0].right, node[1] + 1]
            left = [node[0].left, node[1] + 1]
            stack.append(right)
            stack.append(left)

        # Return the max depth
        return current_max_depth
