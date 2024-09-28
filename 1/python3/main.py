#!/usr/bin/env python3

# See the C++ comments for more verbose details, this is a reimplementation
class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        number_dict = dict()

        index = 0
        for number in nums:
            compliment = target - number
            if compliment in number_dict.keys():
                return [number_dict[compliment], index]
            else:
                number_dict[number] = index

            index += 1

        return None


solution = Solution()
print(solution.twoSum([2,7,11,15], 9))
print(solution.twoSum([3,2,4], 6))
print(solution.twoSum([3,3], 6))
