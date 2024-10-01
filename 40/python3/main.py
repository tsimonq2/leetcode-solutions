#!/usr/bin/env python3

class Solution:
    def combinationSum2(self, candidates, target):
        # Sort candidates to handle duplicates and allow early termination
        candidates.sort()

        self.candidates = candidates
        self.target = target
        self.results = []

        # Start backtracking with an empty combination
        self.backtrack(0, [], 0)

        return self.results

    def backtrack(self, start, current, total):
        # Base case: if the current sum equals the target, add the combination to results
        if total == self.target:
            self.results.append(list(current))  # Append a copy of the valid combination
            return

        # Iterate through candidates starting from 'start' index to avoid duplicates
        for i in range(start, len(self.candidates)):
            # Skip duplicates at the same recursive depth level
            if i > start and self.candidates[i] == self.candidates[i - 1]:
                continue

            # If the sum exceeds the target, stop further exploration
            if total + self.candidates[i] > self.target:
                break

            # Include the current candidate
            current.append(self.candidates[i])

            # Recur with the next index (i + 1) to avoid reusing the same element
            self.backtrack(i + 1, current, total + self.candidates[i])

            # Backtrack by removing the last added element
            current.pop()
