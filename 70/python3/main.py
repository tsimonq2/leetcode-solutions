#!/usr/bin/env python3

from math import sqrt

class Solution:
    def climbStairs(self, n: int) -> int:
        sqrt5 = sqrt(5)

        i = n + 1
        # Calculate the golden ratio (phi) and its conjugate (psi)
        phi = (1 + sqrt5) / 2;
        psi = (1 - sqrt5) / 2;

        # Compute the difference between phi^i and psi^i
        result_double = ((phi**i) - (psi**i)) / sqrt5;

        # Round the result to the nearest integer using 0.5 for rounding
        # Adding 0.5 ensures proper rounding instead of truncation
        return int(result_double + 0.5)

solution = Solution()
print(solution.climbStairs(2))
print(solution.climbStairs(3))
print(solution.climbStairs(5))
