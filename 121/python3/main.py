#!/usr/bin/env python3

class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        max_profit, min_price = 0, prices[0]

        for current_price in prices:
            max_profit = max(max_profit, current_price - min_price)
            min_price = min(min_price, current_price)

        return max_profit

solution = Solution()

print(solution.maxProfit([7,1,5,3,6,4]))
print(solution.maxProfit([7,6,4,3,1]))
