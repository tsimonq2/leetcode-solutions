#!/usr/bin/env python3

class Solution:
    def firstMissingPositive(self, nums):
        # Convert the list to a set for fast lookups
        num_set = set(nums)
        
        missing_positive = 1  # Start with 1 as the smallest positive integer

        # Increment missing_positive until we find a missing number
        while missing_positive in num_set:
            missing_positive += 1

        return missing_positive
