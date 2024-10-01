#!/usr/bin/env python3

class Solution:
    def __init__(self):
        # Initialize the stack and result as member variables
        self.stack = []
        self.result = []

    def generateParenthesis(self, n: int):
        self.backtrack(n, 0, 0)  # Start backtracking with open and closed counts at 0
        return self.result

    def backtrack(self, n, open_count, closed_count):
        # If we've added n open and n closed parentheses, we have a valid combination
        if open_count == n and closed_count == n:
            # Build the string by popping the elements in the stack in order
            self.result.append("".join(self.stack))  # Use the stack to form the string
            return

        # Add an open parenthesis if we haven't yet added n open ones
        if open_count < n:
            self.stack.append("(")
            self.backtrack(n, open_count + 1, closed_count)
            self.stack.pop()  # Backtrack by removing the last element added to the stack

        # Add a closing parenthesis if it can balance with the number of open ones
        if closed_count < open_count:
            self.stack.append(")")
            self.backtrack(n, open_count, closed_count + 1)
            self.stack.pop()  # Backtrack by removing the last element added to the stack

