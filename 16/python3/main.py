#!/usr/bin/env python3

class Solution:
    def threeSumClosest(self, nums, target):
        closest = float('inf')  # Initialize closest sum to a very large number
        min_diff = float('inf')  # Track the minimum difference between sum and target

        # Sort the array to apply two-pointer approach
        nums.sort()

        for i in range(len(nums)):
            # Skip duplicates for the first number
            if i > 0 and nums[i] == nums[i - 1]:
                continue

            left, right = i + 1, len(nums) - 1

            while left < right:
                sum_ = nums[i] + nums[left] + nums[right]
                diff = abs(target - sum_)

                # Update the closest sum if current sum is closer to the target
                if diff < min_diff:
                    closest = sum_
                    min_diff = diff

                # Move the pointers based on how the sum compares to the target
                if sum_ < target:
                    left += 1
                elif sum_ > target:
                    right -= 1
                else:
                    # If sum matches the target exactly, return it
                    return sum_

        return closest

