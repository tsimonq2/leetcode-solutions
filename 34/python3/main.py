#!/usr/bin/env python3

from bisect import bisect_left, bisect_right

class Solution:
    def searchRange(self, nums, target):
        # Find the lower bound and upper bound
        first = bisect_left(nums, target)
        last = bisect_right(nums, target) - 1

        # Check if the target is within the bounds
        if first < len(nums) and nums[first] == target:
            return [first, last]
        else:
            return [-1, -1]
