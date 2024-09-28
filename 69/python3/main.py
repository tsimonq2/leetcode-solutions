#!/usr/bin/env python3

import math

class Solution:
    def mySqrt(self, x: int) -> int:
        if (x == 0 or x == 1):
            return x

        i = x

        while True:
            y = (i + x / i) / 2

            if (y >= i):
                return int(math.floor(i))

            i = y


solution = Solution()
print(solution.mySqrt(4))
print(solution.mySqrt(8))
print(solution.mySqrt(145))
