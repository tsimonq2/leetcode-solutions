#!/usr/bin/env python3

class Solution:
    def longestPalindrome(self, s: str) -> str:
        # Edge case: If the string is empty, return an empty string
        if not s:
            return ""

        # Variables to track the start index and the maximum length of the palindrome
        start = 0
        max_len = 1

        # Loop over each character in the string as a possible center
        for i in range(len(s)):
            # Check for odd-length palindrome centered at s[i]
            left, right = i, i
            # Expand while characters on both sides are equal and within bounds
            while left >= 0 and right < len(s) and s[left] == s[right]:
                # Update the maximum length and starting index if we find a longer palindrome
                if right - left + 1 > max_len:
                    start = left
                    max_len = right - left + 1
                # Move pointers outward to check for a larger palindrome
                left -= 1
                right += 1

            # Check for even-length palindrome centered between s[i] and s[i+1]
            left, right = i, i + 1
            # Expand while characters on both sides are equal and within bounds
            while left >= 0 and right < len(s) and s[left] == s[right]:
                # Update the maximum length and starting index if we find a longer palindrome
                if right - left + 1 > max_len:
                    start = left
                    max_len = right - left + 1
                # Move pointers outward to check for a larger palindrome
                left -= 1
                right += 1

        # Return the longest palindrome substring by extracting the relevant portion of the string
        return s[start:start + max_len]


solution = Solution()

s1 = "babad"
print(f"Longest Palindrome in '{s1}':", solution.longestPalindrome(s1))

s2 = "cbbd"
print(f"Longest Palindrome in '{s2}':", solution.longestPalindrome(s2))
