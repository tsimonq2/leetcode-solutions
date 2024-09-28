#!/usr/bin/env python3

class Solution:
    def romanToInt(self, s: str) -> int:
        roman_numerals = {
            "I": 1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M": 1000
        }

        total = 0
        n = len(s)

        for i in range(n):
            current_value = roman_numerals[s[i]]
            next_value = roman_numerals[s[i + 1]] if i < n - 1 else 0

            if current_value < next_value:
                total -= current_value
            else:
                total += current_value

        return total


solution = Solution()
print(solution.romanToInt("III"))
print(solution.romanToInt("LVIII"))
print(solution.romanToInt("MCMXCIV"))
