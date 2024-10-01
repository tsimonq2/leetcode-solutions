#!/usr/bin/env python3

class Solution:
    def letterCombinations(self, digits: str):
        digit_letters = {
            '2': "abc",  # 2 -> a, b, c
            '3': "def",  # 3 -> d, e, f
            '4': "ghi",  # 4 -> g, h, i
            '5': "jkl",  # 5 -> j, k, l
            '6': "mno",  # 6 -> m, n, o
            '7': "pqrs", # 7 -> p, q, r, s
            '8': "tuv",  # 8 -> t, u, v
            '9': "wxyz"  # 9 -> w, x, y, z
        }

        if not digits:
            return []

        results = [""]  # Start with an empty string to build combinations

        for digit in digits:
            letters = digit_letters[digit]  # Get corresponding letters for the current digit
            temp = []

            # Combine existing combinations with the current digit's letters
            for combination in results:
                for letter in letters:
                    temp.append(combination + letter)  # Append new letter to each combination

            results = temp  # Update results with new combinations

        return results

solution = Solution()
print(solution.letterCombinations("23"))

