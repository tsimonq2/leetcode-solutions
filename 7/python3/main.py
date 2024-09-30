#!/usr/bin/env python3

class Solution:
    def reverse(self, x: int) -> int:
        # 32-bit signed integer limits
        INT_MIN = -2**31
        INT_MAX = 2**31 - 1

        new_value = 0
        negative = False

        # If x is negative, convert it to positive then revert it back later
        if x < 0:
            x = -x
            negative = True

        while x > 0:
            # Check for overflow before multiplying by 10
            if new_value > (INT_MAX // 10) or (new_value == INT_MAX // 10 and x % 10 > INT_MAX % 10):
                return 0  # Return 0 if the reverse exceeds 32-bit bounds
            new_value = (new_value * 10) + (x % 10)
            x //= 10

        if negative:
            new_value = -new_value

        # Check if reversed number is outside 32-bit signed integer bounds
        if new_value < INT_MIN or new_value > INT_MAX:
            return 0

        return new_value
