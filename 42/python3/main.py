#!/usr/bin/env python3

class Solution:
    def trap(self, height):
        flag_left, flag_right = 0, len(height) - 1
        max_left, max_right = 0, 0
        total = 0

        # Two-pointer approach to calculate trapped water
        while flag_left <= flag_right:
            if height[flag_left] <= height[flag_right]:
                max_left = max(max_left, height[flag_left])
                total += max_left - height[flag_left]
                flag_left += 1
            else:
                max_right = max(max_right, height[flag_right])
                total += max_right - height[flag_right]
                flag_right -= 1

        return total
