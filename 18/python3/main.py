#!/usr/bin/env python3

class Solution:
    def fourSum(self, nums, target):
        result = []
        
        # Sort the array to allow the two-pointer approach
        nums.sort()

        for i in range(len(nums)):
            # Skip duplicate elements for the first pointer
            if i > 0 and nums[i] == nums[i - 1]:
                continue

            for j in range(i + 1, len(nums)):
                # Skip duplicate elements for the second pointer
                if j > i + 1 and nums[j] == nums[j - 1]:
                    continue

                # Two-pointer approach for the remaining two numbers
                left, right = j + 1, len(nums) - 1

                while left < right:
                    sum_ = nums[i] + nums[j] + nums[left] + nums[right]

                    if sum_ == target:
                        # Add the quadruplet to the result
                        result.append([nums[i], nums[j], nums[left], nums[right]])

                        # Skip duplicates for left and right pointers
                        while left < right and nums[left] == nums[left + 1]:
                            left += 1
                        while left < right and nums[right] == nums[right - 1]:
                            right -= 1

                        left += 1
                        right -= 1
                    elif sum_ < target:
                        left += 1
                    else:
                        right -= 1

        return result
