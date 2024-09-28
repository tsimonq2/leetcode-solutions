#!/usr/bin/env python3

class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if needle == 0:
            return 0

        haystack_size = len(haystack)
        needle_size = len(needle)

        for start_index in range(0, (haystack_size - needle_size + 1)):
            if haystack[start_index:start_index + needle_size] == needle:
                return start_index

        return -1


solution = Solution()
print(solution.strStr("sadbutsad", "sad"))
print(solution.strStr("leetcode", "leeto"))
print(solution.strStr("a", "a"))
