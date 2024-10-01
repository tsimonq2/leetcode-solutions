#!/usr/bin/env python3

class Solution:
    def combinationSum(self, candidates, target):
        # Initialize the member variables and trigger backtracking
        self.candidates = candidates  # Store candidates in the class
        self.target = target  # Store target in the class
        self.results = []  # To store the results

        # Start backtracking with an empty combination
        self.backtrack(0, [], 0)  # Start at index 0 and current sum of 0

        return self.results  # Return the results after backtracking is complete

    def backtrack(self, index, current, total):
        # Base case: if the current sum equals the target, add the combination to results
        if total == self.target:
            self.results.append(list(current))  # Append a copy of the valid combination
            return

        # If the current sum exceeds the target, stop exploring further
        if total > self.target:
            return

        # Iterate over the remaining candidates starting from 'index'
        for i in range(index, len(self.candidates)):
            # Choose the current candidate
            current.append(self.candidates[i])

            # Recur with the current candidate included, allowing repeats
            self.backtrack(i, current, total + self.candidates[i])

            # Backtrack by removing the current candidate
            current.pop()
