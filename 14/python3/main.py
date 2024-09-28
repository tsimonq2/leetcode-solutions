#!/usr/bin/env python3

class Solution:
    def longestCommonPrefix(self, strs: list[str]) -> str:
        common_prefix = ""

        for char in strs[0]:
            original_common_prefix = common_prefix
            common_prefix += char
            for string in strs:
                if not string.startswith(common_prefix):
                    return original_common_prefix

        return common_prefix

solution = Solution()
print(solution.longestCommonPrefix(["flower","flow","flight"]))
print(solution.longestCommonPrefix(["dog","racecar","car"]))
