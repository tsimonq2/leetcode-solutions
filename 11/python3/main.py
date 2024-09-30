#!/usr/bin/env python3

class Solution:
    def maxArea(self, height: list[int]) -> int:
        left = 0
        right = len(height) - 1
        max_area = 0

        while (left < right):
            # Height * width
            current_area = min(height[left], height[right]) * (right - left)
            if (current_area > max_area):
                max_area = current_area
            if (height[left] > height[right]):
                right -= 1
            elif (height[left] <= height[right]):
                left += 1

        return max_area
