#!/usr/bin/env python3

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        # Handle the empty string case
        if not s:
            return 0

        # Initialize variables
        result = 0         # Store the length of the longest substring
        left = 0           # Left boundary of the sliding window
        current_substr = "" # To store characters in the current window

        # Traverse the string
        for right in range(len(s)):
            # If the character is already in the current substring, move the left pointer
            if s[right] in current_substr:
                # Move the left pointer to right after the first occurrence of the duplicate
                left += current_substr.index(s[right]) + 1
                # Remove all characters up to the duplicate
                current_substr = s[left:right]

            # Add the current character to the substring
            current_substr += s[right]

            # Update the result with the maximum window size found so far
            result = max(result, len(current_substr))

        return result

# Example usage:
solution = Solution()

# Test Example 1
s1 = "abcabcbb"
print("Length of longest substring in 'abcabcbb':", solution.lengthOfLongestSubstring(s1))  # Output: 3

# Test Example 2
s2 = "bbbbb"
print("Length of longest substring in 'bbbbb':", solution.lengthOfLongestSubstring(s2))  # Output: 1

# Test Example 3
s3 = "pwwkew"
print("Length of longest substring in 'pwwkew':", solution.lengthOfLongestSubstring(s3))  # Output: 3
