#!/usr/bin/env python3

class Solution:
    def countAndSay(self, n: int) -> str:
        # Start with the first sequence
        result = "1"

        # Build the sequence up to the nth term
        for _ in range(2, n + 1):
            current = []  # Use a list to build the current sequence

            # Iterate through the previous sequence to count and describe
            i = 0
            while i < len(result):
                count = 1

                # Count the number of consecutive identical digits
                while i + 1 < len(result) and result[i] == result[i + 1]:
                    count += 1
                    i += 1

                # Append the count and the digit to the current sequence
                current.append(str(count))
                current.append(result[i])

                i += 1

            # Update result to the current sequence for the next iteration
            result = ''.join(current)

        return result
