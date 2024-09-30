#!/usr/bin/env python3

class Solution:
    def convert(self, s: str, numRows: int) -> str:
        # Edge cases/single row
        if numRows <= 0:
            return ""
        elif numRows == 1:
            return s

        # Dictionary to act as the coordinate plane
        plane = {}
        current_pos = (1, 1)  # Starting position (x, y)
        outer_bounds = (1, 1)  # Track the bounds (max x, max y)
        diagonal = False  # Diagonal movement flag

        # Iterate through each character in the string
        for c in s:
            # Assign the character to the current position in the plane
            if current_pos[0] not in plane:
                plane[current_pos[0]] = {}
            plane[current_pos[0]][current_pos[1]] = c

            # Update the outer bounds
            outer_bounds = (max(outer_bounds[0], current_pos[0]), max(outer_bounds[1], current_pos[1]))

            # If not diagonal and not at the bottom row, move down
            if not diagonal and current_pos[1] < numRows:
                current_pos = (current_pos[0], current_pos[1] + 1)

            # At the bottom row, switch to diagonal movement
            elif not diagonal and current_pos[1] == numRows:
                diagonal = True
                current_pos = (current_pos[0] + 1, current_pos[1] - 1)

            # Keep moving diagonally up and right until we reach the top
            elif diagonal and current_pos[1] > 1:
                current_pos = (current_pos[0] + 1, current_pos[1] - 1)

            # At the top row, switch back to moving straight down
            elif diagonal and current_pos[1] == 1:
                diagonal = False
                current_pos = (current_pos[0], current_pos[1] + 1)

        # Convert the plane into a string
        result = []
        for y in range(1, outer_bounds[1] + 1):
            row_str = []
            for x in range(1, outer_bounds[0] + 1):
                if x in plane and y in plane[x]:
                    row_str.append(plane[x][y])
            result.append("".join(row_str))  # Join the row into a string

        # Join all the rows with newlines to form the final output string
        return "\n".join(result)


# Example usage
solution = Solution()
s = "PAYPALISHIRING"
numRows = 4
print(solution.convert(s, numRows))
