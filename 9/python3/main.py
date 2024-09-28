#!/usr/bin/env python3

class Solution:
    def isPalindrome(self, x: int) -> bool:
        # Store the original value for comparison later
        original = x

        # Negative numbers always return False
        if x < 0:
            return False

        # Calculates number of digits in a given int
        reversed_number = 0
        while x > 0:
            # Multiplying by 10 shifts the existing digits to the left by one
            # Add the last digit of x to that
            reversed_number = (reversed_number * 10) + (x % 10)
            # Remove the last digit of x and shift all elements to the right by one
            x = int(x // 10)

        return reversed_number == original


solution = Solution()
print(solution.isPalindrome(121))
print(solution.isPalindrome(-121))
print(solution.isPalindrome(10))
