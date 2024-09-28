#!/usr/bin/env python3

class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        # Reverse and strip the string, return the length of the first str
        return len(s.strip()[::-1].split(" ")[0])

solution = Solution()
print(solution.lengthOfLastWord("Hello World"))
print(solution.lengthOfLastWord("   fly me   to   the moon  "))
print(solution.lengthOfLastWord("luffy is still joyboy"))
