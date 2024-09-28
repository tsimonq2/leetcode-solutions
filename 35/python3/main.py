#!/usr/bin/env python3

class Solution:
    def searchInsert(self, nums: list[int], target: int) -> int:
        left = 0
        right = len(nums) - 1

        while (left <= right):
            mid = left + (right - left) // 2

            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1

        return left


solution = Solution()
nums = [1,3,5,6]
print(solution.searchInsert(nums, 5))
print(solution.searchInsert(nums, 2))
print(solution.searchInsert(nums, 7))
