#!/usr/bin/env python3

class Solution:
    def threeSum(self, nums):
        # Sort the input list
        nums.sort()
        result = []
        
        for i in range(len(nums)):
            # Skip duplicate elements to avoid duplicate triplets
            if i > 0 and nums[i] == nums[i - 1]:
                continue

            left, right = i + 1, len(nums) - 1
            while left < right:
                total = nums[i] + nums[left] + nums[right]
                
                if total == 0:
                    # Add the triplet to the result
                    result.append([nums[i], nums[left], nums[right]])

                    # Skip duplicates for both left and right pointers
                    while left < right and nums[left] == nums[left + 1]:
                        left += 1
                    while left < right and nums[right] == nums[right - 1]:
                        right -= 1

                    # Move both pointers inward
                    left += 1
                    right -= 1
                elif total < 0:
                    left += 1
                else:
                    right -= 1

        return result
