#!/usr/bin/env python3

class Solution:
    def intToRoman(self, num: int) -> str:
        roman_numerals = [
            ("M", 1000),
            ("CM", 900),
            ("D", 500),
            ("CD", 400),
            ("C", 100),
            ("XC", 90),
            ("L", 50),
            ("XL", 40),
            ("X", 10),
            ("IX", 9),
            ("V", 5),
            ("IV", 4),
            ("I", 1)
        ]

        result = ""

        for (key, val) in roman_numerals:
            while num >= val:
                result += key
                num -= val

        return result


solution = Solution()
print(solution.intToRoman(3749))
print(solution.intToRoman(58))
print(solution.intToRoman(1994))
