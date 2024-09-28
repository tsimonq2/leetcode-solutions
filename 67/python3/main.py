#!/usr/bin/env python3

class Solution:
    def addBinary(self, a: str, b: str) -> str:
        # Initialize the result and carry
        result = []
        carry = 0

        # Pointers for both strings (starting from the end)
        i, j = len(a) - 1, len(b) - 1

        # Iterate as long as there are digits left in either string or carry remains
        while i >= 0 or j >= 0 or carry:
            # Convert the current digit from string to integer, if index is valid
            digit_a = int(a[i]) if i >= 0 else 0
            digit_b = int(b[j]) if j >= 0 else 0

            # Binary addition for current digit and carry
            total = digit_a + digit_b + carry

            # Append the current bit (0 or 1) to the result list
            result.append(str(total % 2))

            # Update carry (it will be 1 if total is 2 or 3)
            carry = total // 2

            # Move to the next digits
            i -= 1
            j -= 1

        # Reverse the result list to get the correct binary string and join it
        return ''.join(reversed(result))

solution = Solution()

# Test case 1: a = "11", b = "1"
result1 = solution.addBinary("11", "1")
print(result1)  # Output: "100"

# Test case 2: a = "1010", b = "1011"
result2 = solution.addBinary("1010", "1011")
print(result2)  # Output: "10101"

# Additional test cases
result3 = solution.addBinary("110", "11")
print(result3)  # Output: "1001"

result4 = solution.addBinary("1111", "1111")
print(result4)  # Output: "11110"

result5 = solution.addBinary("0", "101")
print(result5)  # Output: "101"
