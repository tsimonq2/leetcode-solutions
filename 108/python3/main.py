#!/usr/bin/env python3

class Solution:
    def sortedArrayToBST(self, nums: list[int]) -> TreeNode:
        # Deal with single-element, double-element, and empty vectors
        if not nums:
            return None

        # Get the middle element of the vector
        root_index = int(len(nums) / 2)
        root = TreeNode(val=nums[root_index])

        # Recursively construct the left subtree with the left half of the array
        left_subarray = nums[:root_index]
        root.left = self.sortedArrayToBST(left_subarray)

        # Recursively construct the right subtree with the right half of the array
        right_subarray = nums[root_index + 1:]
        root.right = self.sortedArrayToBST(right_subarray)

        return root
