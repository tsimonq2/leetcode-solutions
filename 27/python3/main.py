#!/usr/bin/env python3

class Solution:
    def removeElement(self, nums: list[int], val: int) -> int:
        # n points to the last unique element
        n = 0

        # j is the traversing pointer
        for j in range(0, len(nums)):
            # The current element does not match
            if nums[j] != val:
                nums[n] = nums[j]
                n += 1

        return n


solution = Solution()
print(solution.removeElement([3,2,2,3], 2))
print(solution.removeElement([0,1,2,2,3,0,4,2], 2))
