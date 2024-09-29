#!/usr/bin/env python3

class Solution:
    def generate(self, numRows: int):
        pascals_triangle = []

        # Handle edge case for numRows <= 0
        if numRows <= 0:
            return pascals_triangle

        # First row is always [1]
        pascals_triangle.append([1])

        # Generate Pascal's Triangle row by row
        for i in range(1, numRows):
            this_row = [1] * (i + 1)  # Start with 1s on both ends

            # Fill in the middle elements
            for j in range(1, i):
                this_row[j] = pascals_triangle[i-1][j-1] + pascals_triangle[i-1][j]

            pascals_triangle.append(this_row)

        return pascals_triangle


# Helper function to print Pascal's Triangle
def print_pascals_triangle(triangle):
    for row in triangle:
        print(" ".join(map(str, row)))


solution = Solution()

# Test case 1: numRows = 5
print("Pascal's Triangle for numRows = 5:")
result1 = solution.generate(5)
print_pascals_triangle(result1)

# Test case 2: numRows = 7
print("\nPascal's Triangle for numRows = 7:")
result2 = solution.generate(7)
print_pascals_triangle(result2)
