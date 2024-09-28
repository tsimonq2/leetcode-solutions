#!/usr/bin/env python3

class Solution:
    def plusOne(self, digits: list[int]) -> list[int]:
        index = len(digits) - 1

        if (digits[index] < 9):
            digits[index] += 1
            return digits

        while (index >= 0 and digits[index] == 9):
            digits[index] = 0
            index -= 1
        if (index >= 0):
            digits[index] += 1
        else:
            digits.insert(0, 1);

        return digits


solution = Solution()

# Test Case 1: digits = [1, 2, 3]
digits1 = [1, 2, 3]
result1 = solution.plusOne(digits1)
print(f"Input: {digits1}, Output: {result1}")
# Expected Output: [1, 2, 4]

# Test Case 2: digits = [4, 3, 2, 1]
digits2 = [4, 3, 2, 1]
result2 = solution.plusOne(digits2)
print(f"Input: {digits2}, Output: {result2}")
# Expected Output: [4, 3, 2, 2]

# Test Case 3: digits = [9]
digits3 = [9]
result3 = solution.plusOne(digits3)
print(f"Input: {digits3}, Output: {result3}")
# Expected Output: [1, 0]

# Test Case 4: digits = [9, 9, 9]
digits4 = [9, 9, 9]
result4 = solution.plusOne(digits4)
print(f"Input: {digits4}, Output: {result4}")
# Expected Output: [1, 0, 0, 0]

# Test Case 5: digits = [0]
digits5 = [0]
result5 = solution.plusOne(digits5)
print(f"Input: {digits5}, Output: {result5}")
# Expected Output: [1]
