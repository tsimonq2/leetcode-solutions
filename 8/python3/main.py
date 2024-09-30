#!/usr/bin/env python3

class Solution:
    def myAtoi(self, s: str) -> int:
        # Initialize variables
        sign = 1
        result = 0
        i = 0
        n = len(s)
        INT_MAX = 2**31 - 1
        INT_MIN = -2**31

        # Skip leading whitespace
        while i < n and s[i] == ' ':
            i += 1

        # Handle sign if present
        if i < n and s[i] == '-':
            sign = -1
            i += 1
        elif i < n and s[i] == '+':
            i += 1

        # Process the number
        while i < n and s[i].isdigit():
            result = result * 10 + int(s[i])
            
            # Check for overflow/underflow
            if result * sign > INT_MAX:
                return INT_MAX
            if result * sign < INT_MIN:
                return INT_MIN
            
            i += 1

        # Return result with sign
        return result * sign
