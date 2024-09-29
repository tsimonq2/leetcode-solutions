#!/usr/bin/env python3

class Solution:
    def getRow(self, rowIndex: int):
        row = [1]  # The first element of each row is always 1

        # Use the binomial coefficient to generate the row
        for j in range(1, rowIndex + 1):
            # Calculate next element using the previous one
            # row[j] = row[j-1] * (rowIndex - j + 1) / j
            row.append(row[-1] * (rowIndex - j + 1) // j)

        return row


# Helper function to print a row of Pascal's Triangle
def print_row(row):
    print(" ".join(map(str, row)))


solution = Solution()

# Test case 1: Get the 3rd row (0-indexed)
print("Row 3 of Pascal's Triangle:")
result1 = solution.getRow(3)  # This will output the row at index 3, which is [1, 3, 3, 1]
print_row(result1)
