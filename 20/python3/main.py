#!/usr/bin/env python3

class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        matching_bracket = {")": "(", "]": "[", "}": "{"}
        for c in s:
            if c in matching_bracket:
                # Mismatch or unmatched closing bracket
                if not stack or stack.pop() != matching_bracket[c]:
                    return False
            else:
                stack.append(c)

        # Valid if nothing remains
        return not stack

sol = Solution()
print(sol.isValid("()[]{}"))  # True
print(sol.isValid("([)]"))    # False
print(sol.isValid("{[]}"))    # True
