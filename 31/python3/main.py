#!/usr/bin/env python3

from typing import List

class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        # Step 1: Find the first decreasing element from the end
        i = len(nums) - 2
        while i >= 0 and nums[i] >= nums[i + 1]:
            i -= 1

        # Step 2: If we find such an element
        if i >= 0:
            # Find the next larger element to swap with
            j = len(nums) - 1
            while nums[j] <= nums[i]:
                j -= 1
            nums[i], nums[j] = nums[j], nums[i]  # Swap

        # Step 3: Reverse the elements after i
        nums[i + 1:] = reversed(nums[i + 1:])
