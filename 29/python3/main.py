#!/usr/bin/env python3

class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        # Handle the edge case for overflow (INT_MIN / -1)
        if dividend == -2**31 and divisor == -1:
            return 2**31 - 1
        
        # Determine the sign of the result
        sign = 1 if (dividend > 0) == (divisor > 0) else -1
        
        # Convert both to positive using abs()
        abs_dividend = abs(dividend)
        abs_divisor = abs(divisor)
        
        result = 0
        
        # Efficient division using bitwise shifting
        while abs_dividend >= abs_divisor:
            temp = abs_divisor
            multiple = 1
            
            # Double the divisor using bitwise shifts as much as possible
            while abs_dividend >= (temp << 1):
                temp <<= 1
                multiple <<= 1
            
            # Subtract the largest multiple of divisor from dividend
            abs_dividend -= temp
            result += multiple
        
        # Apply the sign and ensure the result is within 32-bit integer range
        result = sign * result
        return min(max(-2**31, result), 2**31 - 1)
