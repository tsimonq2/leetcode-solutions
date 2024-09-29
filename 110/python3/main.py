#!/usr/bin/env python3

class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        if root is None:
            return True
        
        # Stack for iterative traversal, storing (node, state)
        stack = [(root, -1)]  # -1 means the node hasn't been processed yet
        height_map = {}  # Dictionary to store the height of each node
        
        while stack:
            node, state = stack.pop()
            
            if node is None:
                continue

            if state == -1:  # First visit to the node
                stack.append((node, 1))  # Add the node back with a processed state (1)

                # First process the right subtree, then the left subtree
                if node.right:
                    stack.append((node.right, -1))
                if node.left:
                    stack.append((node.left, -1))
            else:  # Second visit, compute height and check balance
                left_height = height_map.get(node.left, 0)
                right_height = height_map.get(node.right, 0)

                # Check if the current node is unbalanced
                if abs(left_height - right_height) > 1:
                    return False  # The tree is unbalanced

                # Calculate and store the height of the current node
                height_map[node] = max(left_height, right_height) + 1
        
        return True
