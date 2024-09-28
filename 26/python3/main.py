#!/usr/bin/env python3

class Solution:
    def removeDuplicates(self, nums: list[int]) -> int:
        if not nums:
            return 0

        # n points to the last unique element
        n = 0

        # j is the traversing pointer
        for j in range(1, len(nums)):
            # The current element is unique
            if nums[j] != nums[n]:
                n += 1
                nums[n] = nums[j]

        return n + 1


solution = Solution()
print(solution.removeDuplicates([1,1,2]))
print(solution.removeDuplicates([0,0,1,1,1,2,2,3,3,4]))
