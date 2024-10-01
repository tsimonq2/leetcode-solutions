#!/usr/bin/env python3

class Solution:
    def longestValidParentheses(self, s: str) -> int:
        stack = []
        max_length = 0
        last_invalid = -1  # Tracks the index of the last invalid closing parenthesis

        for i, char in enumerate(s):
            if char == '(':
                # Push the index of every '(' onto the stack
                stack.append(i)
            else:
                # For each ')', pop if there's a matching '('
                if stack:
                    stack.pop()  # Pop the last '('
                    if stack:
                        # If stack is not empty, calculate the valid substring length
                        max_length = max(max_length, i - stack[-1])
                    else:
                        # If stack is empty, calculate from the last invalid position
                        max_length = max(max_length, i - last_invalid)
                else:
                    # If stack is empty, update the last invalid index
                    last_invalid = i

        return max_length
