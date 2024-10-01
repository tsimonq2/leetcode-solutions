#!/usr/bin/env python3

from collections import Counter

class Solution:
    def findSubstring(self, s: str, words: list[str]) -> list[int]:
        # Return nothing if words or s is empty
        if not s or not words:
            return []

        chunk_size = len(words[0])
        substring_size = len(words) * chunk_size

        # If the length of any candidate substring exceeds the total length, return
        if substring_size > len(s):
            return []

        # Check if all words and the string are made of the same repeated character
        if len(set(s)) == 1 and all(w == words[0] for w in words):
            first_char = words[0][0]
            # If the character in words is not the same as in s, return []
            if first_char != s[0]:
                return []
            result = []
            for i in range(len(s) - substring_size + 1):
                if s[i:i + substring_size] == first_char * substring_size:
                    result.append(i)
            return result

        # Frequency map of the words
        word_count = Counter(words)

        result = []
        
        # Sliding window over the string `s`
        for i in range(len(s) - substring_size + 1):
            seen = Counter()
            j = 0

            # Check each word in the current window
            while j < len(words):
                current_word = s[i + j * chunk_size:i + (j + 1) * chunk_size]

                if current_word not in word_count:
                    break

                seen[current_word] += 1

                # If the word appears more times than it does in words, break
                if seen[current_word] > word_count[current_word]:
                    break

                j += 1

            # If all words matched, add the starting index to result
            if j == len(words):
                result.append(i)

        return result
